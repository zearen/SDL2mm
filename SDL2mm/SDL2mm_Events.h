/**
 * Zachary Weaver <zearen.wover@gmail.com> (c) 2012
 *
 * License: BSD3
 * Version: 0.1 α
 * File: SDL2mm_Events.h
 *
 * Contains the definitions for all the events.  It's basically just a
 * wrapper around the corresponding SDL types.
 */

#ifndef _SDL2MM_EVENTS_H
#define _SDL2MM_EVENTS_H

#include "SDL2mm.h"

namespace SDL2 {
	/**
	 * A C++ Style Enum that corresponds exactly to the SDL C one.
	 */
	enum EEvent {
		FIRSTEVENT = 0,

		QUIT = 0x100,

		WINDOWEVENT =0x200,
		SYSWMEVENT,

		KEYDOWN = 0x300,
		KEYUP,
		TEXTEDITING,
		TEXTINPUT,

		MOUSEMOTION = 0x400,
		MOUSEBUTTONDOWN,
		MOUSEBUTTONUP,
		MOUSEWHEEL,

		INPUTMOTION = 0x500,
		INPUTBUTTONDOWN,
		INPUTBUTTONUP,
		INPUTWHEEL,
		INPUTPROXIMITYIN,
		INPUTPROXIMITYOUT,

		JOYAXISMOTION = 0x600,
		JOYBALLMOTION,
		JOYHATMOTION,
		JOYBUTTONDOWN,
		JOYBUTTONUP,

		FINGERDOWN = 0x700,
		FINGERUP,
		FINGERMOTION,
		TOUCHBUTTONDOWN,
		TOUCHBUTTONUP,

		DOLLARGESTURE = 0x800,
		DOLLARRECORD,
		MULTIGESTURE,

		CLIPBOARDUPDATE = 0x900,

		DROPFILE = 0x1000,

		USEREVENT = 0x8000,

		LASTEVENT = 0xFFFF
	};

	class Event {
	private:
		Uint32 _type;
	public:
		Event();
		Event(SDL_Event ev);
		Event(Uint32 type);
		virtual ~Event();

		virtual Uint32 type();
	};

	class QuitEvent : public Event {
	};

	class WindowEvent : public Event {
	protected:
		SDL_WindowEvent _winEv;
	public:
		WindowEvent();
		WindowEvent(SDL_WindowEvent ev);

		virtual Uint32 type();

		Uint32 windowID();

		Uint8 event();

		int data1();

		int data2();

	};
}
#endif
