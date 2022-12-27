#include "HandleFile.h"

//VERY SIMPLE, CAN BE UPDATED FOR ERROR CHECKING
int HandleFile::loadAll(const string& fileName, string scores[])
{
	ifstream inFile(fileName);

	if (!inFile.is_open()) {
		cerr << "Failed to open file: " << fileName << endl;
		return 0;
	}

	int count = 0;
	string line;

	while (getline(inFile, line)) {
		scores[count] = line;
		count++;
	}

	inFile.close();
	return count;
}

int HandleFile::saveToFile(const string& fileName, string scores[], int size)
{
	ofstream outFile(fileName);

	if (!outFile.is_open()) {
		cerr << "Failed to open file: " << fileName << endl;
		return 0;
	}

	int count = 0;
	while (count < size)
	{
		outFile << scores[count] << endl;
		count++;
	}

	outFile.close();
	return count;
}
