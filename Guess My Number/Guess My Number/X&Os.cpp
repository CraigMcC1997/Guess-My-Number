#include "X&Os.h"

/* TODO: Update function comments */
/* TODO: Check player doesn't chose previously chosen section */
/* TODO: Check if player has won */
/* TODO: Improve error checking */

void XandOGame::init()
{
	/* required by parent class */
	highscores_filename = "../Resources/X&Os/highscores.txt";
	instructions_filename = "../Resources/X&Os/instructions.txt";

	//highscores = new HighScores(highscores_filename);
	instructions = new Instructions(instructions_filename);
}

/**
 * Display the game menu and allow the player to choose an option.
 */
void XandOGame::menu()
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
			cout << "Highscores currently disabled for X&Os game" << endl;
			//highscores->displayHighscores(); //display highscore table
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
 * Play the selected game until exit has been chosen.
 * Then allow the player to return to the main menu screen
 *
 */
void XandOGame::displayCurrentGameMenu()
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
void XandOGame::gameOver()
{
	cout << "----GAME OVER!!---- \n";
	cout << "\nRESULTS: \n";
	/* TODO: print winner here */
	cout << "The winner was " << winner << endl;

	// check if the player made it into the top 10
	//highscores->compareHighscore(overallGuesses);

	cout << "\nThanks for playing X & O's \n\n";
	cout << "-------------------------------- " << endl;
}

/**
 * Game starting point here.
 * Play for MAX_ROUNDS amount of rounds, opening the current round each time
 * When game ends, run gameOver() function.
 */
void XandOGame::playGame()
{
	const int MAX_ROUNDS{ 9 };
	int currentRound{ 1 };
	GAME_OVER = false; /* resetting in case multiple games played */

	playersChoseIcon();

	for (int i = 0; i < MAX_ROUNDS; i++)
	{
		system("cls"); /* clear the screen to improve readability */
		printGameBoard(); /* display the current board state */

		/** early exit if someone won */
		if (GAME_OVER)
			break;

		/** current player choses game tile on board */
		if (i % 2 == 0)
			getPlayersNextMove(Player1, i);
		else
			getPlayersNextMove(Player2, i);

		/* TODO: check if anyone has won yet */
		if (i >= 4) /* can't have a winner before round 5 */
		{
			if (checkForWinner(i))
			{
				if (i % 2 == 0)
					winner = Player1;
				else
					winner = Player2;

				cout << "We have a winner!!!" << endl;
				GAME_OVER = true;
			}
		}

		currentRound++;
	}

	/* TODO: Enable this after game is ready */

	gameOver();
}

/**
 * The current round for the game.
 * A random number is selected. The player is then tasked with finding this number
 * This is done via guesses, after each guess the game prints out if the player
 * Has guessed too high or two low.
 * Round ends when the player has guessed the number correctly.
 */
void XandOGame::getPlayersNextMove(string player, int round)
{
	int option{};

	int current_player{};
	if (round % 2 == 0)
		current_player = 1;
	else
		current_player = 2;

	cout << "Player " << current_player << " please choose a numbered section : ";
	cin >> option;

	gameBoard[option - 1] = player;
}

void XandOGame::printGameBoard()
{
	string breaker{ " | " };
	cout << "  " << gameBoard[0] << breaker << gameBoard[1] << breaker << gameBoard[2] << endl;
	cout << "----|---|----\n";
	cout << "  " << gameBoard[3] << breaker << gameBoard[4] << breaker << gameBoard[5] << endl;
	cout << "----|---|----\n";
	cout << "  " << gameBoard[6] << breaker << gameBoard[7] << breaker << gameBoard[8] << endl;
}

void XandOGame::playersChoseIcon()
{
	/* TODO: add error checking */
	cout << "Player 1 chose X or O:" << endl;
	cin >> Player1;

	/* TODO: make ternary */
	if (Player1 == "X" || Player1 == "x")
	{
		Player1 = "X";
		Player2 = "O";
	}

	else
	{
		Player1 = "O";
		Player2 = "X";
	}

}

/** Not required for this game */
void XandOGame::patchInstructions()
{
	return;
}

/**
 * Check for all possible options for winner.
 *
 * @return
 */
bool XandOGame::checkForWinner(int current_round)
{
	string player{};
	if (current_round % 2 == 0) /* player 1 round */
		player = Player1;
	else						/* player 2 round */
		player = Player2;

	if (checkHorizontal(player) || checkVertical(player) || checkDiagonal(player))
		return true;
	else
		return false;
}

bool XandOGame::checkHorizontal(string checkValue)
{
	bool winner = false;
	if (gameBoard[0] == checkValue && gameBoard[1] == checkValue && gameBoard[2] == checkValue)
		winner = true;
	if (gameBoard[3] == checkValue && gameBoard[4] == checkValue && gameBoard[5] == checkValue)
		winner = true;
	if (gameBoard[6] == checkValue && gameBoard[7] == checkValue && gameBoard[8] == checkValue)
		winner = true;

	return winner;
}

bool XandOGame::checkVertical(string checkValue)
{
	bool winner = false;

	if (gameBoard[0] == checkValue && gameBoard[3] == checkValue && gameBoard[6] == checkValue)
		winner = true;
	if (gameBoard[1] == checkValue && gameBoard[4] == checkValue && gameBoard[7] == checkValue)
		winner = true;
	if (gameBoard[2] == checkValue && gameBoard[5] == checkValue && gameBoard[8] == checkValue)
		winner = true;

	return winner;
}

bool XandOGame::checkDiagonal(string checkValue)
{
	bool winner = false;

	if (gameBoard[0] == checkValue && gameBoard[4] == checkValue && gameBoard[8] == checkValue)
		winner = true;
	if (gameBoard[6] == checkValue && gameBoard[4] == checkValue && gameBoard[2] == checkValue)
		winner = true;

	return winner;
}
