/*
 * PowerBar.cpp
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#include "PowerBar.h"

void PowerBar::load_image(char* path,ResourceManager *resourceManager){
	background.load_image(path,resourceManager);
	for (Uint8 i=0;i<32;i++){
			powerCells[i].load_image(path,resourceManager);
			powerCells[i].make_flasheable(150);
	}
}

void PowerBar::draw(SDL_Surface *screen){
	background.draw(screen);
	for (Uint8 i=0;i<power;i++){
		if (power==32) powerCells[i].flash();
		powerCells[i].draw(screen);
	}
}

void PowerBar::set_power(Uint8 power){
	if (power<0 || power>32)
				return;
	this->power = power;
}


void PowerBar::set_position(Uint16 x,Uint16 y){
	background.set_x(x);
	background.set_y(y);
	background.set_source_x(31);
	background.set_source_y(0);
	background.set_width(width);
	background.set_height(height);

	for (int i=0;i<32;i++){
		powerCells[i].set_x((x+4)+(2*i));
		powerCells[i].set_y(y+10);
		powerCells[i].set_source_x(104);
		powerCells[i].set_source_y(0);
		powerCells[i].set_width(2);
		powerCells[i].set_height(12);

			}
}

int PowerBar::get_width(){
	return width;
}

int PowerBar::get_height(){
	return height;
}
