#pragma once

#ifndef WIRE_H
#define WIRE_H

#include <string>
#include <vector>

using namespace std;

enum WireValue 
{
	OFF,
	ON,
	UNKNOWN
};

class Gate;

class Wire
{
public:
	Wire(int i, string n = "", WireValue v = UNKNOWN, vector<Gate*> d = vector<Gate*>());
	~Wire();

	void setValue(WireValue v);
	void setHistory(WireValue h);
	void addGate(Gate* d);

	WireValue getValue() const;
	string getName() const;
	int getIndex() const;
	vector<Gate*> getDrives() const;
	vector<WireValue> getHistory() const;

	void printHistory() const;


private:
	WireValue value;
	string name;
	vector<Gate*> drives;
	int index;
	vector<WireValue> history;
};

#endif // !WIRE_H