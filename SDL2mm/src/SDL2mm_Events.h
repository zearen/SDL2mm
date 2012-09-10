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
#include <string>

namespace SDL2 {
	/**
	 * A C++ Style Enum that corresponds exactly to the SDL C one,
	 * and is hidden inside a namespace.
	 */
	namespace Events {
	enum EventEnum {
		FIRSTEVENT = SDL_FIRSTEVENT,
		QUIT = SDL_QUIT,
		WINDOWEVENT = SDL_WINDOWEVENT,
		SYSWMEVENT = SDL_SYSWMEVENT,
		KEYDOWN = SDL_KEYDOWN,
		KEYUP = SDL_KEYUP,
		TEXTEDITING = SDL_TEXTEDITING,
		TEXTINPUT = SDL_TEXTINPUT,
		MOUSEMOTION = SDL_MOUSEMOTION,
		MOUSEBUTTONDOWN = SDL_MOUSEBUTTONDOWN,
		MOUSEBUTTONUP = SDL_MOUSEBUTTONUP,
		MOUSEWHEEL = SDL_MOUSEWHEEL,
		INPUTMOTION = SDL_INPUTMOTION,
		INPUTBUTTONDOWN = SDL_INPUTBUTTONDOWN,
		INPUTBUTTONUP = SDL_INPUTBUTTONUP,
		INPUTWHEEL = SDL_INPUTWHEEL,
		INPUTPROXIMITYIN = SDL_INPUTPROXIMITYIN,
		INPUTPROXIMITYOUT = SDL_INPUTPROXIMITYOUT,
		JOYAXISMOTION = SDL_JOYAXISMOTION,
		JOYBALLMOTION = SDL_JOYBALLMOTION,
		JOYHATMOTION = SDL_JOYHATMOTION,
		JOYBUTTONDOWN = SDL_JOYBUTTONDOWN,
		JOYBUTTONUP = SDL_JOYBUTTONUP,
		FINGERDOWN = SDL_FINGERDOWN,
		FINGERUP = SDL_FINGERUP,
		FINGERMOTION = SDL_FINGERMOTION,
		TOUCHBUTTONDOWN = SDL_TOUCHBUTTONDOWN,
		TOUCHBUTTONUP = SDL_TOUCHBUTTONUP,
		DOLLARGESTURE = SDL_DOLLARGESTURE,
		DOLLARRECORD = SDL_DOLLARRECORD,
		MULTIGESTURE = SDL_MULTIGESTURE,
		CLIPBOARDUPDATE = SDL_CLIPBOARDUPDATE,
		DROPFILE = SDL_DROPFILE,
		USEREVENT = SDL_USEREVENT,
		LASTEVENT = SDL_LASTEVENT
	};}
	typedef Events::EventEnum EEvent;

	class Event {
	private:
		Uint32 _type;
	public:
		Event();
		Event(SDL_Event ev);
		Event(Uint32 type);
		virtual ~Event();

		virtual Uint32 windowID();

		virtual Uint32 type();
	};

	class QuitEvent : public Event {
	};


	/**
	 * Window Events
	 */
	namespace WindowEvents {
	enum WindowEventEnum {
		NONE = SDL_WINDOWEVENT_NONE,
		SHOWN = SDL_WINDOWEVENT_SHOWN,
		HIDDEN = SDL_WINDOWEVENT_HIDDEN,
		EXPOSED = SDL_WINDOWEVENT_EXPOSED,
		MOVED = SDL_WINDOWEVENT_MOVED,
		RESIZED = SDL_WINDOWEVENT_RESIZED,
		MINIMIZED = SDL_WINDOWEVENT_MINIMIZED,
		MAXIMIZED = SDL_WINDOWEVENT_MAXIMIZED,
		RESTORED = SDL_WINDOWEVENT_RESTORED,
		ENTER = SDL_WINDOWEVENT_ENTER,
		LEAVE = SDL_WINDOWEVENT_LEAVE,
		CLOSE = SDL_WINDOWEVENT_CLOSE
	};}
	typedef WindowEvents::WindowEventEnum EWindowEvent;

	class WindowEvent : public Event {
	protected:
		SDL_WindowEvent _winEv;
	public:

		WindowEvent();
		WindowEvent(SDL_WindowEvent ev);

		virtual Uint32 type();

		virtual Uint32 windowID();

		EWindowEvent event();

		int data1();

		int data2();
	};

	class WindowShownEvent : public WindowEvent {
	};

	class WindowHiddenEvent : public WindowEvent {
	};

	class WindowExposedEvent : public WindowEvent {
	};

	class WindowMovedEvent : public WindowEvent {
		int xPos();

		int yPos();
	};

	class WindowResizedEvent : public WindowEvent {
		int width();

		int height();
	};

	class WindowMinimzedEvent : public WindowEvent {
	};

	class WindowMaximizedEvent : public WindowEvent {
	};

	class WindowRestoredEvent : public WindowEvent {
	};

	class WindowEnterEvent : public WindowEvent {
	};

	class WindowLeaveEvent : public WindowEvent {
	};

	class WindowFocusGainedEvent : public WindowEvent {
	};

	class WindowFocusLostEvent : public WindowEvent {
	};

	class WindowCloseEvent : public WindowEvent {
	};

	/*
	class SysWMEvent : public Event {
	};
	*/

	/**
	 * Keyboard Events
	 */
	class KeyboardEvent : public Event {
	protected:
		SDL_KeyboardEvent _keyEv;
	public:
		KeyboardEvent();
		KeyboardEvent(SDL_KeyboardEvent ev);

		virtual Uint32 type() =0;

		virtual Uint32 windowID();

		bool isPressed();

		bool isRepeat();

		KeySym keySym();
	};

	class KeyDownEvent : public KeyboardEvent {
	public:
		virtual Uint32 type();
	};

	class KeyUpEvent : public KeyboardEvent {
	public:
		virtual Uint32 type();
	};

	class TextEditingEvent : public Event {
	private:
		SDL_TextEditingEvent _editEv;
	public:
		TextEditingEvent();
		TextEditingEvent(SDL_TextEditingEvent ev);

		virtual Uint32 type();

		virtual Uint32 windowID();

		Uint32 timestamp();

		std::string text();

		int start();
		int length();
	};

	class TextInputEvent : public Event {
	private:
		SDL_TextInputEvent _inputEv;
	public:
		TextInputEvent();
		TextInputEvent(SDL_TextInputEvent ev);

		virtual Uint32 type();

		virtual Uint32 windowID();

		std::string text();
	};

	class MouseEvent : public Event {
	public:
		virtual int x();

		virtual int y();
	};

	namespace Buttons {
	enum ButtonEnum {
		LEFT = SDL_BUTTON_LEFT,
		MIDDLE = SDL_BUTTON_MIDDLE,
		RIGHT = SDL_BUTTON_RIGHT,
		X1 = SDL_BUTTON_X1,
		X2 = SDL_BUTTON_X2
	};}
	typedef Buttons::ButtonEnum EButton;

	class MouseButtonEvent : public MouseEvent {
	private:
		SDL_MouseButtonEvent _mbEv;
	public:
		virtual Uint32 type();

		virtual Uint32 windowID();

		virtual int x();

		virtual int y();

		EButton button();
	};


}
#endif
