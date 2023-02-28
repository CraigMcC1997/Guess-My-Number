#pragma once
#include "AbstractHighscoresHandler.h"

using namespace std;

class GuessNumberHighScores : public AbstractHighscoresHandler
{
private:
	string filename{};
	string current_scores[10];

	struct HighscoreEntry {
		string name{};
		int score{};
		int position{};
	};

	HighscoreEntry highscores[10];

public:
	GuessNumberHighScores(string& filename) : filename{ filename }
	{
		int err = handleFile->loadAll(filename, current_scores);	//load highscores
		if (err != NUM_HIGHSCORES)
		{
			cerr << "Expected loadAll() to return: " << NUM_HIGHSCORES << " instead returned: " << err << endl;
		}
		inputHighscores();
	}

	void compareHighscore(int&);
	void updateHighscores(HighscoreEntry highscores[], const string& name, int score);

	/* required by abstract file */
	void displayHighscores();
	void saveNewScores();
	void inputHighscores();
};