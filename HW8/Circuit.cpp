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
	Event e = this->events.back();
	this->events.pop_back();
	return e;
	/*Event retVal = this->events.top();
	this->events.pop();
	return retVal;*/
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
	return this->eventCount;
}

void Circuit::setCircuitName(string newName)
{
	this->name = newName;
}

bool Circuit::addEvent(Event& newEvent, bool justAdd)
{
	if (!justAdd)
	{
		int location;
		WireValue lastKnownValue = newEvent.getWire()->getValue();
		for (location = this->events.size() - 1; location >= 0 && this->events.at(location).getTime() <= newEvent.getTime(); location--)
		{
			if (this->events.at(location).getWire()->getIndex() == newEvent.getWire()->getIndex())
			{
				lastKnownValue = this->events.at(location).getValue();
				continue;
			}
			if (this->events.at(location) == newEvent ||
				(this->events.at(location).getTime() == newEvent.getTime() - 1 &&
					this->events.at(location).getValue() == newEvent.getValue() &&
					this->events.at(location).getWire()->getIndex() == newEvent.getWire()->getIndex()))
			{
				break;
			}
		}

		if (lastKnownValue == newEvent.getValue()) return false;
		if (location >= 0 && this->events.at(location).getTime() < newEvent.getTime())
		{
			auto firstEvent = 0;
			while (this->events.at(firstEvent).getTime() > this->events.at(location).getTime()) firstEvent++;
			std::swap(this->events.at(firstEvent), this->events.at(location));
			return false;
		}
	}

	auto iter = this->events.begin();
	while (iter != this->events.end())
	{
		if (newEvent.getTime() >= (*iter).getTime()) break;
		iter++;
	}
	this->events.emplace(iter, newEvent);
	this->eventCount++;
	return true;
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
	int maxSize = 0;
	for (auto w : this->wires)
	{
		if (w == nullptr) continue;
		if (w->getHistory().size() > maxSize)
		{
			maxSize = w->getHistory().size();
		}
	}

	for (auto w : this->wires)
	{
		if (w == nullptr || w->getName() == "") continue;
		w->printHistory(maxSize);
	}
}
