#pragma once

#ifndef GATE_H
#define GATE_H

#include <vector>

#include "Wire.h"

using namespace std;

enum GateType {
	AND,
	OR,
	NOT,
	XOR,
	NAND,
	NOR,
	XNOR
};

class Gate
{
public:
	Gate(GateType t, int d, Wire* o, Wire* i1, Wire* i2 = nullptr);
	~Gate();

	int getDelay() const;
	Wire* getInput(int i) const;
	Wire* getOutput() const;
	WireValue evaluate() const;


private:
	GateType type;
	Wire* input1;
	Wire* input2;
	Wire* output;
	int gateDelay;

	WireValue evaluate(GateType g) const;
};

#endif // !GATE_H
