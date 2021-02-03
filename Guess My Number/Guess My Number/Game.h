#pragma once
#include <iostream>
#include <ctime>
#include <limits>
#include <SDL.h>
#include <glew.h>

using namespace std;

class Game
{
private:
	int lowestNum = 0;
	int highestNum = 100;
	int overallGuesses = 0;

public:
	void menu();
	int randNum();
	void changeRounds();
	void currentRound();
	void playGame();
	void draw(SDL_Window*);
};

