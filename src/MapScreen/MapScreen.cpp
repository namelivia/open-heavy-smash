#include "MapScreen.h"

void MapScreen::draw(SDL_Renderer *sdlRenderer){

	for(int i=0;i<SCREEN_WIDTH;i++)
		background[i].draw(sdlRenderer);
	map->draw(sdlRenderer);
	for (int i=0;i<10;i++){
			flags[i].draw(sdlRenderer);
			destiny[i].draw(sdlRenderer);
	}
	spaceShuttle->draw(sdlRenderer);
	spaceStation->draw(sdlRenderer);
}

int MapScreen::read_keyboard(){
	return 0;
}

void MapScreen::update(){
	CurrentScreen::update();

	if (arrived)
		if (CurrentScreen::get_cycles() > arrivalTime+200)
			CurrentScreen::set_destroyMe(true);

	if (CurrentScreen::get_cycles()%5==0)
		spaceStation->set_x(spaceStation->get_x()+1);

	if (CurrentScreen::get_cycles()>500)

		if (CurrentScreen::get_cycles()%3==0){
			if (spaceShuttle->update(destiny[selectedFlag].get_x(),destiny[selectedFlag].get_y())){
				if (!arrived){
					arrivalTime = CurrentScreen::get_cycles();
					arrived = true;
				}
			}
		}

	if (spaceStation->get_x()>SCREEN_WIDTH)
		spaceStation->set_x(-spaceStation->get_width());
}

bool MapScreen::get_destroyMe(){
	return CurrentScreen::get_destroyMe();
}

void MapScreen::finish(){
}
