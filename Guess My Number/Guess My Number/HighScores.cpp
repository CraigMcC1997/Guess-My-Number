#include "HighScores.h"

void HighScores::displayHighscores()
{
	cout << "\nHIGH SCORES: " << endl;
	for (int i = 0; i < MAX_HIGHSCORE; i++)
	{
		cout << i + 1 << ". ";
		cout << highScores[i] << endl;
	}
}

void HighScores::compareHighscore(int currentScore)
{
	string::size_type sz;
	int counter = 9;

	do {
		int str_int = std::stoi(highScores[counter], &sz);	//convert string to int
		if (currentScore < str_int)
		{
			int str_int2 = std::stoi(highScores[counter-1], &sz);	//convert string to int
			if(currentScore < str_int2)
				counter--;
			else
			{
				highScores[counter] = to_string(currentScore);
				return;
			}
		}			
	} while (counter > 0);
}
