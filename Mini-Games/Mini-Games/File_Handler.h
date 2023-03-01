#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class HandleFile
{
public:
	int loadAll(const string& fileName, string file_lines[]);
	int saveToFile(const string& fileName, string scores[], int size);
};