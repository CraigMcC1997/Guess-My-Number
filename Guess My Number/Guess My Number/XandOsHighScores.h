#pragma once
#include "AbstractHighscoresHandler.h"

using namespace std;

class XandOsHighScores : public AbstractHighscoresHandler
{
private:
	string filename{};
	string current_scores[10];

	struct HighscoreEntry {
		string name;
		int position;
		int wins;
		int draws;
		int loses;
	};

	HighscoreEntry highscores[10];

public:
	XandOsHighScores(string filename) : filename{ filename }
	{
		int err = handleFile->loadAll(filename, current_scores);	//load highscores
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