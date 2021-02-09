#pragma once
#include <iostream>
#include "HandleFile.h"
#include <algorithm>

using namespace std;

class HighScores
{
private:
	HandleFile handleFile = HandleFile();
	const int NUM_HIGHSCORES = 10;
	string highScores[11];
public:
	HighScores()
	{
		handleFile.loadAll("highscores.txt", highScores, NUM_HIGHSCORES);	//load highscores
	}
	void displayHighscores();
	void compareHighscore(int);
	void saveNewScores();
};