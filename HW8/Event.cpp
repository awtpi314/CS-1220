#include "Event.h"

using namespace std;

Event::Event(int time, WireValue value, Wire* wire, int number)
{
	this->time = time;
	this->value = value;
	this->includedWire = wire;
	this->number = number;
}

bool operator >(const Event& lhs, const Event& rhs)
{
	return lhs.time > rhs.time;
}

bool operator<(const Event& lhs, const Event& rhs)
{
	return lhs.time < rhs.time;
}

bool operator==(const Event& lhs, const Event& rhs)
{
	return lhs.includedWire->getIndex() == rhs.includedWire->getIndex() && 
		lhs.time == rhs.time && 
		lhs.value == rhs.value;
}

int Event::getTime() const
{
	return this->time;
}

WireValue Event::getValue() const
{
	return this->value;
}

Wire* Event::getWire() const
{
	return this->includedWire;
}

void Event::print() const
{
	cout << "[" << this->includedWire->getIndex() << ", " << this->time << ", " << this->value << ", " << this->number << "]";
}