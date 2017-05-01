/*
 * Juego.h
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#ifndef JUEGO_H_
#define JUEGO_H_

#include "SDL/SDL.h"
#include "Match.h"
#include "VsScreen.h"
#include "MapScreen/MapScreen.h"
#include "SelectTeamScreen.h"
#include "GameState.h"
#include "NewMatch.h"
#include "Constantes.h"

class Juego{
private:
	SDL_Surface *screen;
	Match match;
	NewMatch *newMatch;
	VsScreen vsScreen;
	MapScreen mapScreen;
	SelectTeamScreen selectTeamScreen;
	SDL_Event event;
	ResourceManager *resourceManager;
	GameState *gameState;
	bool salir;
	int currentScreen;

public:

	void iniciar();
	void bucle();
	void finalizar();
    int fps_sincronizar();
};

#endif /* JUEGO_H_ */
