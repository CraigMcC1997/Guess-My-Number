#pragma once
#include <iostream>
#include <ctime>
#include <limits>
#include <SDL.h>
#include <glew.h>

#include "AbstractGame.h"
#include "XandOsHighScores.h"

using namespace std;

class XandOGame : public AbstractGame
{
private:
	XandOsHighScores* highscores;

	string gameBoard[9]{};
	const string GAME_BOARD_START_STATE[9]{ "1","2","3","4","5","6","7","8","9" };

	bool GAME_OVER{ false };

	struct Player {
		string name{};
		string icon{};
	};

	Player player1{};
	Player player2{};
	Player winner{};
	Player loser{};

	/* game specific functions */
	void getPlayersNextMove(string player, int round);
	void printGameBoard();
	void playersChoseIcon();
	void resetGameBoard();

	bool checkForWinner(int current_round);
	bool checkHorizontal(string checkValue);
	bool checkVertical(string checkValue);
	bool checkDiagonal(string checkValue);

public:
	XandOGame()
	{
		init();
		patchInstructions();
	}

	/* required by parent class */
	void init();
	void menu();
	void playGame();
	void gameOver();
	void gameOver(int round_count);
	void patchInstructions();
	void displayCurrentGameMenu();
};
