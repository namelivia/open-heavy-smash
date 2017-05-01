/*
 * TiledBackground.cpp
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#include "TiledBackground.h"

void TiledBackground::load_image(char* path,ResourceManager *resourceManager){
	for (int i=0;i<numCasillas;i++){
		tiles[i].load_image(path,resourceManager);
	}
}

void TiledBackground::draw(SDL_Surface *screen){
	for (int i=0;i<numCasillas;i++){
					tiles[i].draw(screen);
				}
}
