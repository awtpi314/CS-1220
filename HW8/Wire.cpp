#include <iostream>

#include "Wire.h"

using namespace std;

Wire::Wire(
	int i, 
	string n, 
	string type,
	WireValue v,
	vector<Gate*> d
)
{
	this->value = v;
	this->name = n;
	this->type = type;
	this->drives = d;
	this->index = i;
	this->history = vector<WireValue>();
}

Wire::~Wire()
{
}

void Wire::setValue(WireValue v, size_t t)
{
	this->setHistory(v, t);
	this->value = v;
}

void Wire::setHistory(WireValue h, size_t t)
{
	if (this->history.size() <= t) {
		this->history.resize(t + 1, this->value);
	}
	this->history[t] = h;
}

void Wire::addGate(Gate* d)
{
	this->drives.push_back(d);
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

string Wire::getType() const
{
	return this->type;
}

void Wire::printHistory() const
{
	this->printHistory(this->history.size());
}

void Wire::printHistory(int length) const
{
	cout << this->name << "\t";
	for (auto dataPoint : this->history) {
		switch (dataPoint)
		{
		case ON:
			cout << "-";
			break;
		case OFF:
			cout << "_";
			break;
		default:
			cout << "X";
			break;
		}
	}
	for (int i = this->history.size(); i < length; i++) 
	{
		switch (this->value)
		{
		case ON:
			cout << "-";
			break;
		case OFF:
			cout << "_";
			break;
		default:
			cout << "X";
			break;
		}
	}
	cout << endl;
}
