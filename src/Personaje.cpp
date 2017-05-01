/*
 * Personaje.cpp
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#include "Personaje.h"

void Personaje::mover_personaje(int que_direccion){
	switch(que_direccion){
		case 1:
			sprite.set_x(sprite.get_x()+velocidad);
			direccion = 0;
			if (paso >= 1) paso = 0;
			else paso++;
					break;
		case 2:
			sprite.set_x(sprite.get_x()-velocidad);
			direccion = 1;
			if (paso >= 1) paso = 0;
			else paso++;
					break;
		case 3:
			sprite.set_y(sprite.get_y()+velocidad);
			direccion = 2;
			if (paso >= 2) paso = 0;
			else paso++;
					break;
		case 4:
			sprite.set_y(sprite.get_y()-velocidad);
			direccion = 3;
			if (paso >= 2) paso = 0;
			else paso++;
					break;
	}
	switch (direccion){
	case 0:
		sprite.set_source_x(8+paso);
		break;
	case 1:
		sprite.set_source_x(0+paso);
		break;
	case 2:
			sprite.set_source_x(2+paso);
		break;
	case 3:
			sprite.set_source_x(5+paso);
		break;
	}
}

void Personaje::quedar_quieto(){
	switch (direccion){
	case 0:
		sprite.set_source_x(8);
		break;
	case 1:
		sprite.set_source_x(0);
		break;
	case 2:
			sprite.set_source_x(2);
		break;
	case 3:
			sprite.set_source_x(5);
		break;
	}
}

void Personaje::draw(SDL_Surface *screen,Camara *camara){
	sprite.draw(screen,camara);
}

int Personaje::get_velocidad(){
	return velocidad;
}
