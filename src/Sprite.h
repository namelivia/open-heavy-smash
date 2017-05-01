#ifndef SPRITE_H_
#define SPRITE_H_

#include "Drawing.h"
#include "Camera.h"

class Sprite{
private:
	int source_x;
	int source_y;
	Uint16 width;
	Uint16 height;
	int x;
	int y;
	bool isFlashing,isGrayscale,isFlipped;
public:
	Drawing drawing;
	Drawing flashed;
	Drawing grayscaled;
	Drawing temp;
	Drawing flipped;
	Sprite() {}

	void set_source_x(Uint16 new_x);
	void set_source_y(Uint16 new_y);
	void set_width(Uint16 new_x);
	void set_height(Uint16 new_y);
	Uint16 get_source_x();
	Uint16 get_source_y();
	Uint16 get_width();
	Uint16 get_height();
	void set_x(int new_x);
	void set_y(int new_y);
	int get_x();
	int get_y();
	void load_image(char* path, ResourceManager *resourceManager);
	void draw(SDL_Surface *screen,Camera *camera);
	void draw(SDL_Surface *screen);
	void make_flasheable(Uint8 strength);
	void make_grayscale();
	void hflip();
	void flash();
};

#endif /* SPRITE_H_ */
