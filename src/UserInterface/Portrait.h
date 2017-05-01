/*
 * Portrait.h
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#ifndef PORTRAIT_H_
#define PORTRAIT_H_

#include "../Sprite.h"

class Portrait : public Sprite {
private:
	static const int width = 80;
	static const int height = 160;

public:

	Portrait() {
	}

	Portrait(int x,int y,int country){
		set_position(x,y);
		set_country(country);
	}

	void load_image(char* path,ResourceManager *resourceManager);
	void set_country(int country);
	void set_position(int x, int y);
	int get_width();
	int get_height();
};
#endif /* FLAG_H_ */
