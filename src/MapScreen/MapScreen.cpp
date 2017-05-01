#include "MapScreen.h"

void MapScreen::draw(SDL_Surface *screen){

	SDL_Rect clearRect;
	clearRect.x = 0;
	clearRect.y = 0;
	clearRect.w = SCREEN_WIDTH;
	clearRect.h = SCREEN_HEIGHT;
	SDL_FillRect(screen, &clearRect, SDL_MapRGB(screen->format, 38, 38, 38));
	for(int i=0;i<SCREEN_WIDTH;i++)
		background[i].draw(screen);
	map->draw(screen);
	for (int i=0;i<10;i++){
			flags[i].draw(screen);
			destiny[i].draw(screen);
	}
	spaceShuttle->draw(screen);
	spaceStation->draw(screen);
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
