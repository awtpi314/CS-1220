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
	Wire(int i, string n = "", string type = "INPUT", WireValue v = UNKNOWN, vector<Gate*> d = vector<Gate*>());
	~Wire();

	void setValue(WireValue v, size_t t = -1);
	void setHistory(WireValue h, size_t t = -1);
	void addGate(Gate* d);

	WireValue getValue() const;
	string getName() const;
	int getIndex() const;
	vector<Gate*> getDrives() const;
	vector<WireValue> getHistory() const;
	string getType() const;

	void printHistory() const;
	void printHistory(int length) const;
	string getHistoryPretty() const;
	string getHistoryPretty(size_t length) const;


private:
	WireValue value;
	string name;
	vector<Gate*> drives;
	int index;
	string type;
	vector<WireValue> history;
};

#endif // !WIRE_H