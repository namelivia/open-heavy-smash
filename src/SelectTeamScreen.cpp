/*
 * SelectTeamScreen.cpp
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#include "SelectTeamScreen.h"
#include "Constantes.h"

void SelectTeamScreen::draw(SDL_Surface *screen){

	background->draw(screen);
	clock->draw(screen);
	for (int i=0;i<10;i++)flags[i].draw(screen);
	flagSelector->draw(screen);
	player1SelectTeam->draw(screen);
	player2SelectTeam->draw(screen);
}

int SelectTeamScreen::leer_teclado(){
	int tecla = CurrentScreen::leer_teclado();
	if (tecla>0) pressedKey=tecla;
	return 0;
}

void SelectTeamScreen::update(){
	CurrentScreen::update();
	if (CurrentScreen::get_ciclos()%CICLOSPORSEGUNDO == 0)
			state->setTime(state->getTime()-1);

	clock->set_time(state->getTime());

	if (CurrentScreen::get_ciclos()%15 == 0)
		flagSelector->update();

	player1SelectTeam->update();
	player2SelectTeam->update();

	if (CurrentScreen::get_ciclos()%15 == 0){
		if (pressedKey > 0){

			if (pressedKey == 2){
				selectedFlag++;
				sonido->play();
				if (selectedFlag > 9)
					selectedFlag = 0;
			}

			else if (pressedKey == 1) {
				selectedFlag--;
				sonido->play();
				if (selectedFlag < 0)
					selectedFlag = 9;
			}
			else if (pressedKey == 5) {
				CurrentScreen::set_destroyMe(true);
			}
			pressedKey = 0;
		}
	}

	if (CurrentScreen::get_ciclos()>maxTime*CICLOSPORSEGUNDO)
		CurrentScreen::set_destroyMe(true);

	SelectFlag(selectedFlag);
}

bool SelectTeamScreen::get_destroyMe(){
	return CurrentScreen::get_destroyMe();
}

int SelectTeamScreen::get_selectedTeam(){
	return selectedFlag;
}


void SelectTeamScreen::SelectFlag(int whatFlag){
	flagSelector->set_position(flags[whatFlag].get_x()-16,flags[whatFlag].get_y());
	player1SelectTeam->set_team(whatFlag);
	player2SelectTeam->set_team(3);
}

void SelectTeamScreen::terminar(){
	musica->liberar();
	sonido->free();
}
