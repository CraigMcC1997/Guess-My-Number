#pragma once
#include <iostream>
#include <ctime>
#include <limits>
#include <SDL.h>
#include <glew.h>

#include "AbstractGame.h"

using namespace std;

class GuessMyNumber : public AbstractGame
{
private:
	enum GUESS_VALUE { TOO_HIGH, TOO_LOW, CORRECT_GUESS };

	int lowestNum{ 0 };
	int highestNum{ 100 };
	int overallGuesses{ 0 };

public:
	GuessMyNumber()
	{
		init();
		patchInstructions();
	}

	/* required by parent class */
	void init();
	void menu();
	void playGame();
	void gameOver();
	void patchInstructions();

	/* game specific functions */
	int randNum();
	void currentRound();
	void displayCurrentGameMenu();
	bool isValidGuess(int guess);
	int compareGuesses(int guess, int secretNumber);
};
