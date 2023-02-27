#include "XandOsHighScores.h"

/**
 * Save scores to text file.
 *
 */
void XandOsHighScores::displayHighscores()
{
	cout << "\nHIGH SCORES: " << endl;
	for (auto& score : highscores)
	{
		cout << score.position << ". ";
		cout << score.name << " - ";
		cout << "Wins: " << score.wins << " | ";
		cout << "Draws: " << score.draws << " | ";
		cout << "Loses: " << score.loses << endl;
	}
}

/**
 * Update the highscore table and save these to the text file.
 *
 * @param highscores is the array of score structs
 * @param name is the players name
 * @param score is the current score after finishing the game
 */
void XandOsHighScores::updateHighscores(HighscoreEntry highscores[], const string& name, int score)
{
	//if (name.empty() || score <= 0) {
	//	std::cerr << "Invalid input: name cannot be empty and score must be greater than zero.\n";
	//	return;
	//}

	//// Add the new score to the highscore table
	//HighscoreEntry new_entry = { name, score };

	////replace the lowest score with the new entry
	//highscores[NUM_HIGHSCORES - 1] = new_entry;

	//// Sort the highscores in descending order
	//sort(highscores, highscores + NUM_HIGHSCORES,
	//	[](const HighscoreEntry& a, const HighscoreEntry& b)
	//	{ return a.score < b.score; });

	//// Update the positions of the entries
	//for (int i = 0; i < NUM_HIGHSCORES; i++)
	//{
	//	highscores[i].position = i + 1;
	//}

	//// Save the new highscores to file
	//saveNewScores();

	//// Print a message to the user
	//cout << "\n----CONGRADULATIONS YOU MADE IT INTO THE TOP 10----" << endl;

	//// Display the updated highscore table
	//displayHighscores();
}

/**
 * Check the players score is within the top 10 scores.
 * If so then update the high scores table if the player
 * inputs their name
 *
 * @param currentScore is the players score after finishing the game
 */
void XandOsHighScores::compareHighscore(int& currentScore)
{
	//string::size_type sz{};
	//int tenthPlace = highscores[NUM_HIGHSCORES - 1].score;

	//if (currentScore < tenthPlace) //is score in the top 10
	//{
	//	string name;
	//	cout << "You made it into the top 10!";
	//	cout << "To save your score please enter your first name: ";
	//	cin >> name;

	//	if (!name.empty() && currentScore > 0)
	//		updateHighscores(highscores, name, currentScore);
	//	else
	//		cout << "score not valid, could not be saved";
	//}
	//else
	//{
	//	cout << "Unfortunately you did not makee it into the top 10!" << endl;
	//	cout << "Try again next time for a chance to join our leaderboard!" << endl;
	//}
}

/**
 * convert scores to strings and update the current scores array with these strings.
 * Then save the updated highscore table to the highscores text file and
 * check return was as expected
 */
void XandOsHighScores::saveNewScores()
{
	for (int i = 0; i < NUM_HIGHSCORES; i++) {
		current_scores[i] = highscores[i].name + ", "
			+ "W=" + to_string(highscores[i].wins)
			+ "D=" + to_string(highscores[i].draws)
			+ "L=" + to_string(highscores[i].loses);
	}

	int err = handleFile->saveToFile(filename, current_scores, NUM_HIGHSCORES);	//load highscores
	if (err != NUM_HIGHSCORES)
	{
		cerr << "Expected saveToFile() to return: " << NUM_HIGHSCORES << "instead returned: " << err << endl;
	}
}

/**
 * Store the highscores from the text file and save in
 * a struct which saves players name, score and position.
 *
 */
void XandOsHighScores::inputHighscores()
{
	int i{};
	string name;
	string wins_str{}, draws_str{}, loses_str{};

	while (i < NUM_HIGHSCORES) {
		// Split the line on the comma to get the name and score
		size_t comma_pos = current_scores[i].find(',');
		size_t wins_pos = current_scores[i].find("W=");
		size_t draws_pos = current_scores[i].find("D=");
		size_t loses_pos = current_scores[i].find("L=");

		if (comma_pos != string::npos) {
			string temp = current_scores[i];
			name = temp.substr(0, comma_pos);
		}
		if (wins_pos != string::npos) {
			string temp = current_scores[i];
			wins_str = temp.substr(wins_pos + 2, 1);
		}
		if (draws_pos != string::npos) {
			string temp = current_scores[i];
			draws_str = temp.substr(draws_pos + 2, 1);
		}
		if (loses_pos != string::npos) {
			string temp = current_scores[i];
			loses_str = temp.substr(loses_pos + 2, 1);
		}
		else
		{
			cerr << "No comma found on line " << i + 1 << " when inputing highscores from file" << endl;
		}

		highscores[i].position = i + 1;
		highscores[i].name = name;
		highscores[i].wins = stoi(wins_str);
		highscores[i].draws = stoi(draws_str);
		highscores[i].loses = stoi(loses_str);

		i++;
	}
}
