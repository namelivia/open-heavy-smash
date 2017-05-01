/*
 * Match.cpp
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#include "Match.h"
#include "Constantes.h"

void Match::actualizar_camara(){
	//camara->set_x(personaje->sprite.get_x()-ANCHO_PANTALLA/2);
	//camara->set_y(personaje->sprite.get_y()-ALTO_PANTALLA/2);
	if (camara->get_x()<0) camara->set_x(0);
	if (camara->get_y()<0) camara->set_y(0);
}

void Match::draw(SDL_Surface *screen){

	SDL_Rect clearRect;
	clearRect.x = 0;
	clearRect.y = 0;
	clearRect.w = ANCHO_PANTALLA;
	clearRect.h = ALTO_PANTALLA;
	SDL_FillRect(screen, &clearRect, 0);
	if (userInterface !=NULL) userInterface->draw(screen);
	//if (escenario!=NULL)escenario->draw(screen,camara);
	//if (personaje!=NULL)personaje->draw(screen,camara);
	//if (ventana_zona!=NULL && ventana_zona->get_vida()>0){ventana_zona->draw(screen);
	//													 ventana_zona->decrementar_vida();
	//}
}

int Match::leer_teclado(){
	return 0;
}

void Match::update(){

	CurrentScreen::update();
	actualizar_camara();
	if (CurrentScreen::get_ciclos()%CICLOSPORSEGUNDO == 0)
		matchState->setTime(matchState->getTime()-1);
	if (CurrentScreen::get_ciclos()%POWERRATE == 0){
			matchState->setPlayer1Power(matchState->getPlayer1Power()+1);
			matchState->setPlayer2Power(matchState->getPlayer2Power()+1);
	}
	userInterface->update(matchState);
}

void Match::terminar(){
	musica->liberar();
}
