#ifndef CURRENTSCREEN_H_
#define CURRENTSCREEN_H_

#include "SDL2/SDL.h"

class CurrentScreen{
private:
	Uint32 cycles;
	bool destroyMe;
public:

	explicit CurrentScreen () {
		cycles = 0;
		destroyMe = false;
	}
	virtual void update();
	virtual void draw(SDL_Renderer *sdlRenderer);
	virtual int read_keyboard();
	virtual void finish();
	int get_cycles();
	void set_destroyMe(bool destroyMe);
	bool get_destroyMe();
};

#endif /* CURRENTSCREEN_H_ */
