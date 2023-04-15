#include "Circuit.h"

using namespace std;

Circuit::Circuit(string name)
{
	this->name = name;
}

string Circuit::getCircuitName()
{
	return this->name;
}

Queue Circuit::getCircuitEvents()
{
	return this->events;
}

Wire* Circuit::getWire(size_t n)
{
	if (this->wires.size() > n)
	{
		return this->wires.at(n);
	}
	return nullptr;
}

void Circuit::setCircuitName(string newName)
{
	this->name = newName;
}

void Circuit::setCircuitEvents(Queue newEvent)
{
	this->events = newEvent;
}

void Circuit::setWire(size_t n, Wire* inWire)
{
	if (this->wires.size() <= n)
	{
		this->wires.resize(n + 1);
	}
	this->wires[n] = inWire;
}
