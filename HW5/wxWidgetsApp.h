#pragma once

#ifndef _MAIN_H
#define _MAIN_H

#include <wx/wx.h>

class wxWidgetsApp : public wxApp {
public:
	wxWidgetsApp();
	virtual ~wxWidgetsApp();
	virtual bool OnInit();
};

DECLARE_APP(wxWidgetsApp)

#endif // !_MAIN_H
