#pragma once
#include <iostream>
#include "HandleFile.h"
#include <algorithm>

using namespace std;

class HighScores
{
private:
	HandleFile handleFile = HandleFile();
	string filename = "../Resources/highscores.txt";
	const int NUM_HIGHSCORES = 10;
	string highScores[11];
	int err;

public:
	HighScores()
	{
		err = handleFile.loadAll(filename, highScores);	//load highscores

		if (err != NUM_HIGHSCORES)
		{
			cerr << "Expected loadAll() to return: " << NUM_HIGHSCORES << " instead returned: " << err << endl;
		}
	}

	void displayHighscores();
	void compareHighscore(int&);
	void updateHighscores(int, string::size_type&);
	void saveNewScores();
};