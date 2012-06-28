/**
 *
 */

#ifndef _SDL2MM_SURFACE_H
#define _SDL2MM_SURFACE_H

#include "SDL2mm.h"

namespace SDL2 {

class Surface {
private:
	SDL_Surface *sdlSurface;
public:
	Surface();
	Surface(SDL_Surface *initSurface);
	~Surface();


};

}
