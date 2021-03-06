#include "TicTacManager.h"
#include <iostream>

TicTacManager::TicTacManager()
{
}

TicTacManager::~TicTacManager()
{
	delete this->player2;
	delete this->player1;
	delete this->board;
}

bool TicTacManager::Init()
{
	unsigned int boardsize;
	string playerName;
	cout << "??????? ????? ?????? ???? (3-6): ";
	cin >> boardsize;
	if ((boardsize < 3) || (boardsize > 6))
	{
		cout << "???????? ????? ?????? ????" << endl;
		return false;
	}
	this->board = new TicTacBoard(boardsize);
	this->player1 = new TicTacPlayer();
	this->player2 = new TicTacPlayer();
	cin.ignore();
	cout << "??????? ??? ?????? ????????? ?? X: ";
	getline(cin, playerName);
	player1->SetupPlayer(playerName, CellType_X);
	cout << "??????? ??? ?????? ????????? ?? O: ";
	getline(cin, playerName);
	player2->SetupPlayer(playerName, CellType_O);
	player1->SetBoard(this->board);
	player2->SetBoard(this->board);
	currentPlayer = player1;





	return true;
}

void TicTacManager::ShowBoard()
{
	this->board->Show();
}

void TicTacManager::MakeMove()
{
	ShowBoard();
	while (!currentPlayer->MakeMove())
	{
		cout << "???????????? ???, ?????????? ??? ???" << endl;
		ShowBoard();
	}
	if (this->board->CheckEndCondition())
	{	
		if (this->board->IsVictory())
		cout << "?????" << currentPlayer->GetName() << " ???????!" << endl;
	else
		cout << "?????!" << endl;
	this->bGameFinished = true;
	ShowBoard();
	return;
	}
	currentPlayer = (currentPlayer == player1) ? player2 : player1;
}

bool TicTacManager::IsGameFinished()
{
	return bGameFinished;
}
