#pragma once
#include <iostream>
#include <algorithm>
#include "File_Handler.h"

class AbstractHighscoresHandler {
protected:
	HandleFile* handleFile{ new HandleFile() };
	const int NUM_HIGHSCORES{ 10 };
public:
	virtual void displayHighscores() = 0;
	virtual void compareHighscore(int&) = 0;
	virtual void saveNewScores() = 0;
	virtual void inputHighscores() = 0;
};
