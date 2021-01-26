#include <iostream>
#include <ctime>

using namespace std;

int randNum()
{
	int num;

	srand(static_cast<unsigned int>(time(0)));	//seeds the RNG

	return num = rand() % 101;	//random number between 1-100
}

void game(int secretNumber)
{
	int tries = 0;
	int guess;

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
}

int main(int arc, char* argv)
{
	int secretNumber = 0;

	cout << "Welcome to GUESS MY NUMBER \n\n";

	secretNumber = randNum();
	game(secretNumber);

	return 0;
}