/*
 * TiledBackground.h
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#ifndef TILEDBACKGROUND_H_
#define TILEDBACKGROUND_H_

#include "../Sprite.h"
#include "../Constantes.h"

class TiledBackground {
private:
	static const Uint8 width = 157;
	static const Uint8 height = 79;
	int numCasillas;
	bool flash;

public:
	//TODO: Make this dynamic
	Sprite tiles[500];

	TiledBackground() {
		int tilesAncho = ANCHO_PANTALLA/width+1;

		numCasillas = (ALTO_PANTALLA/(width*2)+2)*(tilesAncho + tilesAncho+2);
		for (int i=0;i<numCasillas;i++){
			if ((i/tilesAncho)%2 == 0)
				tiles[i].set_x(width*(i%tilesAncho));
			else
				tiles[i].set_x(width*(i%tilesAncho) - width/2);
			tiles[i].set_y(79*(i/tilesAncho));
			tiles[i].set_width(width);
			tiles[i].set_height(height);
			tiles[i].set_source_x(80);
			tiles[i].set_source_y(104);
		}
	}

	void draw(SDL_Surface *screen);
	void load_image(char* path,ResourceManager *resourceManager);
};

#endif /* TILEDBACKGROUND_H_ */
