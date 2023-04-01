#include "Gate.h"

Gate::Gate(GateType t, int d, Wire* o, Wire* i1, Wire* i2)
{
	this->type = t;
	this->gateDelay = d;
	this->output = o;
	this->input1 = i1;
	this->input2 = i2;
}

Gate::~Gate()
{
	delete this->output;
	delete this->input1;
	delete this->input2;
}

int Gate::getDelay() const
{
	return this->gateDelay;
}

Wire* Gate::getInput(int i) const
{
	if (i == 1) 
	{
		return this->input1;
	}
	else 
	{
		return this->input2;
	}
}

Wire* Gate::getOutput() const
{
	return this->output;
}

WireValue Gate::evaluate() const
{
	if (this->input1 == nullptr) 
	{
		return UNKNOWN;
	}
	return this->evaluate(this->type);
}

WireValue Gate::evaluate(GateType g) const {
	WireValue input1Value = this->input1->getValue();

	switch (g)
	{
	case NOT:
		if (input1Value == UNKNOWN)
		{
			return UNKNOWN;
		}
		return input1Value == OFF ? ON : OFF;
	case AND:
	{
		WireValue input2Value = this->input2->getValue();
		if ((input1Value == UNKNOWN && input2Value == ON) ||
			(input1Value == ON && input2Value == UNKNOWN)) {
			return UNKNOWN;
		}
		return (WireValue)(input1Value & input2Value);
	}
	case NAND:
	{
		WireValue eval = evaluate(AND);
		if (eval == UNKNOWN) {
			return UNKNOWN;
		}
		return (WireValue)(!eval);
	}
	case OR:
	{
		WireValue input2Value = this->input2->getValue();
		if ((input1Value == UNKNOWN && input2Value == OFF) ||
			(input1Value == OFF && input2Value == UNKNOWN) ||
			(input1Value == UNKNOWN && input2Value == UNKNOWN)) {
			return UNKNOWN;
		}
		return (WireValue)((input1Value | input2Value) & 0b1);
	}
	case XOR:
	{
		WireValue input2Value = this->input2->getValue();
		if (input1Value == UNKNOWN || input2Value == UNKNOWN) {
			return UNKNOWN;
		}
		return (WireValue)((input1Value ^ input2Value) & 0b1);
	}
	case NOR:
	{
		WireValue eval = evaluate(OR);
		if (eval == UNKNOWN) {
			return UNKNOWN;
		}
		return (WireValue)(!eval);
	}
	case XNOR:
	{
		WireValue eval = evaluate(XOR);
		if (eval == UNKNOWN) {
			return UNKNOWN;
		}
		return (WireValue)(!eval);
	}

	default:
		break;
	}
}
