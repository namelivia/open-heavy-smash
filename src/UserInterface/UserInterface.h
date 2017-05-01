/*
 * UserInterface.h
 *
 *  Created on: 03/11/2012
 *      Author: nacho
 */

#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_

#include "Clock.h"
#include "PlayerUI.h"
#include "../NewMatch.h"
#include "../MatchState.h"

class UserInterface {
private:

public:

	Clock * clock;
	PlayerUI * player1UI;
	PlayerUI * player2UI;

	UserInterface() {
	}

	UserInterface(Uint16 x,Uint16 y,Uint16 width, Uint16 height, NewMatch *newMatch) {

		//ñapaaa para obtener la anchura de los objetos antes de crearlos
			this->clock = new Clock((width-30)/2,y,newMatch->getTime());
			this->player1UI = new PlayerUI(x,y,false,0,0,newMatch->getPlayer1Team());
			this->player2UI = new PlayerUI(x+width-player1UI->get_width(),y,true,0,0,newMatch->getPlayer2Team());
		}

	void draw(SDL_Surface *screen);
	void cargar(char *path,ResourceManager *resourceManager);
	void update(MatchState *matchState);
};


#endif /* USERINTERFACE_H_ */
