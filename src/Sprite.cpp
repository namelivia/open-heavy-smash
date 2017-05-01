/*
 * Sprite.cpp
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#include "Sprite.h"
#include "Camara.h"
#include "Constantes.h"

void Sprite::set_source_x(Uint16 nuevo_x){source_x=nuevo_x;}
void Sprite::set_source_y(Uint16 nuevo_y){source_y=nuevo_y;}
void Sprite::set_width(Uint16 nuevo_x){width=nuevo_x;}
void Sprite::set_height(Uint16 nuevo_y){height=nuevo_y;}
Uint16 Sprite::get_source_x(){return source_x;}
Uint16 Sprite::get_source_y(){return source_y;}
Uint16 Sprite::get_width(){return width;}
Uint16 Sprite::get_height(){return height;}
void Sprite::set_x(int nuevo_x){x=nuevo_x;}
void Sprite::set_y(int nuevo_y){y=nuevo_y;}
int Sprite::get_x(){return x;}
int Sprite::get_y(){return y;}
void Sprite::draw(SDL_Surface *screen,Camara *camara){
	SDL_Rect fuente = {source_x,source_y, width, height};
	SDL_Rect rect = {x-camara->get_x(),y-camara->get_y(),0,0};
	SDL_BlitSurface (dibujo.get_dibujo(),&fuente,screen, &rect);
}
void Sprite::draw(SDL_Surface *screen){
	SDL_Rect fuente = {source_x,source_y, width, height};
	SDL_Rect rect = {x,y,0,0};
	SDL_BlitSurface (dibujo.get_dibujo(),&fuente,screen, &rect);}

void Sprite::make_flasheable(Uint8 strength){
	flashed = dibujo;
	flashed.flash(strength);
	temp = dibujo;
	isFlashing = false;
}

void Sprite::make_grayscale(){
	grayscaled = dibujo;
	grayscaled.grayscale();
	dibujo = grayscaled;
}

void Sprite::hflip(){
	flipped = dibujo;
	flipped.flip();
	dibujo = flipped;
	source_x = dibujo.get_dibujo()->w-source_x-width;
}

void Sprite::flash(){
	if (isFlashing){
		dibujo = temp;
		isFlashing = false;
	}
	else {
		dibujo = flashed;
		isFlashing = true;
	}
}

void Sprite::load_image(char* path, ResourceManager *resourceManager){
	dibujo.load_image(path,resourceManager);
}
