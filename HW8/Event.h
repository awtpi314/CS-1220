#pragma once

#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <sstream>

#include "Wire.h"

using namespace std;

class Event
{
public:
	Event(int time, WireValue value, Wire* wire, int number);

	//friend bool operator >(const Event& lhs, const Event& rhs);
	friend bool operator <(const Event& lhs, const Event& rhs);
	//friend bool operator ==(const Event& lhs, const Event& rhs);

	int getTime() const;
	WireValue getValue() const;
	Wire* getWire() const;
	void print() const;
	string getPretty() const;

private:
	int time;
	WireValue value;
	Wire* includedWire;
	int number;
};

#endif // !
