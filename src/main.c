#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "window.h"

int main(int argc, char* args[])
{
	Window window;
	bool done = false;

	// Create Window
	WindowResult result = window_create(&window);	
	if (result != WINDOW_OKIE)
		return 1;

	// Game loop! what needs to be done every frame?
	while (!done) // maybe move polling into window class?
	{
		SDL_Event event;
		
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT)
				done = true;

			// handle other events here
		}
	}

	window_destroy(&window);

	return 0;
}
