#include <iostream>

#include "Wire.h"

using namespace std;

Wire::Wire(
	string n, 
	int i, 
	WireValue v//, 
	//vector<Gate*> d = vector<Gate*>()
)
{
	this->value = v;
	this->name = n;
	//this->drives = d;
	this->index = i;
	this->history = vector<WireValue>();
}

Wire::~Wire()
{
	//for (auto gate : drives) 
	//{
	//	delete gate;
	//}
}

void Wire::setValue(WireValue v)
{
	this->setHistory(this->value);
	this->value = v;
}

void Wire::setHistory(WireValue h)
{
	this->history.push_back(h);
}

//void Wire::setDrives(vector<Gate*> d)
//{
//	this->drives = d;
//}

WireValue Wire::getValue() const
{
	return this->value;
}

std::string Wire::getName() const
{
	return this->name;
}

//std::vector<Gate*> Wire::getDrives() const
//{
//	return this->drives;
//}

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
	cout << endl;
}
