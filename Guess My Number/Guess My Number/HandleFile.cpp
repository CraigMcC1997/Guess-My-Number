#include "HandleFile.h"

//VERY SIMPLE, CAN BE UPDATED FOR ERROR CHECKING
int HandleFile::loadAll(const string& fileName, string file_lines[])
{
	ifstream inFile(fileName);

	if (!inFile.is_open()) {
		cerr << "Failed to open file: " << fileName << endl;
		return 0;
	}

	int line_count = 0;
	string line;

	while (getline(inFile, line)) {
		file_lines[line_count] = line;
		line_count++;
	}

	inFile.close();
	return line_count;
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
