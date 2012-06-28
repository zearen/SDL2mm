/*
 * Zachary Weaver <zearen.wover@gmail.com> (c) 2012
 *
 * License: BSD3
 * Version: 0.1 α
 * File: SDL2mm_Program.h
 */

#ifndef _SDL2MM_PROGRAM_H
#define _SDL2MM_PROGRAM_H

#include "SDL2mm.h"

namespace SDL2 {
	class Application {
	private:
		bool _quit = false;
	public:
		/**
		 * Creates a new application and initializes SDL
		 */
		Application();

		/*
		 * Used to chain applications or screens together, passing
		 * application state to the next Application
		 */
		Application(Application* prevApp);

		/**
		 * Destroys the Application and shuts down SDL if not chained
		 */
		virtual ~Application();

		/**
		 * Processes and dispatches events.
		 * It is intended to be used with application that have a greedy
		 * mainLoop() like function.  This should be called every iteration
		 * It's speed is wholly dependent on the speed of client code.
		 * It will return false when the application finishes
		 */
		bool processEvents();

		/**
		 * Runs the application
		 * This just calls processEvents until it returns false
		 */
		void mainLoop();

		/**
		 * Returns whether the application ended from a Quit event.
		 */
		bool userQuit();
	};
}

#endif
