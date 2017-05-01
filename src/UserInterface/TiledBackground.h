#ifndef TILEDBACKGROUND_H_
#define TILEDBACKGROUND_H_

#include "../Sprite.h"
#include "../Constants.h"

class TiledBackground {
private:
	static const Uint8 width = 157;
	static const Uint8 height = 79;
	int tile_number;
	bool flash;

public:
	//TODO: Make this dynamic
	Sprite tiles[500];

	TiledBackground() {
		int horizontal_tiles = SCREEN_WIDTH/width+1;

		tile_number = (SCREEN_HEIGHT/(width*2)+2)*(horizontal_tiles + horizontal_tiles+2);
		for (int i=0;i<tile_number;i++){
			if ((i/horizontal_tiles)%2 == 0)
				tiles[i].set_x(width*(i%horizontal_tiles));
			else
				tiles[i].set_x(width*(i%horizontal_tiles) - width/2);
			tiles[i].set_y(79*(i/horizontal_tiles));
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
