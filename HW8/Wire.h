#pragma once

#ifndef WIRE_H
#define WIRE_H

#include <string>
#include <vector>

#include "Gate.h"

enum WireValue 
{
	OFF,
	ON,
	UNKNOWN
};

class Wire
{
public:
	Wire(std::string n, int i, WireValue v = UNKNOWN, std::vector<Gate*> d = std::vector<Gate*>());
	~Wire();

	void setValue(WireValue v);
	void setName(std::string n);

private:
	WireValue value;
	std::string name;
	std::vector<Gate*> drives;
	int index;
	std::vector<WireValue> history;
};

#endif // !WIRE_H