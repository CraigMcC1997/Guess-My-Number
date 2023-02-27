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
void XandOsHighScores::updateHighscores(const string& name, const char score_type)
{
	if (name.empty()) {


		cerr << "Invalid input: name cannot be empty.\n";
		return;
	}

	/* todo: check name, add new entry if doesn't exist, else update existing */
	/* todo: check type, if new entry add, else update existing */
	bool scorePreviouslySaved = false;
	int count{};
	do
	{
		if (highscores[count].name == name)
		{
			scorePreviouslySaved = true;
			break;
		}

		count++;
	} while (!scorePreviouslySaved && count < NUM_HIGHSCORES);

	/* update exisiting highscores */
	if (scorePreviouslySaved)
	{
		increaseSpecificScore(highscores[count], score_type);
	}
	else /* add new score */
	{
		HighscoreEntry new_entry = { name, NULL, 0, 0, 0 };

		increaseSpecificScore(new_entry, score_type);

		// Add the new score to the highscore table
		highscores[NUM_HIGHSCORES - 1] = new_entry; //replace the lowest score with the new entry

		// Sort the highscores in descending order
		sort(highscores, highscores + NUM_HIGHSCORES,
			[](const HighscoreEntry& a, const HighscoreEntry& b)
			{ return a.loses > b.loses; });

		sort(highscores, highscores + NUM_HIGHSCORES,
			[](const HighscoreEntry& a, const HighscoreEntry& b)
			{ return a.draws < b.draws; });

		sort(highscores, highscores + NUM_HIGHSCORES,
			[](const HighscoreEntry& a, const HighscoreEntry& b)
			{ return a.wins < b.wins; });

		// Update the positions of the entries
		for (int i = 0; i < NUM_HIGHSCORES; i++)
		{
			highscores[i].position = i + 1;
		}
	}

	// Save the new highscores to file
	saveNewScores();

	// Print a message to the user
	cout << "\n----CONGRATULATIONS YOU MADE IT INTO THE TOP 10----" << endl;

	// Display the updated highscore table
	displayHighscores();
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
			+ " D=" + to_string(highscores[i].draws)
			+ " L=" + to_string(highscores[i].loses);
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

void XandOsHighScores::increaseSpecificScore(HighscoreEntry& entry, const char score_type)
{
	if (score_type == 'W')
		entry.wins++;
	else if (score_type == 'D')
		entry.draws++;
	else if (score_type == 'L')
		entry.loses++;
}