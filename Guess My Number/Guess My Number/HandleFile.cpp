#include "HandleFile.h"

fstream& HandleFile::GotoLine(fstream& file, unsigned int num) {
	file.seekg(ios::beg);
	for (int i = 0; i < num; ++i) {
		file.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return file;
}

//VERY SIMPLE, CAN BE UPDATED FOR ERROR CHECKING
void HandleFile::loadAll(string fileName, string array[], int size)
{
	ifstream inFile(fileName);
	int count = 0;

	while (count < size)
	{
		inFile >> array[count];
		count++;
	}
	inFile.close();
}

void HandleFile::saveToFile(string fileName, string array[], int size)
{
	ofstream outFile(fileName);
	int count = 0;

	while (count < size)
	{
		outFile << array[count] << endl;
		count++;
	}
	outFile.close();
}
