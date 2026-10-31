#ifndef WINDOW_H
#define WINDOW_H

#include <SDL3/SDL.h>

typedef struct
{
	SDL_Window* handle;
	bool isRunning;
} Window;

typedef enum
{
	WINDOW_OKIE,
	WINDOW_SDL_ERROR
} WindowResult;



WindowResult window_create(Window* window);

void window_destroy(Window* window);

#endif
