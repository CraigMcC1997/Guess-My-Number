#include "Game.h"

int Game::randNum()
{
	srand(static_cast<unsigned int>(time(0)));	//seeds the RNG
	return rand() % 101;	//random number between 1-100
}

void Game::playGame()
{
	int tries = 0;
	int guess = 0;
	int secretNumber = 0;

	cout << "Welcome to GUESS MY NUMBER \n\n";

	secretNumber = randNum();

	do {
		cout << "Enter a guess: ";
		cin >> guess;
		++tries;

		if (guess > secretNumber)
			cout << "Too high!\n\n";
		else if (guess < secretNumber)
			cout << "Too low!\n\n";
		else
			cout << "\n YOU GOT IT IN " << tries << " GUESSES";

	} while (guess != secretNumber);
}