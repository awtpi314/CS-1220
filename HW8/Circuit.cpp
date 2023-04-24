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
	Event retVal = this->events.top();
	this->eventHistory.push_back(retVal);
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
	this->wires[n]->setValue(UNKNOWN);
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

string Circuit::getQueue() const
{
	priority_queue<Event> npq(this->events);
	stringstream ss("");
	while (!npq.empty())
	{
		ss << npq.top().getPretty() << endl;
		npq.pop();
	}
	return ss.str();
}

string Circuit::getEventHistory()
{
	stringstream ss;
	for (auto e : this->eventHistory)
	{
		ss << e.getPretty() << endl;
	}
	return ss.str();
}

void Circuit::resetCircuit()
{
	this->name = "";
	this->events = priority_queue<Event>();
	this->wires.clear();
	this->gates.clear();
	this->eventHistory.clear();
	this->eventCount = 0;
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
