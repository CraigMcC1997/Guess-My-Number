#include "GameSelection.h"

void GameSelection::GameSelectorMenu()
{
	int option;
	cout << "-------------------------------- " << endl;
	cout << "MENU:" << endl;
	cout << "0. Exit" << endl;
	cout << "1. Play Guess My Number Game" << endl;

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
			guessNumberGame->displayCurrentGameMenu(); //Play game
			break;
		default:
			cout << "please chose a valid option" << endl;
		}
	}
}

void GameSelection::DisplayGamesMenu()
{
	GameSelectorMenu();
}
