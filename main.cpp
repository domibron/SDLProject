#include <iostream>
#include "SDL.h"

using namespace std;

SDL_Window* g_sdlWindow;
SDL_Renderer* g_sdlRenderer;

SDL_Texture* LoadTexture(const char* filename) {
	SDL_Surface* image = SDL_LoadBMP(filename);
	if (image == nullptr) {
		cout << "Failed to load " << filename << ". SDL error: " << SDL_GetError() << endl;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(g_sdlRenderer, image);
	if (texture == nullptr) {
		cout << "Failed to create texture from surface. SDL error: " << SDL_GetError() << endl;
	}

	SDL_FreeSurface(image);

	return texture;
}

int main(int argc, char* argv[]) {

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Failed to initialise SDL. SDL error: " << SDL_GetError() << endl;
	}

	g_sdlWindow = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, NULL);

	if (g_sdlWindow == nullptr) {
		cout << "Failed to create window. SDL error: " << SDL_GetError() << endl;
	}

	g_sdlRenderer = SDL_CreateRenderer(g_sdlWindow, -1, SDL_RENDERER_ACCELERATED);
	if (g_sdlRenderer == nullptr) {
		cout << "Failed to create renderer. SDL error: " << SDL_GetError() << endl;
	}

	SDL_Texture* doorTexture = LoadTexture("door.bmp");
	for (int frameCount = 0; frameCount < 850; frameCount++) {

		SDL_SetRenderDrawColor(g_sdlRenderer, 255, 0, 0, 255);
		SDL_RenderClear(g_sdlRenderer);

		SDL_Rect destinationRect { frameCount,25,16,16 };

		SDL_RenderCopy(g_sdlRenderer, doorTexture, NULL, &destinationRect);

		SDL_RenderPresent(g_sdlRenderer);

		SDL_Delay(16);
	}


	// pauses console.
	getchar();

	SDL_DestroyTexture(doorTexture);

	SDL_DestroyRenderer(g_sdlRenderer);
	SDL_DestroyWindow(g_sdlWindow);
	SDL_Quit();

	return 0;
}