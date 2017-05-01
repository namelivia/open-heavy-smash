/*
 * Captain.h
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#ifndef CAPTAIN_H_
#define CAPTAIN_H_

#include "../Sprite.h"

class Captain : public Sprite {
private:
	static const Uint16 width = 27;
	static const Uint16 height = 52;

public:

	Captain() {
	}

	Captain(int x,int y,int country){
		set_position(x,y);
		set_country(country);
	}

	void set_country(int country);
	void set_position(int x, int y);
};
#endif /* CAPTAIN_H_ */
