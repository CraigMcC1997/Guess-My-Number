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
	string current_scores[10];
	int err;

	struct HighscoreEntry {
		string name;
		int score;
		int position;
	};

	HighscoreEntry highscores[10];

public:
	HighScores()
	{
		err = handleFile.loadAll(filename, current_scores);	//load highscores
		if (err != NUM_HIGHSCORES)
		{
			cerr << "Expected loadAll() to return: " << NUM_HIGHSCORES << " instead returned: " << err << endl;
		}
		inputHighscores();
	}

	void displayHighscores();
	void compareHighscore(int&);
	void updateHighscores(HighscoreEntry highscores[], const string& name, int score);
	void saveNewScores();
	void inputHighscores();
};