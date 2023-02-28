#pragma once
#include "AbstractHighscoresHandler.h"

/* TODO: Update formatting for high scores output */
/* TODO: Re-enable updating highscores based on game wins*/
/* TODO: Highscores ranking: most wins, most draws, least loses */

using namespace std;

class XandOsHighScores : public AbstractHighscoresHandler
{
private:
	string filename{};
	string current_scores[10];

	struct HighscoreEntry {
		string name{};
		int position{};
		int wins{};
		int draws{};
		int loses{};
	};

	HighscoreEntry highscores[10];

	/* private functions */
	void increaseSpecificScore(HighscoreEntry& entry, const char score_type);

public:
	XandOsHighScores(string& filename) : filename{ filename }
	{
		int err = handleFile->loadAll(filename, current_scores);	//load highscores
		if (err != NUM_HIGHSCORES)
		{
			cerr << "Expected loadAll() to return: " << NUM_HIGHSCORES << " instead returned: " << err << endl;
		}
		inputHighscores();
	}

	void displayHighscores();
	void updateHighscores(const string& name, const char type);
	void saveNewScores();
	void inputHighscores();
};