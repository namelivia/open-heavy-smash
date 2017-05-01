/*
 * MapScreen.cpp
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#include "MapScreen.h"

void MapScreen::draw(SDL_Surface *screen){

	SDL_Rect clearRect;
	clearRect.x = 0;
	clearRect.y = 0;
	clearRect.w = ANCHO_PANTALLA;
	clearRect.h = ALTO_PANTALLA;
	SDL_FillRect(screen, &clearRect, SDL_MapRGB(screen->format, 38, 38, 38));
	for(int i=0;i<ANCHO_PANTALLA;i++)
		background[i].draw(screen);
	map->draw(screen);
	for (int i=0;i<10;i++){
			flags[i].draw(screen);
			destiny[i].draw(screen);
	}
	spaceShuttle->draw(screen);
	spaceStation->draw(screen);
}

int MapScreen::leer_teclado(){
	return 0;
}

void MapScreen::update(){
	CurrentScreen::update();

	if (arrived)
		if (CurrentScreen::get_ciclos() > arrivalTime+200)
			CurrentScreen::set_destroyMe(true);

	if (CurrentScreen::get_ciclos()%5==0)
		spaceStation->set_x(spaceStation->get_x()+1);

	if (CurrentScreen::get_ciclos()>500)

		if (CurrentScreen::get_ciclos()%3==0){
			if (spaceShuttle->update(destiny[selectedFlag].get_x(),destiny[selectedFlag].get_y())){
				if (!arrived){
					arrivalTime = CurrentScreen::get_ciclos();
					arrived = true;
				}
			}
		}

	if (spaceStation->get_x()>ANCHO_PANTALLA)
		spaceStation->set_x(-spaceStation->get_width());
}

bool MapScreen::get_destroyMe(){
	return CurrentScreen::get_destroyMe();
}

void MapScreen::terminar(){
}
