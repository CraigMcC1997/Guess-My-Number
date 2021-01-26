#include <iostream>
#include <ctime>

using namespace std;

int main(int arc, char* argv)
{
	srand(static_cast<unsigned int>(time(0)));	//seeds the RNG

	int secretNumber = rand() % 101;	//random number between 1-100
	int tries = 0;
	int guess;

	cout << "Welcome to GUESS MY NUMBER \n\n";

	do {
		cout << "Enter a guess: ";
		cin >> guess;
		++tries;

		if (guess > secretNumber)
			cout << "Too high!\n\n";
		else if (guess < secretNumber)
			cout << "Too low!\n\n";
		else
			cout << "\n YOU GOT IT IN " << tries << " GUESSES";

	} while (guess != secretNumber);

	return 0;
}