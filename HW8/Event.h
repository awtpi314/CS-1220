#pragma once

#ifndef EVENT_H
#define EVENT_H

#include <iostream>

#include "Wire.h"

using namespace std;

class Event
{
public:
	Event(int time, WireValue value, Wire* wire);

	friend bool operator >(const Event& lhs, const Event& rhs);

	int getTime();
	bool getValue();
	Wire* getWire();
	void print() const;

private:
	int time;
	bool value;
	Wire* includedWire;
};

#endif // !
