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

	SDL_Surface* image = SDL_LoadBMP("door.bmp");
	if (image == nullptr) {
		cout << "Failed to load door.bmp. SDL error: " << SDL_GetError() << endl;
	}

	SDL_Surface* windowSurface = SDL_GetWindowSurface(sdlWindow);
	if (windowSurface == nullptr) {
		cout << "Failed to get window surface. SDL error: " << SDL_GetError() << endl;
	}

	SDL_Rect destinationRect{ 25, 25, 16, 16 };
	SDL_BlitSurface(image, NULL, windowSurface, &destinationRect);


	SDL_UpdateWindowSurface(sdlWindow);

	// pauses console.
	getchar();

	SDL_FreeSurface(image);
	SDL_DestroyWindow(sdlWindow);
	SDL_Quit();

	return 0;
}