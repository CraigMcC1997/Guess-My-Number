#include "Game.h"
#include "Window.h"

#if _DEBUG
#pragma comment(linker, "/subsystem:\"console\" /entry:\"WinMainCRTStartup\"")
#endif

using namespace std;

Game* game;
Window* window;

SDL_Renderer* renderTarget = nullptr;
SDL_GLContext glContext; // OpenGL context handle
SDL_Event sdlEvent;  // variable to detect SDL events

void init()
{
	//window = new Window(1200, 800, "Guess My Number");
	//window->setupRC(glContext);

	game = new Game();
}

void draw(SDL_Window* window)
{
	//glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	game->draw(window);
}

int main(int arc, char* argv[])
{
	init();
	
	//renderTarget = nullptr;
	//renderTarget = SDL_CreateRenderer(window->getWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//// Required on Windows *only* init GLEW to access OpenGL beyond 1.1
	//glewExperimental = GL_TRUE;
	//GLenum err = glewInit();
	//if (GLEW_OK != err) { // glewInit failed, something is seriously wrong
	//	std::cout << "glewInit failed, aborting." << endl;
	//	exit(1);
	//}
	//cout << glGetString(GL_VERSION) << endl;
	

	bool running = true;
	while (running) {	// the event loop
		while (SDL_PollEvent(&sdlEvent)) {
			if (sdlEvent.type == SDL_QUIT)
				running = false;
		}

		//update(sdlEvent);
		//draw(window->getWindow());
		game->playGame();
	}

	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window->getWindow());
	delete game;
	SDL_Quit();
	return 0;
}