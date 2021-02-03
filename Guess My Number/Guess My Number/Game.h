#pragma once
#include <iostream>
#include <ctime>
#include <limits>

using namespace std;

class Game
{
private:
	int lowestNum = 0;
	int highestNum = 100;
	int overallGuesses = 0;

public:
	int randNum();
	void changeRounds();
	void currentRound();
	void playGame();
};

