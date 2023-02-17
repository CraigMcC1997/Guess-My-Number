#pragma once
#include <iostream>
#include "GuessMyNumber.h"

using namespace std;

class GameSelection
{
private:
	GuessMyNumber* guessNumberGame{ new GuessMyNumber() };

public:
	GameSelection() {}

	void GameSelectorMenu();
	void DisplayGamesMenu();
};

