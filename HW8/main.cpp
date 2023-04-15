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

void readInCircuit(ifstream& f) {
	string currentLine;
	getline(f, currentLine);
	string circuitName = currentLine.substr(currentLine.find(" ") + 1);

	Circuit* mainCircuit = new Circuit(circuitName);

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
		}
	}
}

int main(int argc, char* argv[])
{
	ifstream inFS;
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


	inFS.open(circuitFileName);
	if (inFS.is_open()) {
		cerr << "haha looser u didn t work right" << endl;
		exit(1);
	}


	// perform operations

	inFS.close();

	inFS.open(vectorFileName);
	if (inFS.is_open()) {
		cerr << "haha looser thother one didn t work right bro" << endl;
		exit(1);
	}

	// perform even more magnanimous operations

	inFS.close();
}