#include "Gate.h"

Gate::Gate(GateType t, int d, Wire* o, Wire* i1, Wire* i2 = nullptr)
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
	switch (this->type) 
	{
	}
	return WireValue();
}
