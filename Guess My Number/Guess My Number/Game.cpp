#include "Game.h"

void Game::menu()
{
	int option;

	cout << "MENU:" << endl;
	cout << "1. " << "Play Game" << endl;
	cout << "2. " << "HighScores" << endl;
	cout << "3. " << "Exit" << endl;
	cout << "Choice: ";

	cin >> option;

	switch (option)
	{
	case 1:
		changeRounds(); //Play game
		break;
	case 2:	
		highscores.displayHighscores();
		break;	
	case 3:
		exit(0); //close game window
		break;
	default:
		cout << "please chose a valid option" << endl;
	}
}

int Game::randNum()
{
	srand(static_cast<unsigned int>(time(0)));	//seeds the RNG
	return rand() % highestNum + 1;	//random number between 1-100
}

void Game::playGame()
{
	cout << "----Welcome to GUESS MY NUMBER---- \n\n";
	menu();
}

void Game::gameOver()
{
	cout << "----GAME OVER!!---- \n";
	cout << "\nRESULTS: \n";
	cout << "Total Guesses Taken: " << overallGuesses << "\n";

	highscores.compareHighscore(overallGuesses);	//check if the player made it into the top 10
	//put a check here if the player made it into the top 10 and display this to the user, i.e score, position and
	//overall table

	cout << "\nThanks for playing GUESS MY NUMBER \n\n";
	cout << "---------------------------------------------- \n\n";
}

void Game::changeRounds()
{
	const int MAX_ROUNDS = 2;
	int currentRound = 1;

	for (int i = 0; i < MAX_ROUNDS; i++)
	{
		cout << "--- ROUND " << currentRound << " --- \n\n";
		this->currentRound();
		currentRound++;
	}

	//display text to show the game has reached its conclusion
	gameOver();
}

void Game::currentRound()
{
	int tries = 0;
	int guess;
	int secretNumber = 0;

	cout << "Please chose a number between " << lowestNum << " and " << highestNum << " \n\n";

	secretNumber = randNum();

	do {
		if (tries > 0)
			cout << "Guesses Taken: " << tries << "\n";

		cout << "Enter a guess: ";
		
		cin >> guess;
		
		//error checking
		//confirms input is in fact a numberical input
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please input a number ONLY \n\n";
		}
		else {
			tries++;

			if (guess > (highestNum))
				cout << "Please chose a number between " << lowestNum << " and " << highestNum << " \n\n";
			else if (guess > secretNumber)
				cout << "Too high!\n\n";
			else if (guess < secretNumber)
				cout << "Too low!\n\n";
			else
			{
				cout << "\n YOU GOT IT IN " << tries << " GUESSES \n\n";
				overallGuesses += tries;
			}
		}
	} while (guess != secretNumber);
}

void Game::draw(SDL_Window* window)
{
	// clear the screen
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//do game here

	SDL_GL_SwapWindow(window); // swap buffers
}