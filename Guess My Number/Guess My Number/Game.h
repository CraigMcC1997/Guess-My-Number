#pragma once
#include <iostream>
#include <ctime>

using namespace std;

class Game
{
private:
	int lowestNum = 0;
	int highestNum = 100;

public:
	int randNum();
	void changeRounds();
	void currentRound();
	void playGame();
};

