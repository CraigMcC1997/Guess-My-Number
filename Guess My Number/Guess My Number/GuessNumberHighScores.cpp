#include "GuessNumberHighScores.h"

/**
 * Save scores to text file.
 *
 */
void GuessNumberHighScores::displayHighscores()
{
	cout << "\nHIGH SCORES: " << endl;
	for (auto& score : highscores)
	{
		cout << score.position << ". ";
		cout << score.name << " - ";
		cout << score.score << endl;
	}
}

/**
 * Update the highscore table and save these to the text file.
 *
 * @param highscores is the array of score structs
 * @param name is the players name
 * @param score is the current score after finishing the game
 */
void GuessNumberHighScores::updateHighscores(HighscoreEntry highscores[], const string& name, int score)
{
	if (name.empty() || score <= 0) {
		std::cerr << "Invalid input: name cannot be empty and score must be greater than zero.\n";
		return;
	}

	// Add the new score to the highscore table
	HighscoreEntry new_entry = { name, score };

	//replace the lowest score with the new entry
	highscores[NUM_HIGHSCORES - 1] = new_entry;

	// Sort the highscores in descending order
	sort(highscores, highscores + NUM_HIGHSCORES,
		[](const HighscoreEntry& a, const HighscoreEntry& b)
		{ return a.score < b.score; });

	// Update the positions of the entries
	for (int i = 0; i < NUM_HIGHSCORES; i++)
	{
		highscores[i].position = i + 1;
	}

	// Save the new highscores to file
	saveNewScores();

	// Print a message to the user
	cout << "\n----CONGRADULATIONS YOU MADE IT INTO THE TOP 10----" << endl;

	// Display the updated highscore table
	displayHighscores();
}

/**
 * Check the players score is within the top 10 scores.
 * If so then update the high scores table if the player
 * inputs their name
 *
 * @param currentScore is the players score after finishing the game
 */
void GuessNumberHighScores::compareHighscore(int& currentScore)
{
	string::size_type sz{};
	int tenthPlace = highscores[NUM_HIGHSCORES - 1].score;

	if (currentScore < tenthPlace) //is score in the top 10
	{
		string name;
		cout << "You made it into the top 10!";
		cout << "To save your score please enter your first name: ";
		cin >> name;

		if (!name.empty() && currentScore > 0)
			updateHighscores(highscores, name, currentScore);
		else
			cout << "score not valid, could not be saved";
	}
	else
	{
		cout << "Unfortunately you did not makee it into the top 10!" << endl;
		cout << "Try again next time for a chance to join our leaderboard!" << endl;
	}
}

/**
 * convert scores to strings and update the current scores array with these strings.
 * Then save the updated highscore table to the highscores text file and
 * check return was as expected
 */
void GuessNumberHighScores::saveNewScores()
{
	for (int i = 0; i < NUM_HIGHSCORES; i++) {
		current_scores[i] = highscores[i].name + ", " + to_string(highscores[i].score);
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
void GuessNumberHighScores::inputHighscores()
{
	int i{};
	string name;
	string score_str;

	while (i < NUM_HIGHSCORES) {
		// Split the line on the comma to get the name and score
		size_t comma_pos = current_scores[i].find(',');

		if (comma_pos != string::npos) {
			name = current_scores[i].substr(0, comma_pos);
			score_str = current_scores[i].substr(comma_pos + 1);
		}
		else
		{
			cerr << "No comma found on line " << i + 1 << " when inputing highscores from file" << endl;
		}

		highscores[i].position = i + 1;
		highscores[i].name = name;
		highscores[i].score = stoi(score_str);

		i++;
	}
}
