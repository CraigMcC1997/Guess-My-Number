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


void HighScores::compareHighscore(int currentScore)
{
    string::size_type sz;
    int str_ints[11];
    int n = sizeof(highScores) / sizeof(highScores[0]);
    int n2 = sizeof(str_ints) / sizeof(str_ints[0]);
   

    int tenthPlace = std::stoi(highScores[NUM_HIGHSCORES - 1], &sz);	//convert string to int
	
    if (currentScore < tenthPlace) //is score in the top 10
    {
        for (int i = 0; i < NUM_HIGHSCORES ; i++)
            str_ints[i] = std::stoi(highScores[i], &sz);    //convert the array of strings to an array of ints

        str_ints[10] = currentScore;        //add the score to the position top 10 + 1
        sort(str_ints, str_ints + n2);      //sort the new array of 11 intergers
        
        for (int i = 0; i < NUM_HIGHSCORES; i++)
            highScores[i] = to_string(str_ints[i]);    //convert the ints back to strings
                           
        saveNewScores();                    //update the highscores table which will drop the 11th number
    }
}



void HighScores::saveNewScores()
{
	handleFile.saveToFile("highscores.txt", highScores, NUM_HIGHSCORES);	//load highscores
}
