#include "Match.h"
#include "Constants.h"

void Match::update_camera(){
	//camera->set_x(character->sprite.get_x()-SCREEN_WIDTH/2);
	//camera->set_y(character->sprite.get_y()-SCREEN_HEIGHT/2);
	if (camera->get_x()<0) camera->set_x(0);
	if (camera->get_y()<0) camera->set_y(0);
}

void Match::draw(SDL_Renderer *sdlRenderer){

	if (userInterface !=NULL) userInterface->draw(sdlRenderer);
	//if (scenery!=NULL)scenery->draw(sdlRenderer,camera);
	//if (character!=NULL)character->draw(sdlRenderer,camera);
	//if (window_zone!=NULL && window_zone->get_vida()>0){window_zone->draw(sdlRenderer);
	//													 window_zone->decrementar_vida();
	//}
}

int Match::read_keyboard(){
	return 0;
}

void Match::update(){

	CurrentScreen::update();
	update_camera();
	if (CurrentScreen::get_cycles()%CYCLESPERSEC == 0)
		matchState->setTime(matchState->getTime()-1);
	if (CurrentScreen::get_cycles()%POWERRATE == 0){
			matchState->setPlayer1Power(matchState->getPlayer1Power()+1);
			matchState->setPlayer2Power(matchState->getPlayer2Power()+1);
	}
	userInterface->update(matchState);
}

void Match::finish(){
	music->free();
}
