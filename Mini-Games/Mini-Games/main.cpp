#include "GameSelection.h"

#if _DEBUG
#pragma comment(linker, "/subsystem:\"console\" /entry:\"WinMainCRTStartup\"")
#endif

using namespace std;

GameSelection* gameSelector;
SDL_Event sdlEvent;  // variable to detect SDL events

void init()
{
	gameSelector = new GameSelection();
}

int main(int arc, char* argv[])
{
	init();

	bool running{ true };
	while (running) {	// the event loop
		while (SDL_PollEvent(&sdlEvent)) {
			if (sdlEvent.type == SDL_QUIT)
				running = false;
		}
		gameSelector->DisplayGamesMenu();
	}

	delete gameSelector;
	SDL_Quit();
	return 0;
}