/*
 * SelecTeamScreen.cpp
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#include "VsScreen.h"
#include "Constantes.h"

void VsScreen::draw(SDL_Surface *screen){

	SDL_Rect clearRect;
	clearRect.x = 0;
	clearRect.y = 0;
	clearRect.w = ANCHO_PANTALLA;
	clearRect.h = ALTO_PANTALLA;
	SDL_FillRect(screen, &clearRect, 0);
	portrait1->draw(screen);
	portrait2->draw(screen);
	vs->draw(screen);
}

int VsScreen::leer_teclado(){
	return 0;
}

void VsScreen::update(){
	CurrentScreen::update();
	if (portrait1->get_y()<ALTO_PANTALLA/2-80)
			portrait1->set_y(portrait1->get_y()+1);
	if (portrait2->get_y()>ALTO_PANTALLA/2-80)
			portrait2->set_y(portrait2->get_y()-1);
	if (CurrentScreen::get_ciclos()>600)
		CurrentScreen::set_destroyMe(true);

	if (CurrentScreen::get_ciclos()==400){
		vs->flash();
		sonido->play();
	}

	if (CurrentScreen::get_ciclos()==403)
		vs->flash();
}

bool VsScreen::get_destroyMe(){
	return CurrentScreen::get_destroyMe();
}

void VsScreen::terminar(){
	musica->liberar();
	sonido->free();
}
