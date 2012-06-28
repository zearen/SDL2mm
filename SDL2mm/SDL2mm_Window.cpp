/**
 *
 */

#define _SDL2MM_INTERNAL
#include <vector>
#include "SDL2mm_Internal.h"

Window::Window(const char* title="", int x=0, int y=0, int w=800, int h=600, Uint32 flags) {
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
