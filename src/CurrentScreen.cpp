#include "CurrentScreen.h"

void CurrentScreen::draw(SDL_Renderer *sdlRenderer){
}

int CurrentScreen::read_keyboard(){
	const Uint8 *keystate = SDL_GetKeyboardState(NULL);
	if (keystate[SDL_SCANCODE_UP]) return 1;
	else if (keystate[SDL_SCANCODE_DOWN])return 2;
	else if (keystate[SDL_SCANCODE_LEFT])return 3;
	else if (keystate[SDL_SCANCODE_RIGHT])return 4;
	else if (keystate[SDL_SCANCODE_RETURN]) return 5;
	else return 0;
}

void CurrentScreen::update(){
	cycles++;
}

void CurrentScreen::finish(){
}

int CurrentScreen::get_cycles(){
	return cycles;
}

bool CurrentScreen::get_destroyMe(){
	return destroyMe;
}

void CurrentScreen::set_destroyMe(bool destroyMe){
	this->destroyMe = destroyMe;
}
