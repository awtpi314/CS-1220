#include <iostream>
#include <fstream>
#include <sstream>

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
		istringstream iss(currentLine);
		string type;
		iss >> type;
		if (type == "INPUT" || type == "OUTPUT")
		{
			string name;
			iss >> name;
			int id;
			iss >> id;

			mainCircuit->setWire(id, new Wire(id, name));
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
		istringstream iss(currentLine);
		string wireName;
		iss >> wireName;
		iss >> wireName;

		int time;
		iss >> time;
		int value;
		iss >> value;

		Event e = Event(time, (WireValue)value, mainCircuit->getWire(wireName));
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
		cout << "Enter the path to the vector file: ";
		cin >> vectorFileName;
	}
	else
	{
		cerr << "THE MEGA AWESOME CIRCUIT SIMULATOR" << endl <<
			"(c) 2023 Alexander Taylor and Elijah Payton" << endl << endl <<
			"Usage: MACS.exe <circuit_file_name> <vector_file_name>" << endl << endl <<
			"ERROR: Incorrect number of parameters" << endl;
		exit(1);
	}

	ifstream circuitFile(circuitFileName);
	
	Circuit* mainCircuit = new Circuit();
	readInCircuit(mainCircuit, circuitFile);

	circuitFile.close();


	ifstream vectorFile(vectorFileName);

	readInVector(mainCircuit, vectorFile);

	while (mainCircuit->hasEvent()) 
	{
		Event e = mainCircuit->getNextEvent();
		if (e.getTime() > 100) break;
		e.print();
		Wire* wireToChange = e.getWire();
		wireToChange->setValue((WireValue)e.getValue(), e.getTime());
		vector<Gate*> gates = wireToChange->getDrives();
		for (auto g : gates) 
		{
			WireValue previous = g->getOutput()->getValue();
			WireValue next = g->evaluate();
			if (previous != next)
			{
				Event newEvent = Event(e.getTime() + g->getDelay(), next, g->getOutput());
				mainCircuit->addEvent(newEvent);
			}
		}
	}

	mainCircuit->printWires();

	vectorFile.close();
}