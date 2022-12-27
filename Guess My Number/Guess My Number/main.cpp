#include "Game.h"

#if _DEBUG
#pragma comment(linker, "/subsystem:\"console\" /entry:\"WinMainCRTStartup\"")
#endif

using namespace std;

Game* game;
SDL_Event sdlEvent;  // variable to detect SDL events

void init()
{
	cout << "----Welcome to GUESS MY NUMBER---- \n\n";
	game = new Game();
}

int main(int arc, char* argv[])
{
	init();

	bool running = true;
	while (running) {	// the event loop
		while (SDL_PollEvent(&sdlEvent)) {
			if (sdlEvent.type == SDL_QUIT)
				running = false;
		}
		game->playGame();
	}

	delete game;
	SDL_Quit();
	return 0;
}