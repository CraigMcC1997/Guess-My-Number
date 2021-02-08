#include "HighScores.h"

void HighScores::displayHighscores()
{
	loadFile.loadAll("highscores.txt", highScores, MAX_HIGHSCORE);	//load highscores

	cout << "\nHIGH SCORES: " << endl;
	for (int i = 0; i < MAX_HIGHSCORE; i++)
	{
		cout << i + 1 << ". ";
		cout << highScores[i] << endl;
	}
}