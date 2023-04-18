#pragma once

#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <map>
#include <string>
#include <queue>

#include "Event.h"
#include "Gate.h"

using namespace std;

class Circuit
{
public:
	Circuit() { this->name = ""; };
	Circuit(string name);
	~Circuit();
	string getCircuitName() const;
	Event getNextEvent();
	Wire* getWire(size_t n) const;
	Wire* getWire(string s) const;
	Gate* getGate(size_t n) const;
	int getEventCount();
	bool hasEvent() const { return !this->events.empty(); }
	void setCircuitName(string newName);
	void addEvent(Event& newEvent);
	void setWire(size_t n, Wire* inWire);
	void addGate(Gate* g);
	void printWires() const;

private:
	string name;
	priority_queue<Event, vector<Event>, greater<Event>> events;
	vector<Wire*> wires;
	vector<Gate*> gates;
	int eventCount = 0;
};

#endif // !CIRCUIT_H
