#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class HandleFile
{
private:

public:
	int loadAll(const string& fileName, string scores[]);
	int saveToFile(const string& fileName, string scores[], int size);
};