#pragma once
#include <iostream>
#include <ctime>
#include <limits>
#include <SDL.h>
#include <glew.h>

#include "HighScores.h"
#include "HandleFile.h"

using namespace std;

class Game
{
private:
	int lowestNum = 0;
	int highestNum = 100;
	int overallGuesses = 0;

	string filename = "../Resources/instructions.txt";
	string instructions[6];

	HighScores highscores = HighScores();
	HandleFile handleFile = HandleFile();

public:
	Game()
	{
		int err = handleFile.loadAll(filename, instructions);	//load highscores
		if (err != 6)
		{
			cerr << "Expected loadAll() to return: 6 instead returned: " << err << endl;
		}
	}
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

