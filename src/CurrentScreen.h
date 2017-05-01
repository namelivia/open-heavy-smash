/*
 * CurrentScreen.h
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#ifndef CURRENTSCREEN_H_
#define CURRENTSCREEN_H_

#include "SDL/SDL.h"

class CurrentScreen{
private:
	Uint32 ciclos;
	bool destroyMe;
public:

	explicit CurrentScreen () {
		ciclos = 0;
		destroyMe = false;
	}
	virtual void update();
	virtual void draw(SDL_Surface *screen);
	virtual int leer_teclado();
	virtual void terminar();
	int get_ciclos();
	void set_destroyMe(bool destroyMe);
	bool get_destroyMe();
};

#endif /* CURRENTSCREEN_H_ */
