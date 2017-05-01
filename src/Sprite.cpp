#include "Sprite.h"
#include "Camera.h"
#include "Constants.h"

void Sprite::set_source_x(Uint16 new_x){source_x=new_x;}
void Sprite::set_source_y(Uint16 new_y){source_y=new_y;}
void Sprite::set_width(Uint16 new_x){width=new_x;}
void Sprite::set_height(Uint16 new_y){height=new_y;}
Uint16 Sprite::get_source_x(){return source_x;}
Uint16 Sprite::get_source_y(){return source_y;}
Uint16 Sprite::get_width(){return width;}
Uint16 Sprite::get_height(){return height;}
void Sprite::set_x(int new_x){x=new_x;}
void Sprite::set_y(int new_y){y=new_y;}
int Sprite::get_x(){return x;}
int Sprite::get_y(){return y;}

void Sprite::draw(SDL_Renderer *sdlRenderer,Camera *camera){
	SDL_Texture *texture = drawing.get_drawing();
	SDL_Rect fuente = {source_x,source_y, width, height};
	SDL_Rect rect = {x-camera->get_x(),y-camera->get_y(),0,0};
	SDL_RenderCopy(sdlRenderer, texture, &fuente, &rect);
}

void Sprite::draw(SDL_Renderer *sdlRenderer){
	SDL_Texture *texture = drawing.get_drawing();
	SDL_Rect src;
	SDL_Rect dest;
 	src.x	= source_x;
	src.y = source_y;
	src.w = width;
	src.h = height;
	dest.x = x;
	dest.y = y;
	dest.w = width;
	dest.h = height;
	SDL_RenderCopy(sdlRenderer, texture, &src, &dest);
}

/*void Sprite::make_flasheable(Uint8 strength){
	flashed = drawing;
	flashed.flash(strength);
	temp = drawing;
	isFlashing = false;
}

void Sprite::make_grayscale(){
	grayscaled = drawing;
	grayscaled.grayscale();
	drawing = grayscaled;
}

void Sprite::hflip(){
	flipped = drawing;
	flipped.flip();
	drawing = flipped;
	source_x = drawing.get_drawing()->w-source_x-width;
}

void Sprite::flash(){
	if (isFlashing){
		drawing = temp;
		isFlashing = false;
	}
	else {
		drawing = flashed;
		isFlashing = true;
	}
}*/

void Sprite::load_image(char* path, ResourceManager *resourceManager){
	drawing.load_image(path,resourceManager);
}
