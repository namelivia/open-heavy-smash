#ifndef MAPSCREEN_H_
#define MAPSCREEN_H_

#include "../Music.h"
#include "../Constants.h"
#include "../UserInterface/Portrait.h"
#include "../CurrentScreen.h"
#include "../SoundFX.h"
#include "../UserInterface/Flag.h"
#include "../NewMatch.h"
#include "../GameState.h"
#include "SpaceShuttle.h"

class MapScreen : CurrentScreen{
private:
	static const Uint8 horizontalMargin = 24;
public:
	Sprite *map;
	Sprite *spaceStation;
	Sprite destiny[10];
	Flag flags[10];
	Sprite background[SCREEN_WIDTH];
	Uint8 selectedFlag;
	GameState *gameState;
	SpaceShuttle *spaceShuttle;
	bool arrived;
	int arrivalTime;

	MapScreen () {};
	MapScreen(NewMatch *newMatch,ResourceManager *resourceManager,GameState *gameState){

		//Coordinates of the team places. Should it be moved?
		int coordinates[10][2] = {{241,41},{146,50},{150,96},{52,34},{268,84},{38,32},{60,44},{68,56},{134,42},{0,0}};

		// Some variable inicialization ¿Shuttle -> New Class?
		selectedFlag = newMatch->getPlayer2Team();
		arrivalTime = 0;
		arrived = false;
		this->gameState = gameState;

		//Worldmap sprite
		map = new Sprite();
		map->load_image((char *)G_WORLDMAP,resourceManager);
		map->set_x(34);
		map->set_y(0);
		map->set_width(254);
		map->set_height(109);
		map->set_source_x(0);
		map->set_source_y(0);

		//Space station sprite
		spaceStation = new Sprite();
		spaceStation->load_image((char *)G_WORLDMAP,resourceManager);
		spaceStation->set_x(0);
		spaceStation->set_y(50);
		spaceStation->set_width(24);
		spaceStation->set_height(22);
		spaceStation->set_source_x(255);
		spaceStation->set_source_y(20);

		//Points on the, both destiny and origin and flags.
		for(int i=0;i<10;i++){

			flags[i].load_image((char *)G_UI,resourceManager);
			flags[i].set_country(i);
			if (i%2 == 0)
				flags[i].set_position(48+24*i,176);
			else
				flags[i].set_position(48+24*(i-1),208);

			if (i != selectedFlag)
				//flags[i].make_grayscale();

			if (!gameState->getDefeated(i)){
				destiny[i].load_image((char *)G_WORLDMAP,resourceManager);
				destiny[i].set_x(coordinates[i][0]);
				destiny[i].set_y(coordinates[i][1]);
				destiny[i].set_width(7);
				destiny[i].set_height(7);
				destiny[i].set_source_x(255);
				destiny[i].set_source_y(57);
			}
			else {
				destiny[i].load_image((char *)G_WORLDMAP,resourceManager);
				destiny[i].set_x(coordinates[i][0]-4);
				destiny[i].set_y(coordinates[i][1]-4);
				destiny[i].set_width(15);
				destiny[i].set_height(15);
				destiny[i].set_source_x(255);
				destiny[i].set_source_y(42);
			}
		}

		//Background (set of lines), Should this be changed?
		for(int i=0;i<SCREEN_WIDTH;i++){
			background[i].load_image((char *)G_WORLDMAP,resourceManager);
			background[i].set_x(i);
			background[i].set_y(18);
			background[i].set_width(1);
			background[i].set_height(75);
			background[i].set_source_x(254);
			background[i].set_source_y(0);
		}

		//Space Shuttle

		spaceShuttle = new SpaceShuttle(destiny[gameState->getLastDefeated()].get_x(),destiny[gameState->getLastDefeated()].get_y());
		spaceShuttle->load_image((char *)G_WORLDMAP,resourceManager);
		if (spaceShuttle->get_x()<destiny[selectedFlag].get_x()){
			spaceShuttle->hflip();
		}


	}

	void update();
	void draw(SDL_Renderer *sdlRenderer);
	int read_keyboard();
	void finish();
	bool get_destroyMe();
};

#endif /* MAPSCREEN_H_ */
