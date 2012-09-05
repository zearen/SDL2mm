/**
 *
 */

#define _SDL2MM_INTERNAL
#include <vector>
#include "SDL2mm_Internal.h"

Window::Window(const char* title, Uint32 flags, int x, int y, int w, int h) {
	sdlWindow = SDL_CreateWindow(title, x, y, w, h, flags);
}

Window::Window(SDL_Window *initWindow) {
	sdlWindow = initWindow;
}

Window::~Window() {
	SDL_DestroyWindow(sdlWindow);
}

Surface Window::getSurface() {
	return Surface(SDL_GetWindowSurface(sdlWindow));
}
