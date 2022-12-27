#pragma once
#include <iostream>
#include <ctime>
#include <limits>
#include <SDL.h>
#include <glew.h>

#include "HighScores.h"

using namespace std;

class Game
{
private:
	int lowestNum = 0;
	int highestNum = 100;
	int overallGuesses = 0;
	HighScores highscores = HighScores();

public:
	void menu();
	int randNum();
	void changeRounds();
	void currentRound();
	void playGame();
	void gameOver();
	void displayInstructions();
	bool isValidGuess(int guess);
	int compareGuesses(int guess, int secretNumber);
};

