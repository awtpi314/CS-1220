#include "Event.h"

using namespace std;

Event::Event(int time, WireValue value, Wire* wire)
{
	this->time = time;
	this->value = value;
	this->includedWire = wire;
}

bool operator >(const Event& lhs, const Event& rhs)
{
	return lhs.time > rhs.time;
}

int Event::getTime()
{
	return this->time;
}

bool Event::getValue()
{
	return this->value;
}

Wire* Event::getWire()
{
	return this->includedWire;
}

void Event::print() const
{
	cout << "Wire " << this->includedWire->getName() << " will change at " << this->time << " to a value of " << this->value << endl;
}