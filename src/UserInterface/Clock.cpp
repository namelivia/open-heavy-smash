/*
 * Clock.cpp
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#include "Clock.h"

	void Clock::load_image(char *path, ResourceManager *resourceManager){
		background.load_image(path,resourceManager);
		numbers[0].load_image(path,resourceManager);
		numbers[1].load_image(path,resourceManager);
	}
	void Clock::draw(SDL_Surface *screen){
		this->background.draw(screen);
		this->numbers[0].draw(screen);
		this->numbers[1].draw(screen);;
	}

	void Clock::set_time(int time){
		if (time<0 || time>99)
			return;
		numbers[0].set_source_x(((time/10)%5)*9);
		numbers[0].set_source_y(32+(((time/10)/5)*14));
		numbers[1].set_source_x(((time%10)%5)*9);
		numbers[1].set_source_y(32+(((time%10)/5)*14));

	}

	void Clock::set_position(int x,int y){
		background.set_x(x);
		background.set_y(y);
		background.set_source_x(0);
		background.set_source_y(0);
		background.set_width(31);
		background.set_height(32);

		numbers[0].set_x(x+4);
		numbers[0].set_y(y+8);
		numbers[0].set_width(9);
		numbers[0].set_height(14);

		numbers[1].set_x(x+17);
		numbers[1].set_y(y+8);
		numbers[1].set_width(9);
		numbers[1].set_height(14);
	}
