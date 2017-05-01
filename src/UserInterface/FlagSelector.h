/*
 * FlagSelector.h
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#ifndef FLAGSELECTOR_H_
#define FLAGSELECTOR_H_

#include "../Sprite.h"

class FlagSelector {
private:
	static const Uint8 width = 41;
	static const Uint8 height = 16;
	int frame;

public:
	Sprite sprite;

	FlagSelector();
	FlagSelector(Uint16 x, Uint16 y) {
		set_position(x,y);
		frame = 0;
		update();
	}
	void draw(SDL_Surface *screen);
	void load_image(char* path, ResourceManager *resourceManager);
	void set_score(Uint8 score);
	void set_position(Uint16 x,Uint16 y);
	int get_width();
	int get_height();
	void update();
};

#endif /* FLAGSELECTOR_H_ */
