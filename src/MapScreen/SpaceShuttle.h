/*
 * SpaceShuttle.h
 *
 *  Created on: 03/11/2012
 *      Author: nacho
 */

#ifndef SPACESHUTTLE_H_
#define SPACESHUTTLE_H_

#include "../Sprite.h"

class SpaceShuttle {
private:

public:
	Sprite shuttle;
	Sprite fire;
	int x;
	int y;
	bool isFlying;
	bool fireFrame;
	bool flipped;

	SpaceShuttle(int x, int y){
		this->x = x;
		this->y = y;

		isFlying = false;
		shuttle.set_width(18);
		shuttle.set_height(12);
		shuttle.set_source_x(255);
		shuttle.set_source_y(8);

		fire.set_width(15);
		fire.set_height(8);
		fire.set_source_x(255);
		fire.set_source_y(0);

		fireFrame = false;
		flipped = false;
	}
	void draw(SDL_Surface *screen);
	void load_image(char* path,ResourceManager *resourceManager);
	void hflip();
	void set_position(int x,int y);
	int get_x();
	int get_y();
	bool update(int destinationX, int destinationY);
	void AnimateFire();
};


#endif /* SPACESHUTTLE_H_ */
