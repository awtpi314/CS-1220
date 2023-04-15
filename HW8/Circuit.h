#pragma once

#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <map>
#include <string>

#include "Queue.h"
#include "Gate.h"

using namespace std;

class Circuit
{
public:
	Circuit(string name);
	~Circuit();
	string getCircuitName();
	Queue getCircuitEvents();
	Wire* getWire(size_t n);
	void setCircuitName(string newName);
	void setCircuitEvents(Queue newEvent);
	void setWire(size_t n, Wire* inWire);

private:
	string name;
	Queue events;
	vector<Wire*> wires;
};

#endif // !CIRCUIT_H
