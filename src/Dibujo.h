/*
 * Dibujo.h
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#ifndef DIBUJO_H_
#define DIBUJO_H_
#include "SDL/SDL.h"
#include "ResourceManager.h"

class Dibujo{
private:
	SDL_Surface *imagen;
	Uint32 get_pixel32( SDL_Surface *surface, Uint16 x, Uint16 y );
	void put_pixel32( SDL_Surface *surface, Uint16 x, Uint16 y, Uint32 pixel );
public:
	Dibujo() {}
	int load_image(char *path,ResourceManager *resourceManager);
	SDL_Surface *get_dibujo();
	void flash(Uint8 strength);
	void grayscale();
	void flip();
	Uint8 add(Uint8 number1,Uint8 number2);
};

#endif /* DIBUJO_H_ */
