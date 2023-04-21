#include <sstream>

#include "Circuit.h"

using namespace std;

Circuit::Circuit(string name)
{
	this->name = name;
}

Circuit::~Circuit()
{
	for (auto g : this->gates) {
		delete g;
	}

	for (auto w : this->wires) {
		delete w;
	}
}

string Circuit::getCircuitName() const
{
	return this->name;
}

Event Circuit::getNextEvent()
{
	/*Event e = this->events.back();
	this->events.pop_back();
	return e;*/
	Event retVal = this->events.top();
	this->events.pop();
	return retVal;
}

Wire* Circuit::getWire(size_t n) const
{
	if (this->wires.size() > n)
	{
		return this->wires.at(n);
	}
	return nullptr;
}

Wire* Circuit::getWire(string s) const
{
	for (auto w : this->wires)
	{
		if (w == nullptr) continue;
		if (w->getName() == s)
		{
			return w;
		}
	}
}

Gate* Circuit::getGate(size_t n) const
{
	return this->gates.at(n);
}

int Circuit::getEventCount()
{
	return this->eventCount++;
}

void Circuit::setCircuitName(string newName)
{
	this->name = newName;
}

void Circuit::addEvent(Event& newEvent)
{
	this->events.push(newEvent);
}

void Circuit::setWire(size_t n, Wire* inWire)
{
	if (this->wires.size() <= n)
	{
		this->wires.resize(n + 1);
	}
	this->wires[n] = inWire;
}

void Circuit::addGate(Gate* g)
{
	this->gates.push_back(g);
}

void Circuit::printWires() const
{
	cout << this->getWireDesc();
}

string Circuit::getWireDesc() const
{
	stringstream ss;

	size_t maxSize = this->getMaxWireSize();

	for (auto w : this->wires)
	{
		if (w == nullptr || w->getName() == "") continue;
		ss << w->getHistoryPretty(maxSize);
	}

	return ss.str();
}

size_t Circuit::getMaxWireSize() const
{
	size_t maxSize = 0;
	for (auto w : this->wires)
	{
		if (w == nullptr) continue;
		if (w->getHistory().size() > maxSize)
		{
			maxSize = w->getHistory().size();
		}
	}
	return maxSize;
}
