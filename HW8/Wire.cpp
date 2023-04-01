#include <iostream>

#include "Wire.h"

Wire::Wire(
	std::string n, 
	int i, 
	WireValue v = UNKNOWN, 
	std::vector<Gate*> d = std::vector<Gate*>()
)
{
	this->value = v;
	this->name = n;
	this->drives = d;
	this->index = i;
	this->history = std::vector<WireValue>();
}

Wire::~Wire()
{
	for (auto gate : drives) 
	{
		delete gate;
	}
}

void Wire::setValue(WireValue v)
{
	this->value = v;
}

void Wire::setName(std::string n)
{
	this->name = n;
}

void Wire::setDrives(std::vector<Gate*> d)
{
	this->drives = d;
}

WireValue Wire::getValue() const
{
	return this->value;
}

std::string Wire::getName() const
{
	return this->name;
}

std::vector<Gate*> Wire::getDrives() const
{
	return this->drives;
}

int Wire::getIndex() const
{
	return this->index;
}

std::vector<WireValue> Wire::getHistory() const
{
	return this->history;
}

void Wire::printHistory() const
{
	std::cout << this->name << "\t";
	for (auto dataPoint : this->history) {
		switch (dataPoint)
		{
		case ON:
			std::cout << "-";
			break;
		case OFF:
			std::cout << "_";
			break;
		default:
			std::cout << "X";
			break;
		}
	}
	std::cout << std::endl;
}
