#pragma once
#include <string>
#include <fstream>

using namespace std;

class HandleFile
{
private:

public:
	fstream& GotoLine(fstream& file, unsigned int num);
	void loadAll(string fileName, string array[], int size);
	void saveToFile(string fileName, string array[], int size);
};