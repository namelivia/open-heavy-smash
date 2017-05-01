/*
 * Personaje.h
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#ifndef PERSONAJE_H_
#define PERSONAJE_H_

#include "Sprite.h"
#include "Constantes.h"

class Personaje {
private:
	int paso;
	int direccion;
	static const int velocidad = 1;

public:
	Sprite sprite;

	Personaje(int x_inicial,int y_inicial) {sprite.set_x(x_inicial*ANCHO_TILE);sprite.set_y(y_inicial*ALTO_TILE);paso=0;}

	void mover_personaje(int que_direccion);
	void draw(SDL_Surface *screen,Camara *camara);
	int get_velocidad();
	void quedar_quieto();
};

#endif /* PERSONAJE_H_ */
