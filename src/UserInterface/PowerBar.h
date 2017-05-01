#ifndef POWERBAR_H_
#define POWERBAR_H_

#include "../Sprite.h"

class PowerBar {
private:
	static const Uint8 width = 73;
	static const Uint8 height = 24;
	int power;
	bool flash;

public:
	Sprite powerCells[32];
	Sprite background;

	PowerBar() {
	}

	PowerBar(Uint16 x, Uint16 y, Uint8 power) {
		set_position(x,y);
		set_power(power);
	}
	void draw(SDL_Surface *screen);
	void load_image(char* path,ResourceManager *resourceManager);
	void set_position(Uint16 x, Uint16 y);
	void set_power(Uint8 power);
	int get_width();
	int get_height();
};

#endif /* POWERBAR_H_ */
