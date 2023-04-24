///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUICLASS_H__
#define __GUICLASS_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statusbr.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/filepicker.h>
#include <wx/textctrl.h>
#include <wx/statbmp.h>
#include <wx/panel.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class GUIClass
///////////////////////////////////////////////////////////////////////////////
class GUIClass : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* topMenu;
		wxMenu* fileMenu;
		wxMenu* modeMenu;
		wxMenu* helpMenu;
		wxStatusBar* statusBar;
		wxPanel* m_panel2;
		wxButton* startButton;
		wxButton* nextStepButton;
		wxStaticText* circuitFileText;
		wxFilePickerCtrl* circuitFilePicker;
		wxStaticText* vectorFileText;
		wxFilePickerCtrl* vectorFilePicker;
		wxStaticText* actionsText;
		wxTextCtrl* actionsTextBox;
		wxStaticText* queueText;
		wxTextCtrl* queueTextBox;
		wxStaticText* eventHistoryText;
		wxTextCtrl* eventHistoryTextBox;
		wxStaticText* traceText;
		wxTextCtrl* traceTextBox;
		wxStaticBitmap* shomperk;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ExitClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void ShowAboutScreen( wxCommandEvent& event ) { event.Skip(); }
		virtual void StartClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void NextStepClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void SearchForVector( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void VectorFileChange( wxFileDirPickerEvent& event ) { event.Skip(); }
		
	
	public:
		
		GUIClass( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Mega Awesome Circuit Simulator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 863,554 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~GUIClass();
	
};

#endif //__GUICLASS_H__
