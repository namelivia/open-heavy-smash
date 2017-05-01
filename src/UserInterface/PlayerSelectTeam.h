/*
 * PlayerSelectTeam.h
 *
 *  Created on: 03/11/2012
 *      Author: nacho
 */

#ifndef PLAYERSELECTTEAM_H_
#define PLAYERSELECTTEAM_H_

#include "Portrait.h"
#include "Frame.h"
#include "PlayerName.h"
#include "Grid.h"
#include "Stats.h"
#include "Captain.h"

class PlayerSelectTeam {
private:
	static const Uint8 width = 126;
	static const Uint8 height = 190;
public:
	Portrait *portrait;
	Frame *frame;
	PlayerName *playerName;
	Grid *grid;
	Stats *stats;
	Captain *captain;

	PlayerSelectTeam(){
	}
	PlayerSelectTeam(int x, int y, bool right, int team, int playerName){
		if (right){
			this ->portrait = new Portrait(x-(width/23),y-65,team);
			this->frame = new Frame(x-(width/23),y-65);
			this->playerName = new PlayerName(x-(width/2),y-(height/2),playerName);
			this->grid = new Grid(x-52,y-65,playerName);
			this->stats = new Stats(x-52,y,playerName);
			this->captain = new Captain(x-45,y-55,team);
		}
		else {
			this ->portrait = new Portrait(x-72,y-65,team);
			this->frame = new Frame(x-72,y-65);
			this->playerName = new PlayerName(x-(width/2),y-(height/2),playerName);
			this->grid = new Grid(x+12,y-65,playerName);
			this->stats = new Stats(x+12,y,playerName);
			this->captain = new Captain(x+17,y-55,team);
		}
	}
	void draw(SDL_Surface *screen);
	void load_image(char *path_selectTeam,char *path_ui,char *path_portraits,ResourceManager *resourceManager);
	int get_width();
	int get_height();
	void set_team(int team);
	void update();
};


#endif /* PLAYERSELECTTEAM_H_ */
