#pragma once
#include <iostream>
#include "LoadFromFile.h"

class HighScores
{
private:
	LoadFromFile loadFile = LoadFromFile();
	const int MAX_HIGHSCORE = 10;
	string highScores[10];
public:
	HighScores()
	{
		loadFile.loadAll("highscores.txt", highScores, MAX_HIGHSCORE);	//load highscores
	}
	void displayHighscores();
	void compareHighscore(int );
};