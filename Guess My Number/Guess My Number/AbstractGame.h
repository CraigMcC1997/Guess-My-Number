#pragma once
#include "Highscores_Handler.h"
#include "Instructions_Handler.h"

class AbstractGame {
protected:
	HighScores* highscores;
	Instructions* instructions;

	string highscores_filename{ };
	string instructions_filename{ };

	bool returnToMenu{ false };
public:
	virtual void init() = 0;
	virtual void menu() = 0;
	virtual void playGame() = 0;
	virtual void gameOver() = 0;
	virtual void patchInstructions() = 0;
};
