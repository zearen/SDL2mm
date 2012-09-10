/*
 * Zachary Weaver <zearen.wover@gmail.com> (c) 2012
 *
 * License: BSD3
 * Version: 0.1 α
 * File: SDL2mm_Program.h
 */

#define _SDL2MM_INTERNAL
#include "SDL2mm_Internal.h"

Application::Application() {

}

Application::Application(Application *prevApp) {
	if (!prevApp) return;

}

bool Application::processEvents() {
	bool alive = true;
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch(event.type) {
		case EventEnum::QUIT:
			_quit = true;
			alive = false;
			break;
		default:
			break;
		}
	}
	return alive;
}

void Application::mainLoop() {
	while (processEvents());
}

bool Application::userQuit() {
	return _quit;
}
