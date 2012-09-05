#define _SDL2MM_INTERNAL
#include "SDL2mm_Internal.h"

Error::Error() {
	msg = SDL_GetError();
}

const char *Error::what() const throw() {
	return msg;
}
