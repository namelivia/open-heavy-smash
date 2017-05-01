#include "TiledBackground.h"

void TiledBackground::load_image(char* path,ResourceManager *resourceManager){
	for (int i=0;i<tile_number;i++){
		tiles[i].load_image(path,resourceManager);
	}
}

void TiledBackground::draw(SDL_Renderer *sdlRenderer){
	for (int i=0;i<tile_number;i++){
		tiles[i].draw(sdlRenderer);
	}
}
