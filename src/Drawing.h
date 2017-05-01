#ifndef DRAWING_H_
#define DRAWING_H_
#include "SDL2/SDL.h"
#include "ResourceManager.h"

class Drawing{
private:
	SDL_Texture *image;
	Uint32 get_pixel32( SDL_Surface *surface, Uint16 x, Uint16 y );
	void put_pixel32( SDL_Surface *surface, Uint16 x, Uint16 y, Uint32 pixel );
public:
	Drawing() {}
	int load_image(char *path,ResourceManager *resourceManager);
	SDL_Texture *get_drawing();
	//void flash(Uint8 strength);
	//void grayscale();
	//void flip();
	//Uint8 add(Uint8 number1,Uint8 number2);
};

#endif /* DRAWING_H_ */
