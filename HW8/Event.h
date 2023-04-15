#pragma once

#ifndef EVENT_H
#define EVENT_H

#include "Wire.h"

using namespace std;

class Event
{
	Event();
	~Event();

	private:
		Wire* includedWire;

};

#endif // !
