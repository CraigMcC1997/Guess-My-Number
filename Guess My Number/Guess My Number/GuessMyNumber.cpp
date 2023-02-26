#include "GuessMyNumber.h"

void GuessMyNumber::init()
{
	/* required by parent class */
	highscores_filename = "../Resources/GuessMyNumber/highscores.txt";
	instructions_filename = "../Resources/GuessMyNumber/instructions.txt";

	highscores = new HighScores(highscores_filename);
	instructions = new Instructions(instructions_filename);
}

/**
 * Display the game menu and allow the player to choose an option.
 *
 */
void GuessMyNumber::menu()
{
	int option;
	cout << "-------------------------------- " << endl;
	cout << "MENU:" << endl;
	cout << "0. Return To Main Menu" << endl;
	cout << "1. Play Game" << endl;
	cout << "2. HighScores" << endl;
	cout << "3. Instructions" << endl;
	cout << "-------------------------------- " << endl;
	cout << "Choice: ";

	if (!(cin >> option))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please input a numberical value between 0 & 3" << endl;;
	}
	else
	{
		switch (option)
		{
		case 0:
			returnToMenu = true; //Return to main menu
			break;
		case 1:
			playGame(); //Play game
			break;
		case 2:
			highscores->displayHighscores(); //display highscore table
			break;
		case 3:
			instructions->displayInstructions();
			break;
		default:
			cout << "please chose a valid option" << endl;
		}
	}
}

/**
 * Pick a random number between 0-100.
 *
 * @return the random number
 */
int GuessMyNumber::randNum()
{
	srand(static_cast<unsigned int>(time(0)));	//seeds the RNG
	return rand() % highestNum + 1;	//random number between 1-100
}

/**
 * Play the selected game until exit has been chosen.
 * Then allow the player to return to the main menu screen
 *
 */
void GuessMyNumber::displayCurrentGameMenu()
{
	do {
		menu();
	} while (!returnToMenu);
}

/**
 * Game has finished, display text to show this.
 * Compare score against highscore tables to see if update is required
 *
 */
void GuessMyNumber::gameOver()
{
	cout << "----GAME OVER!!---- \n";
	cout << "\nRESULTS: \n";
	cout << "Total Guesses Taken: " << overallGuesses << "\n";

	// check if the player made it into the top 10
	highscores->compareHighscore(overallGuesses);

	cout << "\nThanks for playing GUESS MY NUMBER \n\n";
	cout << "-------------------------------- " << endl;
}

/**
 * Game starting point here.
 * Play for MAX_ROUNDS amount of rounds, opening the current round each time
 * When game ends, run gameOver() function.
 */
void GuessMyNumber::playGame()
{
	const int MAX_ROUNDS{ 1 };
	int currentRound{ 1 };
	overallGuesses = 0;	// resetting overall guesses for start of game

	for (int i = 0; i < MAX_ROUNDS; i++)
	{
		cout << "--- ROUND " << currentRound << " --- \n\n";
		this->currentRound();
		currentRound++;
	}

	gameOver();
}

/**
 * The current round for the game.
 * A random number is selected. The player is then tasked with finding this number
 * This is done via guesses, after each guess the game prints out if the player
 * Has guessed too high or two low.
 * Round ends when the player has guessed the number correctly.
 */
void GuessMyNumber::currentRound()
{
	int tries{};
	int guess{};
	int secretNumber{ randNum() };

	cout << "Please chose a number between " << lowestNum << " and " << highestNum << " \n\n";

	do {
		if (tries > 0)
			cout << "Guesses Taken: " << tries << "\n";

		cout << "Enter a guess: ";

		if (!(cin >> guess) || !isValidGuess(guess))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please input a numberical value between " << lowestNum << " and " << highestNum << " \n\n";
			continue;
		}
		else {
			tries++;

			switch (compareGuesses(guess, secretNumber)) {
			case TOO_HIGH:
				cout << "Too high!\n\n";
				break;
			case TOO_LOW:
				cout << "Too low!\n\n";
				break;
			case CORRECT_GUESS:
				cout << "\n YOU GOT IT IN " << tries << " GUESSES \n\n";
				overallGuesses += tries;
				break;
			}
		}
	} while (guess != secretNumber);
}

/**
 * Ensure the player has input a valid guess.
 *
 * @param guess - the players input
 * @return bool value
 */
bool GuessMyNumber::isValidGuess(int guess)
{
	return guess >= lowestNum && guess <= highestNum;
}

/**
 * Check if the players guess is too high or two low.
 *
 * @param guess - the players input
 * @param secretNumber - The number the player is trying to find
 * @return if the player guessed correctly or not
 */
int GuessMyNumber::compareGuesses(int guess, int secretNumber)
{
	if (guess > secretNumber) {
		return TOO_HIGH;
	}
	else if (guess < secretNumber) {
		return TOO_LOW;
	}
	else {
		return CORRECT_GUESS;
	}
}

void GuessMyNumber::patchInstructions()
{
	string* text{ instructions->GetInstructions() };
	int line_count{ instructions->GetInstructionSize() };

	for (int i{ 0 }; i < line_count; i++)
	{
		size_t lowestNumPosition = text[i].find("lowestNum");
		if (lowestNumPosition != std::string::npos) {
			// Replace "old_word" with "new_word"
			text[i].replace(lowestNumPosition, strlen("lowestNum"), to_string(lowestNum));
		}

		size_t highestNumPosition = text[i].find("highestNum");
		if (highestNumPosition != std::string::npos) {
			// Replace "old_word" with "new_word"
			text[i].replace(highestNumPosition, strlen("highestNum"), to_string(highestNum));
		}
	}

	instructions->updateInstructions(text);
}
