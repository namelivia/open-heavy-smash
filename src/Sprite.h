/*
 * Sprite.h
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include "Dibujo.h"
#include "Camara.h"

class Sprite{
private:
	int source_x;
	int source_y;
	Uint16 width;
	Uint16 height;
	int x;
	int y;
	bool isFlashing,isGrayscale,isFlipped;
public:
	Dibujo dibujo;
	Dibujo flashed;
	Dibujo grayscaled;
	Dibujo temp;
	Dibujo flipped;
	Sprite() {}

	void set_source_x(Uint16 nuevo_x);
	void set_source_y(Uint16 nuevo_y);
	void set_width(Uint16 nuevo_x);
	void set_height(Uint16 nuevo_y);
	Uint16 get_source_x();
	Uint16 get_source_y();
	Uint16 get_width();
	Uint16 get_height();
	void set_x(int nuevo_x);
	void set_y(int nuevo_y);
	int get_x();
	int get_y();
	void load_image(char* path, ResourceManager *resourceManager);
	void draw(SDL_Surface *screen,Camara *camara);
	void draw(SDL_Surface *screen);
	void make_flasheable(Uint8 strength);
	void make_grayscale();
	void hflip();
	void flash();
};

#endif /* SPRITE_H_ */
