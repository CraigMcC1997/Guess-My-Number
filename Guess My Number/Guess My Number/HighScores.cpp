#include "HighScores.h"

void HighScores::displayHighscores()
{
	cout << "\nHIGH SCORES: " << endl;
	for (int i = 0; i < NUM_HIGHSCORES; i++)
	{
		cout << i + 1 << ". ";
		cout << highScores[i] << endl;
	}
}

/**
 * updateHighscores() takes the new highscore and the size of the value as a string.
 * The array of highscores are then converted to ints. The new score is then added to the end
 * of the array and sorted into descending order. The scores are then converted back to strings.
 * Then the highscores file is updated by calling saveNewScores()
 *
 * @param newHighScore
 * @param sz
 */
void HighScores::updateHighscores(int newHighScore, string::size_type& sz)
{
	int str_ints[11];   //used for comparing the string values as ints
	int n = sizeof(str_ints) / sizeof(str_ints[0]); //find the size of this array

	for (int i = 0; i < NUM_HIGHSCORES; i++)
		str_ints[i] = stoi(highScores[i], &sz);    //convert the array of strings to an array of ints

	str_ints[10] = newHighScore;        //add the score to the position top 10 + 1
	sort(str_ints, str_ints + n);      //sort the new array of 11 intergers

	for (int i = 0; i < NUM_HIGHSCORES; i++)
		highScores[i] = to_string(str_ints[i]);    //convert the ints back to strings

	saveNewScores();    //update the highscores table which will drop the 11th number

	cout << "\n----CONGRADULATIONS YOU MADE IT INTO THE TOP 10----" << endl;
	displayHighscores();                //shows the user the new highscore board
}


void HighScores::compareHighscore(int& currentScore)
{
	string::size_type sz;
	int tenthPlace = stoi(highScores[NUM_HIGHSCORES - 1], &sz);	//convert string to int

	if (currentScore < tenthPlace) //is score in the top 10
	{
		updateHighscores(currentScore, sz);
	}
}

void HighScores::saveNewScores()
{
	int err = handleFile.saveToFile(filename, highScores, NUM_HIGHSCORES);	//load highscores

	if (err != NUM_HIGHSCORES)
	{
		cerr << "Expected saveToFile() to return: " << NUM_HIGHSCORES << "instead returned: " << err << endl;
	}
}
