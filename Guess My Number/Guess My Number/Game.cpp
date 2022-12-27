#include "Game.h"

void Game::menu()
{
	int option;
	cout << "-------------------------------- " << endl;
	cout << "MENU:" << endl;
	cout << "0. Exit" << endl;
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
			exit(0); //close game window
			break;
		case 1:
			changeRounds(); //Play game
			break;
		case 2:
			highscores.displayHighscores(); //display highscore table
			break;
		case 3:
			displayInstructions();
			break;
			/*case 4:
					highscores.compareHighscore(51);*/
		default:
			cout << "please chose a valid option" << endl;
		}
	}
}

void Game::displayInstructions()
{
	cout << "Chose a number between " << lowestNum << " & " << highestNum << endl;
	cout << "Until the randomly generated number is found." << endl;
	cout << "The game will run for 3 rounds. Each guess adding to your score" << endl;
	cout << "At the end of the three rounds the game will end." << endl;
	cout << "The less guesses it takes to find the 3 numbers" << endl;
	cout << "The higher up the leaderboard you will be. Good luck!" << endl;
}

int Game::randNum()
{
	srand(static_cast<unsigned int>(time(0)));	//seeds the RNG
	return rand() % highestNum + 1;	//random number between 1-100
}

void Game::playGame()
{
	menu();
}

void Game::gameOver()
{
	cout << "----GAME OVER!!---- \n";
	cout << "\nRESULTS: \n";
	cout << "Total Guesses Taken: " << overallGuesses << "\n";

	// check if the player made it into the top 10
	// put a check here if the player made it into the top 10 and display this to the user, i.e score, position and
	// overall table
	highscores.compareHighscore(overallGuesses);

	overallGuesses = 0;	// resetting overall guesses for the next game

	cout << "\nThanks for playing GUESS MY NUMBER \n\n";
	cout << "-------------------------------- " << endl;
}

void Game::changeRounds()
{
	const int MAX_ROUNDS = 1;
	int currentRound = 1;

	for (int i = 0; i < MAX_ROUNDS; i++)
	{
		cout << "--- ROUND " << currentRound << " --- \n\n";
		this->currentRound();
		currentRound++;
	}

	gameOver();
}

void Game::currentRound()
{
	int tries = 0;
	int guess;
	int secretNumber = randNum();

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
			case 1:
				cout << "Too high!\n\n";
				break;
			case -1:
				cout << "Too low!\n\n";
				break;
			case 0:
				cout << "\n YOU GOT IT IN " << tries << " GUESSES \n\n";
				overallGuesses += tries;
				break;
			}
		}
	} while (guess != secretNumber);
}

bool Game::isValidGuess(int guess)
{
	return guess >= lowestNum && guess <= highestNum;
}

int Game::compareGuesses(int guess, int secretNumber)
{
	if (guess > secretNumber) {
		return 1;
	}
	else if (guess < secretNumber) {
		return -1;
	}
	else {
		return 0;
	}
}
