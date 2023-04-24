#include "SubGUIClass.h"

#include <wx/msgdlg.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

SubGUIClass::SubGUIClass(wxWindow* parent)
	:
	GUIClass(parent)
{

}

void SubGUIClass::nextStep()
{
	if (!mainCircuit->hasEvent()) return;
	Event e = mainCircuit->getNextEvent();
	if (e.getTime() > 60) return;
	Wire* wireToChange = e.getWire();
	vector<Gate*> gates = wireToChange->getDrives();
	for (auto g : gates)
	{
		mainCircuit->printWires();
		WireValue previous = g->evaluate();
		WireValue next = g->speculate(e);

		stringstream ss("");
		ss << e.getPretty() << " -> ";

		if (previous != next)
		{
			Event newEvent = Event(e.getTime() + g->getDelay(), next, g->getOutput(), mainCircuit->getEventCount());
			mainCircuit->addEvent(newEvent);
			ss << newEvent.getPretty();
		}

		this->actionsTextBox->SetValue(ss.str());
	}

	wireToChange->setValue((WireValue)e.getValue(), e.getTime());
}

void SubGUIClass::ExitClick(wxCommandEvent& event)
{
	this->Close();
}

void SubGUIClass::ShowAboutScreen(wxCommandEvent& event)
{
	wxMessageBox("THE MEGA AWESOME CIRCUIT SIMULATOR\n(c) 2023 Alexander Taylor and Elijah Payton", "MACS About", wxOK | wxICON_INFORMATION);
}

void SubGUIClass::StartClick(wxCommandEvent& event)
{
	while (mainCircuit->hasEvent()) 
	{
		this->nextStep();
	}
	this->traceTextBox->SetValue(mainCircuit->getWireDesc());
	this->queueTextBox->SetValue(mainCircuit->getQueue());
	this->eventHistoryTextBox->SetValue(mainCircuit->getEventHistory());
}

void SubGUIClass::NextStepClick(wxCommandEvent& event)
{
	this->nextStep();
	this->traceTextBox->SetValue(mainCircuit->getWireDesc());
	this->queueTextBox->SetValue(mainCircuit->getQueue());
	this->eventHistoryTextBox->SetValue(mainCircuit->getEventHistory());
}

void SubGUIClass::SearchForVector(wxFileDirPickerEvent& event)
{
	mainCircuit->resetCircuit();
	string baseFileName = (string)this->circuitFilePicker->GetFileName().GetFullPath();
	ifstream f(baseFileName);

	string currentLine;
	getline(f, currentLine);
	string circuitName = currentLine.substr(currentLine.find(" ") + 1);

	mainCircuit->setCircuitName(circuitName);

	while (getline(f, currentLine))
	{
		if (currentLine.length() == 0) break;
		istringstream iss(currentLine);
		string type;
		iss >> type;
		if (type == "INPUT" || type == "OUTPUT")
		{
			string name;
			iss >> name;
			int id;
			iss >> id;

			mainCircuit->setWire(id, new Wire(id, name, type));
		}
		else if (type == "NOT")
		{
			string delay;
			iss >> delay;
			int inputWire;
			iss >> inputWire;
			int outputWire;
			iss >> outputWire;

			if (mainCircuit->getWire(outputWire) == nullptr)
			{
				mainCircuit->setWire(outputWire, new Wire(outputWire));
			}

			Gate* newGate = new Gate(STR_TO_GATE(type), stoi(delay), mainCircuit->getWire(outputWire), mainCircuit->getWire(inputWire));
			mainCircuit->addGate(newGate);
			mainCircuit->getWire(inputWire)->addGate(newGate);
		}
		else
		{
			string delay;
			iss >> delay;
			int inputWire1;
			iss >> inputWire1;
			int inputWire2;
			iss >> inputWire2;
			int outputWire;
			iss >> outputWire;

			if (mainCircuit->getWire(outputWire) == nullptr)
			{
				mainCircuit->setWire(outputWire, new Wire(outputWire));
			}

			Gate* newGate = new Gate(STR_TO_GATE(type), stoi(delay), mainCircuit->getWire(outputWire), mainCircuit->getWire(inputWire1), mainCircuit->getWire(inputWire2));
			mainCircuit->addGate(newGate);
			mainCircuit->getWire(inputWire1)->addGate(newGate);
			mainCircuit->getWire(inputWire2)->addGate(newGate);
		}
	}

	string vectorFileName = baseFileName.substr(0, baseFileName.length() - 4) + "_v.txt";
	this->vectorFilePicker->SetFileName(wxFileName(vectorFileName));

	this->VectorFileChange(event);

	this->traceTextBox->SetValue(mainCircuit->getWireDesc());
	this->queueTextBox->SetValue(mainCircuit->getQueue());
	this->actionsTextBox->SetValue("");
	this->eventHistoryTextBox->SetValue("");
}

void SubGUIClass::VectorFileChange(wxFileDirPickerEvent& event)
{
	string currentLine;
	string vectorFileName = (string)this->vectorFilePicker->GetFileName().GetFullPath();
	ifstream inFS(vectorFileName);

	getline(inFS, currentLine);

	while (getline(inFS, currentLine))
	{
		if (currentLine.length() == 0) break;
		istringstream iss(currentLine);
		string wireName;
		iss >> wireName;
		iss >> wireName;

		int time;
		iss >> time;
		string stringValue;
		iss >> stringValue;

		WireValue value;
		if (stringValue == "X")
		{
			value = UNKNOWN;
		}
		else
		{
			value = (WireValue)std::stoi(stringValue);
		}

		Event e = Event(time, value, mainCircuit->getWire(wireName), mainCircuit->getEventCount());
		mainCircuit->addEvent(e);
	}
}
