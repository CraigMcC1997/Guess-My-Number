#include "Game.h"

int Game::randNum()
{
	srand(static_cast<unsigned int>(time(0)));	//seeds the RNG
	return rand() % highestNum + 1;	//random number between 1-100
}

void Game::playGame()
{
	int tries = 0;
	int guess = 0;
	int secretNumber = 0;

	cout << "Welcome to GUESS MY NUMBER \n";
	cout << "Please chose a number between " << lowestNum << " and " << highestNum <<" \n\n";

	secretNumber = randNum();

	do {
		if(tries > 0)
			cout << "Guesses Taken: " << tries << "\n";

		cout << "Enter a guess: ";
		cin >> guess;
		tries++;

		if(guess > (highestNum -1))
			cout << "Please chose a number between " << lowestNum << " and " << highestNum << " \n\n";
		else if (guess > secretNumber)
			cout << "Too high!\n\n";
		else if (guess < secretNumber)
			cout << "Too low!\n\n";
		else
			cout << "\n YOU GOT IT IN " << tries << " GUESSES";

	} while (guess != secretNumber);
}