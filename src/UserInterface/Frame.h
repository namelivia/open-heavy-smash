/*
 * Frame.h
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#ifndef FRAME_H_
#define FRAME_H_

#include "../Sprite.h"

class Frame : public Sprite {
private:
	static const Uint16 width = 80;
	static const Uint16 height = 160;

public:

	Frame() {
	}

	Frame(int x,int y){
		set_position(x,y);
	}
	void set_position(int x, int y);
};
#endif /* FRAME_H_ */
