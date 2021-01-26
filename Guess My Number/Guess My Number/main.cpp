#include "Game.h"

using namespace std;

Game* game;

void init()
{
	game = new Game();
}

int main(int arc, char* argv)
{
	game->playGame();

	return 0;
}