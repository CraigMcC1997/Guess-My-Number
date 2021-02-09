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

void HighScores::updateHighscores(int newHighScore, string::size_type sz)
{
    int str_ints[11];   //used for comparing the string values as ints
    int n = sizeof(str_ints) / sizeof(str_ints[0]); //find the size of this array

    for (int i = 0; i < NUM_HIGHSCORES; i++)
        str_ints[i] = std::stoi(highScores[i], &sz);    //convert the array of strings to an array of ints

    str_ints[10] = newHighScore;        //add the score to the position top 10 + 1
    sort(str_ints, str_ints + n);      //sort the new array of 11 intergers

    for (int i = 0; i < NUM_HIGHSCORES; i++)
        highScores[i] = to_string(str_ints[i]);    //convert the ints back to strings

    saveNewScores();    //update the highscores table which will drop the 11th number

    cout << "\n----CONGRADULATIONS YOU MADE IT INTO THE TOP 10----" << endl;
    displayHighscores();                //shows the user the new highscore board
}


void HighScores::compareHighscore(int currentScore)
{
    string::size_type sz;
    int tenthPlace = std::stoi(highScores[NUM_HIGHSCORES - 1], &sz);	//convert string to int
	
    if (currentScore < tenthPlace) //is score in the top 10
    {
        updateHighscores(currentScore, sz);
    }
}

void HighScores::saveNewScores()
{
	handleFile.saveToFile("highscores.txt", highScores, NUM_HIGHSCORES);	//load highscores
}
