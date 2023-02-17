#pragma once
#include <iostream>
#include <algorithm>
#include <cstdarg>

#include "File_Handler.h"

using namespace std;

class Instructions
{
private:
	HandleFile* handleFile{ new HandleFile() };
	string filename{};
	string instructions[10];
	int instuction_line_count{};

public:
	Instructions(string filename) : filename{ filename }
	{
		instuction_line_count = handleFile->loadAll(filename, instructions);	//load highscores
	}

	int GetInstructionSize();
	string* GetInstructions();
	void displayInstructions();
	void updateInstructions(string* updated_text);
};