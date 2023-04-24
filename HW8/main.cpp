#include <iostream>
#include <fstream>
#include <sstream>

#include <Windows.h>

#include "Circuit.h"
#include "Gate.h"
#include "Wire.h"

using namespace std;

string fmtOut(WireValue w) {
	switch (w) {
	case ON:
		return "ON";
	case OFF:
		return "OFF";
	default:
		return "UNKNOWN";
	}
}

void testGateStates(Wire* w1, Wire* w2, Wire* w3) {
	for (int g = 0; g < 7; g++) {
		string gName;
		switch (g) {
		case 0:
			gName = "AND";
			break;
		case 1:
			gName = "OR";
			break;
		case 2:
			gName = "NOT";
			break;
		case 3:
			gName = "XOR";
			break;
		case 4:
			gName = "NAND";
			break;
		case 5:
			gName = "NOR";
			break;
		case 6:
			gName = "XNOR";
			break;
		default:
			break;
		}
		cout << "Testing " << gName << " gate: " << endl;
		for (int i1 = 0; i1 < 3; i1++) {
			w1->setValue((WireValue)i1);
			for (int i2 = 0; i2 < 3; i2++) {
				w2->setValue((WireValue)i2);
				cout << "(" << fmtOut((WireValue)i1) << ", " << fmtOut((WireValue)i2) << ")";
				Gate* iLikeYoCutG = new Gate((GateType)g, 3, w3, w1, w2);
				cout << " -> " << fmtOut(iLikeYoCutG->evaluate()) << endl;
			}
		}
		cout << endl;
		cout.flush();
	}
}

Circuit* readInCircuit(Circuit* mainCircuit, ifstream& f) {
	string currentLine;
	getline(f, currentLine);
	string circuitName = currentLine.substr(currentLine.find(" ") + 1);

	mainCircuit->setCircuitName(circuitName);

	while (getline(f, currentLine))
	{
		if (currentLine.length() == 0) break;
		istringstream iss(currentLine);
		string type;
		iss >> type;
		if (type == "INPUT" || type == "OUTPUT")
		{
			string name;
			iss >> name;
			int id;
			iss >> id;

			mainCircuit->setWire(id, new Wire(id, name, type));
		}
		else if (type == "NOT")
		{
			string delay;
			iss >> delay;
			int inputWire;
			iss >> inputWire;
			int outputWire;
			iss >> outputWire;

			if (mainCircuit->getWire(outputWire) == nullptr)
			{
				mainCircuit->setWire(outputWire, new Wire(outputWire));
			}

			Gate* newGate = new Gate(STR_TO_GATE(type), stoi(delay), mainCircuit->getWire(outputWire), mainCircuit->getWire(inputWire));
			mainCircuit->addGate(newGate);
			mainCircuit->getWire(inputWire)->addGate(newGate);
		}
		else
		{
			string delay;
			iss >> delay;
			int inputWire1;
			iss >> inputWire1;
			int inputWire2;
			iss >> inputWire2;
			int outputWire;
			iss >> outputWire;

			if (mainCircuit->getWire(outputWire) == nullptr)
			{
				mainCircuit->setWire(outputWire, new Wire(outputWire));
			}

			Gate* newGate = new Gate(STR_TO_GATE(type), stoi(delay), mainCircuit->getWire(outputWire), mainCircuit->getWire(inputWire1), mainCircuit->getWire(inputWire2));
			mainCircuit->addGate(newGate);
			mainCircuit->getWire(inputWire1)->addGate(newGate);
			mainCircuit->getWire(inputWire2)->addGate(newGate);
		}
	}

	return mainCircuit;
}

Circuit* readInVector(Circuit* mainCircuit, ifstream& inFS)
{
	string currentLine;
	getline(inFS, currentLine);

	while (getline(inFS, currentLine))
	{
		if (currentLine.length() == 0) break;
		istringstream iss(currentLine);
		string wireName;
		iss >> wireName;
		iss >> wireName;

		int time;
		iss >> time;
		string stringValue;
		iss >> stringValue;

		WireValue value;
		if (stringValue == "X")
		{
			value = UNKNOWN;
		}
		else
		{
			value = (WireValue)std::stoi(stringValue);
		}

		Event e = Event(time, value, mainCircuit->getWire(wireName), mainCircuit->getEventCount());
		mainCircuit->addEvent(e);
	}

	return mainCircuit;
}

int main(int argc, char* argv[])
{
	string circuitFileName;
	string vectorFileName;

	if (argc == 3)
	{
		circuitFileName = string(argv[1]);
		vectorFileName = string(argv[2]);
	}
	else if (argc == 1)
	{
		cout << "Enter the path to the circuit file: ";
		cin >> circuitFileName;
		vectorFileName = circuitFileName + "_v.txt";
		circuitFileName += ".txt";
	}
	else
	{
		cerr << "THE MEGA AWESOME CIRCUIT SIMULATOR" << endl <<
			"(c) 2023 Alexander Taylor and Elijah Payton" << endl << endl <<
			"Usage: MACS.exe <circuit_file_name> <vector_file_name>" << endl << endl <<
			"ERROR: Incorrect number of parameters" << endl;
		exit(1);
	}

	while (circuitFileName != ".txt")
	{
		ifstream circuitFile(circuitFileName);

		Circuit* mainCircuit = new Circuit();
		readInCircuit(mainCircuit, circuitFile);

		circuitFile.close();


		ifstream vectorFile(vectorFileName);

		readInVector(mainCircuit, vectorFile);

		vectorFile.close();

		COORD coord;
		coord.X = 0;
		coord.Y = 4;

		COORD coord2;
		coord2.X = 0;
		coord2.Y = 10;

		while (mainCircuit->hasEvent())
		{
			system("CLS");
			Event e = mainCircuit->getNextEvent();
			if (e.getTime() > 60) break;
			Wire* wireToChange = e.getWire();
			vector<Gate*> gates = wireToChange->getDrives();
			for (auto g : gates)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
				mainCircuit->printWires();
				WireValue previous = g->evaluate();
				WireValue next = g->speculate(e);

				wireToChange->setValue((WireValue)e.getValue(), e.getTime());

				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord2);
				e.print();
				cout << " -> ";

				if (previous != next)
				{
					Event newEvent = Event(e.getTime() + g->getDelay(), next, g->getOutput(), mainCircuit->getEventCount());
					mainCircuit->addEvent(newEvent);
					newEvent.print();
				}

				cout << endl;
			}
		}

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		mainCircuit->printWires();

		system("PAUSE");
		system("CLS");
		COORD origin;
		origin.X = 0;
		origin.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), origin);

		cout << "Enter the path to the circuit file: ";
		cin >> circuitFileName;
		vectorFileName = circuitFileName + "_v.txt";
		circuitFileName += ".txt";
	}
}