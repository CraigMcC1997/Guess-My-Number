#include "LoadFromFile.h"

fstream& LoadFromFile::GotoLine(fstream& file, unsigned int num) {
	file.seekg(ios::beg);
	for (int i = 0; i < num; ++i) {
		file.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return file;
}

//VERY SIMPLE, CAN BE UPDATED FOR ERROR CHECKING
void LoadFromFile::loadAll(string fileName, string array[], int size)
{
	string currentLine;
	int count = 0;

	while (count < size)
	{
		fstream file(fileName);
		GotoLine(file, count);
		file >> currentLine;
		array[count] = currentLine;
		count++;
	}
}
