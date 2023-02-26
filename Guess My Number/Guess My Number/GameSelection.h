#pragma once
#include <iostream>
#include "GuessMyNumber.h"
#include "X&Os.h"

using namespace std;

class GameSelection
{
private:
	GuessMyNumber* guessNumberGame{ new GuessMyNumber() };
	XandOGame* XandOsGame{ new XandOGame() };

public:
	GameSelection() {}

	void GameSelectorMenu();
	void DisplayGamesMenu();
};

