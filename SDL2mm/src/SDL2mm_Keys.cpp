#define _SDL2MM_INTERNAL
#include "SDL2mm_Internal.h"

Modifier::Modifier() {
	mod = 0;
}

Modifier::Modifier(Uint16 initMod) {
	mod = initMod;
}

Modifier::Modifier(Modifier& toCopy) {
	mod = toCopy.mod;
}

bool Modifier::has(EModifier modifier) {
	return mod & modifier != 0;
}

void Modifier::set(EModifier modifier) {
	mod |= modifier;
}

void Modifier::unset(EModifier modifier) {
	mod &= ~modifier;
}

KeySym::KeySym() {
	keySym.mod = 0;
	keySym.scancode = Scancode::UNKNOWN;
	keySym.sym = Keycode::UNKNOWN;
}

KeySym::KeySym(SDL_Keysym initKeySym) {
	keySym = initKeySym;
}

KeySym::KeySym(KeySym& toCopy) {
	keySym = toCopy.keySym;
}

EScancode KeySym::scancode() {
	return keySym.scancode;
}

EKeycode KeySym::keycode() {
	return keySym.scancode;
}

Modifier KeySym::modifier() {
	return Modifier(keySym.mod);
}
