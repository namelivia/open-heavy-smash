/*
 * Grid.h
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#ifndef GRID_H_
#define GRID_H_

#include "../Sprite.h"

class Grid : public Sprite {
private:
	static const Uint16 width = 40;
	static const Uint16 height = 65;

public:

	Grid() {
	}

	Grid(int x,int y,int color){
		set_position(x,y);
		set_color(color);
	}

	void set_color(int name);
	void set_position(int x, int y);
};
#endif /* GRID_H_ */
