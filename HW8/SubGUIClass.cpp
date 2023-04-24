#include "SubGUIClass.h"

#include <wx/msgdlg.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

SubGUIClass::SubGUIClass( wxWindow* parent )
:
GUIClass( parent )
{

}

void SubGUIClass::ExitClick( wxCommandEvent& event )
{
	this->Close();
}

void SubGUIClass::ShowAboutScreen( wxCommandEvent& event )
{
	wxMessageBox("THE MEGA AWESOME CIRCUIT SIMULATOR\n(c) 2023 Alexander Taylor and Elijah Payton", "MACS About", wxOK | wxICON_INFORMATION);
}

void SubGUIClass::StartClick( wxCommandEvent& event )
{
	if (this->singleStepBox->GetValue())
	{

	}
	else
	{

	}
}

void SubGUIClass::NextStepClick( wxCommandEvent& event )
{
// TODO: Implement NextStepClick
}

void SubGUIClass::PauseClick( wxCommandEvent& event )
{
// TODO: Implement PauseClick
}

void SubGUIClass::SearchForVector( wxFileDirPickerEvent& event )
{
	ifstream f((string)this->circuitFilePicker->GetFileName().GetFullPath());

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
}
