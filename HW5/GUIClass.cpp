///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUIClass.h"

///////////////////////////////////////////////////////////////////////////

GUIClass::GUIClass( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 340,500 ), wxSize( 340,500 ) );
	
	menuBar = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	wxMenuItem* newGameMenu;
	newGameMenu = new wxMenuItem( fileMenu, wxID_ANY, wxString( wxT("New Game") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( newGameMenu );
	
	wxMenuItem* sep1;
	sep1 = fileMenu->AppendSeparator();
	
	exitMenu = new wxMenuItem( fileMenu, wxID_EXIT, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( exitMenu );
	
	menuBar->Append( fileMenu, wxT("File") ); 
	
	this->SetMenuBar( menuBar );
	
	wxBoxSizer* panelSizer;
	panelSizer = new wxBoxSizer( wxVERTICAL );
	
	mainPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* contentSizer;
	contentSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* row0;
	row0 = new wxBoxSizer( wxHORIZONTAL );
	
	pos00 = new wxButton( mainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,100 ), 0 );
	pos00->SetFont(wxFont(48, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	
	row0->Add( pos00, 0, wxALL, 5 );
	
	pos01 = new wxButton( mainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,100 ), 0 );
	pos01->SetFont(wxFont(48, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	
	row0->Add( pos01, 0, wxALL, 5 );
	
	pos02 = new wxButton( mainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,100 ), 0 );
	pos02->SetFont(wxFont(48, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	
	row0->Add( pos02, 0, wxALL, 5 );
	
	contentSizer->Add( row0, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* row1;
	row1 = new wxBoxSizer( wxHORIZONTAL );
	
	pos10 = new wxButton( mainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,100 ), 0 );
	pos10->SetFont(wxFont(48, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	
	row1->Add( pos10, 0, wxALL, 5 );
	
	pos11 = new wxButton( mainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,100 ), 0 );
	pos11->SetFont(wxFont(48, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	
	row1->Add( pos11, 0, wxALL, 5 );
	
	pos12 = new wxButton( mainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,100 ), 0 );
	pos12->SetFont(wxFont(48, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	
	row1->Add( pos12, 0, wxALL, 5 );
	
	contentSizer->Add( row1, 1, wxEXPAND, 5 );
	
	wxBoxSizer* row2;
	row2 = new wxBoxSizer( wxHORIZONTAL );
	
	pos20 = new wxButton( mainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,100 ), 0 );
	pos20->SetFont(wxFont(48, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));;
	
	row2->Add( pos20, 0, wxALL, 5 );
	
	pos21 = new wxButton( mainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,100 ), 0 );
	pos21->SetFont(wxFont(48, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));;
	
	row2->Add( pos21, 0, wxALL, 5 );
	
	pos22 = new wxButton( mainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,100 ), 0 );
	pos22->SetFont(wxFont(48, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));;
	
	row2->Add( pos22, 0, wxALL, 5 );
	
	contentSizer->Add( row2, 1, wxEXPAND, 5 );
	
	wxBoxSizer* programFunctions;
	programFunctions = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* buttonsSpacer;
	buttonsSpacer = new wxBoxSizer( wxHORIZONTAL );
	
	resetButton = new wxButton( mainPanel, wxID_ANY, wxT("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	buttonsSpacer->Add( resetButton, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	exitButton = new wxButton( mainPanel, wxID_ANY, wxT("Exit"), wxDefaultPosition, wxDefaultSize, 0 );
	buttonsSpacer->Add( exitButton, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	programFunctions->Add( buttonsSpacer, 1, wxEXPAND, 5 );
	
	contentSizer->Add( programFunctions, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	mainPanel->SetSizer( contentSizer );
	mainPanel->Layout();
	contentSizer->Fit( mainPanel );
	panelSizer->Add( mainPanel, 1, wxEXPAND, 5 );
	
	this->SetSizer( panelSizer );
	this->Layout();
	statusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	statusBar->SetLabel("   It's player O's turn");
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIClass::OnMainWindowClose ) );
	this->Connect( newGameMenu->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIClass::OnResetClick ) );
	this->Connect( exitMenu->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIClass::OnExit ) );
	pos00->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnPlayerClick ), NULL, this );
	pos01->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnPlayerClick ), NULL, this );
	pos02->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnPlayerClick ), NULL, this );
	pos10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnPlayerClick ), NULL, this );
	pos11->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnPlayerClick ), NULL, this );
	pos12->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnPlayerClick ), NULL, this );
	pos20->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnPlayerClick ), NULL, this );
	pos21->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnPlayerClick ), NULL, this );
	pos22->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnPlayerClick ), NULL, this );
	resetButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnResetClick ), NULL, this );
	exitButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnExit ), NULL, this );
}

GUIClass::~GUIClass()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIClass::OnMainWindowClose ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIClass::OnResetClick ) );
	this->Disconnect( wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIClass::OnExit ) );
	pos00->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnPlayerClick ), NULL, this );
	pos01->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnPlayerClick ), NULL, this );
	pos02->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnPlayerClick ), NULL, this );
	pos10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnPlayerClick ), NULL, this );
	pos11->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnPlayerClick ), NULL, this );
	pos12->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnPlayerClick ), NULL, this );
	pos20->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnPlayerClick ), NULL, this );
	pos21->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnPlayerClick ), NULL, this );
	pos22->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnPlayerClick ), NULL, this );
	resetButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnResetClick ), NULL, this );
	exitButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::OnExit ), NULL, this );
	
}
