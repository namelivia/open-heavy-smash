#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "Sprite.h"
#include "Constants.h"

class Character {
private:
	int step;
	int direction;
	static const int speed = 1;

public:
	Sprite sprite;

	Character(int initial_x,int initial_y) {sprite.set_x(initial_x*TILE_WIDTH);sprite.set_y(initial_y*TILE_HEIGHT);step=0;}

	void move_character(int what_direction);
	void draw(SDL_Surface *screen,Camera *camera);
	int get_speed();
	void stop_moving();
};

#endif /* CHARACTER_H_ */
