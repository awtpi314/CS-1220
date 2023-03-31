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