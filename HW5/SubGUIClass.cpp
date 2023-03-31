#include "SubGUIClass.h"
#include <wx/msgdlg.h>

SubGUIClass::SubGUIClass( wxWindow* parent )
:
GUIClass( parent )
{
}

State SubGUIClass::checkWinner(int x, int y, State s)
{
	if ((board[x][0] == board[x][1] && board[x][1] == board[x][2] && board[x][0] == s) ||
		(board[0][y] == board[1][y] && board[1][y] == board[2][y] && board[0][y] == s) ||
		(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == s) ||
		(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == s)) {
		return s;
	}

	if (moveCount == 9) {
		return Draw;
	}

	return Blank;
}

void SubGUIClass::resetBoard()
{
	this->pos00->SetLabel(wxT(""));
	this->pos01->SetLabel(wxT(""));
	this->pos02->SetLabel(wxT(""));
	this->pos10->SetLabel(wxT(""));
	this->pos11->SetLabel(wxT(""));
	this->pos12->SetLabel(wxT(""));
	this->pos20->SetLabel(wxT(""));
	this->pos21->SetLabel(wxT(""));
	this->pos22->SetLabel(wxT(""));

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = Blank;
		}
	}
	moveCount = 0;

	this->isOTurn = true;
	statusBar->SetLabel("   It's player O's turn");
}

void SubGUIClass::OnMainWindowClose( wxCloseEvent& event )
{
	if (event.CanVeto()) {
		const auto result = wxMessageBox(wxT("Are you sure you want to exit?"), wxT("Confirm Exit"), wxICON_QUESTION | wxYES_NO);
		if (result != 2) {
			event.Veto();
			return;
		}
	}

	Destroy();
}

void SubGUIClass::OnResetClick( wxCommandEvent& event )
{
	const auto result = wxMessageBox(wxT("Are you sure you want to reset the board?"), wxT("Confirm Reset"), wxICON_QUESTION | wxYES_NO);
	if (result == wxYES) {
		resetBoard();
	}
}

void SubGUIClass::OnExit( wxCommandEvent& event )
{
	const auto result = wxMessageBox(wxT("Are you sure you want to exit?"), wxT("Confirm Exit"), wxICON_QUESTION| wxYES_NO);
	if (result == wxYES) {
		this->Close(true);
	}
}

void SubGUIClass::OnPlayerClick( wxCommandEvent& event )
{
	auto button = (wxButton*) event.GetEventObject();
	auto position = button->GetRect();
	
	if (button->GetLabel().length() == 0) {
		if (isOTurn) {
			button->SetLabel("O");
			statusBar->SetLabel("   It's player X's turn");
		}
		else {
			button->SetLabel("X");
			statusBar->SetLabel("   It's player O's turn");
		}

		int x = position.x / 100;
		int y = position.y / 100;
		auto playerMove = this->isOTurn ? O : X;

		if (board[x][y] == Blank) {
			board[x][y] = playerMove;
			moveCount++;
		}
		auto winner = checkWinner(x, y, playerMove);
		int result = -1;

		switch (winner) {
		case O:
			result = wxMessageBox(wxT("The O player wins! Play again?"), wxT("Winner!"), wxYES_NO | wxYES_DEFAULT);
			resetBoard();
			break;
		case X:
			result = wxMessageBox(wxT("The X player wins! Play again?"), wxT("Winner!"), wxYES_NO | wxYES_DEFAULT);
			resetBoard();
			break;
		case Draw:
			result = wxMessageBox(wxT("Looks like that's a cat game. Play again?"), wxT("Draw"), wxYES_NO | wxYES_DEFAULT);
			resetBoard();
			break;
		default:
			isOTurn = !isOTurn;
			return;
		}

		if (result == wxNO) {
			OnExit(event);
		}
	}
}
