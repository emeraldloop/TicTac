#pragma once
#include "TicTacBoard.h"
#include <conio.h>
#include <string>
#include <iostream>
using namespace std;

class TicTacPlayer
{
private:
	TicTacBoard* board;
	CellType cellType;
	string name;
public:
	TicTacPlayer();
	virtual ~TicTacPlayer();
	void SetupPlayer(string name, CellType cellType);
	void SetBoard(TicTacBoard* board);
	bool MakeMove();
	string GetName();
};

