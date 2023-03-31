#include "wxWidgetsApp.h"
#include "SubGUIClass.h"

IMPLEMENT_APP(wxWidgetsApp)

wxWidgetsApp::wxWidgetsApp() {

}

wxWidgetsApp:: ~wxWidgetsApp() {

}

bool wxWidgetsApp::OnInit() {
	SubGUIClass* frame = new SubGUIClass((wxWindow*) nullptr);
	frame->Show();
	SetTopWindow(frame);
	return true;
}