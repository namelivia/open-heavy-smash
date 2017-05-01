#include "FlagSelector.h"

void FlagSelector::load_image(char* path, ResourceManager *resourceManager){
	sprite.load_image(path,resourceManager);
}

void FlagSelector::draw(SDL_Surface *screen){
	sprite.draw(screen);
}

void FlagSelector::update(){
	sprite.set_source_x(215+(frame%2)*width);
	sprite.set_source_y(0+(frame/2)*height);
	frame++;
	if (frame == 6) frame = 0;
}

void FlagSelector::set_position(Uint16 x, Uint16 y){
	sprite.set_x(x);
	sprite.set_y(y);
	sprite.set_width(width);
	sprite.set_height(height);
}

int FlagSelector::get_width(){
	return width;
}

int FlagSelector::get_height(){
	return height;
}
