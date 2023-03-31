///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "noname.h"

///////////////////////////////////////////////////////////////////////////

MainWindow::MainWindow( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	menuBar = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	menuButtonExit = new wxMenu();
	fileMenu->Append( -1, wxT("Exit"), menuButtonExit );
	
	menuBar->Append( fileMenu, wxT("File") ); 
	
	this->SetMenuBar( menuBar );
	
	
	this->Centre( wxBOTH );
}

MainWindow::~MainWindow()
{
}
