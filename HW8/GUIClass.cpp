///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUIClass.h"

#include "shomperk.bmp.h"

///////////////////////////////////////////////////////////////////////////

GUIClass::GUIClass( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	topMenu = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	modeMenu = new wxMenu();
	wxMenuItem* mode0;
	mode0 = new wxMenuItem( modeMenu, wxID_ANY, wxString( wxT("Mode 0 (default)") ) , wxEmptyString, wxITEM_NORMAL );
	modeMenu->Append( mode0 );
	
	wxMenuItem* mode1;
	mode1 = new wxMenuItem( modeMenu, wxID_ANY, wxString( wxT("Mode 1 (non-standard)") ) , wxEmptyString, wxITEM_NORMAL );
	modeMenu->Append( mode1 );
	
	fileMenu->Append( -1, wxT("Mode"), modeMenu );
	
	wxMenuItem* exitButton;
	exitButton = new wxMenuItem( fileMenu, wxID_EXIT, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( exitButton );
	
	topMenu->Append( fileMenu, wxT("File") ); 
	
	helpMenu = new wxMenu();
	wxMenuItem* aboutMenu;
	aboutMenu = new wxMenuItem( helpMenu, wxID_ANY, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	helpMenu->Append( aboutMenu );
	
	topMenu->Append( helpMenu, wxT("Help") ); 
	
	this->SetMenuBar( topMenu );
	
	statusBar = this->CreateStatusBar( 3, wxST_SIZEGRIP, wxID_ANY );
	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );
	
	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	startButton = new wxButton( m_panel2, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( startButton, 1, wxALL, 5 );
	
	nextStepButton = new wxButton( m_panel2, wxID_ANY, wxT("Next Step"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( nextStepButton, 1, wxALL, 5 );
	
	pauseButton = new wxButton( m_panel2, wxID_ANY, wxT("Pause"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( pauseButton, 1, wxALL, 5 );
	
	bSizer2->Add( bSizer9, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer( wxHORIZONTAL );
	
	circuitFileText = new wxStaticText( m_panel2, wxID_ANY, wxT("Circuit File:"), wxDefaultPosition, wxDefaultSize, 0 );
	circuitFileText->Wrap( -1 );
	bSizer91->Add( circuitFileText, 0, wxALL, 5 );
	
	circuitFilePicker = new wxFilePickerCtrl( m_panel2, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	bSizer91->Add( circuitFilePicker, 0, wxALL, 5 );
	
	bSizer2->Add( bSizer91, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer911;
	bSizer911 = new wxBoxSizer( wxHORIZONTAL );
	
	vectorFileText = new wxStaticText( m_panel2, wxID_ANY, wxT("Vector File:"), wxDefaultPosition, wxDefaultSize, 0 );
	vectorFileText->Wrap( -1 );
	bSizer911->Add( vectorFileText, 0, wxALL, 5 );
	
	vectorFilePicker = new wxFilePickerCtrl( m_panel2, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	vectorFilePicker->Enable( false );
	
	bSizer911->Add( vectorFilePicker, 0, wxALL, 5 );
	
	bSizer2->Add( bSizer911, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );
	
	singleStepBox = new wxCheckBox( m_panel2, wxID_ANY, wxT("Single Step"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer25->Add( singleStepBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer2->Add( bSizer25, 0, wxEXPAND, 5 );
	
	actionsText = new wxStaticText( m_panel2, wxID_ANY, wxT("Actions:"), wxDefaultPosition, wxDefaultSize, 0 );
	actionsText->Wrap( -1 );
	bSizer2->Add( actionsText, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );
	
	actionsTextBox = new wxTextCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	bSizer18->Add( actionsTextBox, 1, wxALL|wxEXPAND, 5 );
	
	bSizer2->Add( bSizer18, 1, wxEXPAND, 5 );
	
	queueText = new wxStaticText( m_panel2, wxID_ANY, wxT("Queue:"), wxDefaultPosition, wxDefaultSize, 0 );
	queueText->Wrap( -1 );
	bSizer2->Add( queueText, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );
	
	queueTextBox = new wxTextCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	bSizer19->Add( queueTextBox, 1, wxALL|wxEXPAND, 5 );
	
	bSizer2->Add( bSizer19, 1, wxEXPAND, 5 );
	
	eventHistoryText = new wxStaticText( m_panel2, wxID_ANY, wxT("Event History:"), wxDefaultPosition, wxDefaultSize, 0 );
	eventHistoryText->Wrap( -1 );
	bSizer2->Add( eventHistoryText, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer181;
	bSizer181 = new wxBoxSizer( wxVERTICAL );
	
	eventHistoryTextBox = new wxTextCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	bSizer181->Add( eventHistoryTextBox, 1, wxALL|wxEXPAND, 5 );
	
	bSizer2->Add( bSizer181, 1, wxEXPAND, 5 );
	
	bSizer1->Add( bSizer2, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );
	
	traceText = new wxStaticText( m_panel2, wxID_ANY, wxT("Trace:"), wxDefaultPosition, wxDefaultSize, 0 );
	traceText->Wrap( -1 );
	bSizer23->Add( traceText, 0, wxALL|wxEXPAND, 5 );
	
	traceTextBox = new wxTextCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	bSizer23->Add( traceTextBox, 1, wxEXPAND, 5 );
	
	bSizer15->Add( bSizer23, 2, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxVERTICAL );
	
	shomperk = new wxStaticBitmap( m_panel2, wxID_ANY, shomperk_bmp_to_wx_bitmap(), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24->Add( shomperk, 1, 0, 5 );
	
	bSizer15->Add( bSizer24, 1, wxEXPAND, 5 );
	
	bSizer1->Add( bSizer15, 2, wxEXPAND, 5 );
	
	m_panel2->SetSizer( bSizer1 );
	m_panel2->Layout();
	bSizer1->Fit( m_panel2 );
	bSizer51->Add( m_panel2, 1, wxEXPAND | wxALL, 5 );
	
	this->SetSizer( bSizer51 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( exitButton->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIClass::ExitClick ) );
	this->Connect( aboutMenu->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIClass::ShowAboutScreen ) );
	startButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::StartClick ), NULL, this );
	nextStepButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::NextStepClick ), NULL, this );
	pauseButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::PauseClick ), NULL, this );
	circuitFilePicker->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( GUIClass::SearchForVector ), NULL, this );
}

GUIClass::~GUIClass()
{
	// Disconnect Events
	this->Disconnect( wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIClass::ExitClick ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIClass::ShowAboutScreen ) );
	startButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::StartClick ), NULL, this );
	nextStepButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::NextStepClick ), NULL, this );
	pauseButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::PauseClick ), NULL, this );
	circuitFilePicker->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( GUIClass::SearchForVector ), NULL, this );
	
}
