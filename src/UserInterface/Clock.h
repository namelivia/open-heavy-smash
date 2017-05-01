#ifndef CLOCK_H_
#define CLOCK_H_

#include "../Sprite.h"

class Clock {
private:

public:
	Sprite background;
	Sprite numbers[2];
	Clock(){
	}

	Clock(int x, int y, int time){
			set_position(x,y);
			set_time(time);
		}
	void draw(SDL_Renderer *sdlRenderer);
	void load_image(char* path,ResourceManager *resourceManager);
	void set_time(int time);
	void set_position(int x,int y);
};


#endif /* CLOCK_H_ */
