#ifndef _SDL2MM_ERROR_H
#define _SDL2MM_ERROR_H

#include "SDL2mm.h"
#include <exception>

namespace SDL2 {
class Error : public std::exception {
private:
	const char* msg;
public:
	Error();

	const char* what() const throw();
};

}

#endif
