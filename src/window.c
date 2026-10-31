#include "window.h"


// should probably move these somewhere editable...
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

// https://wiki.libsdl.org/SDL3/SDL_WindowFlags
const SDL_WindowFlags FLAGS = SDL_WINDOW_RESIZABLE | SDL_WINDOW_VULKAN; 

WindowResult window_create(Window* window)
{
	// initialize SDL then create a window
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return WINDOW_SDL_ERROR;
	}

	window->handle = SDL_CreateWindow("Leaf Skitter", SCREEN_WIDTH, SCREEN_HEIGHT, FLAGS);
	if (window->handle == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());

		SDL_Quit();
		return WINDOW_SDL_ERROR;
	}

	window->isRunning = true;
	return WINDOW_OKIE;
}

void window_destroy(Window* window)
{
	window->isRunning = false;
	SDL_DestroyWindow(window->handle);
	SDL_Quit();
}
