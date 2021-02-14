#pragma once
#include <string>
#include <fstream>

using namespace std;

class HandleFile
{
private:

public:
	void loadAll(string fileName, string array[], int size);
	void saveToFile(string fileName, string array[], int size);
};