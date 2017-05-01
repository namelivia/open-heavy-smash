/*
 * CurrentScreen.cpp
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#include "CurrentScreen.h"

void CurrentScreen::draw(SDL_Surface *screen){
}

int CurrentScreen::leer_teclado(){
	Uint8 *keystate;
	keystate= SDL_GetKeyState(NULL);
	if (keystate[SDLK_UP]) return 1;
	else if (keystate[SDLK_DOWN])return 2;
	else if (keystate[SDLK_LEFT])return 3;
	else if (keystate[SDLK_RIGHT])return 4;
	else if (keystate[SDLK_RETURN]) return 5;
	else return 0;
}

void CurrentScreen::update(){
	ciclos++;
}

void CurrentScreen::terminar(){
}

int CurrentScreen::get_ciclos(){
	return ciclos;
}

bool CurrentScreen::get_destroyMe(){
	return destroyMe;
}

void CurrentScreen::set_destroyMe(bool destroyMe){
	this->destroyMe = destroyMe;
}
