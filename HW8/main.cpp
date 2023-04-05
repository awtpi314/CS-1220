#include <iostream>

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

int main(int argc, char* argv[])
{
	/*Wire* w1 = new Wire(1, "A", UNKNOWN);
	Wire* w2 = new Wire(2, "B", UNKNOWN);
	Wire* w3 = new Wire(3, "C");

	for (int g = 0; g < 7; g++){
		string gName;
		switch(g){
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
		for (int i1 = 0; i1 < 3; i1 ++){
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
	}*/

	Wire* w4 = new Wire(4, "D");
	w4->setValue(OFF, 5);
	w4->setValue(ON, 10);
	w4->printHistory();
}