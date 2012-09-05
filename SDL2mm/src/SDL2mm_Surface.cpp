/**
 *
 */

#define _SDL2MM_INTERNAL
#include <vector>
#include "SDL2mm_Internal.h"

Surface::Surface(SDL_Surface *initSurface) {
	sdlSurface = initSurface;
}

Surface::~Surface() {
	SDL_FreeSurface(sdlSurface);
}
