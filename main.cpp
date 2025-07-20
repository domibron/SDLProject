#include <iostream>
#include "SDL.h"

using namespace std;

int main(int argc, char* argv[]) {

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Failed to initialise SDL. SDL error: " << SDL_GetError() << endl;
	}

	SDL_Window* sdlWindow = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, NULL);

	if (sdlWindow == nullptr) {
		cout << "Failed to create window. SDL error: " << SDL_GetError() << endl;
	}

	getchar();

	SDL_DestroyWindow(sdlWindow);
	SDL_Quit();

	return 0;
}