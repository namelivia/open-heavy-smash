/*
 * Musica.h
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#ifndef MUSICA_H_
#define MUSICA_H_
#include "SDL/SDL_mixer.h"
#include "ResourceManager.h"

class Musica{
private:
	Mix_Music * musica;
public:
	Musica() {}
	int cargar(char* path,ResourceManager *resourceManager);
	int reproducir();
	void liberar();
};

#endif /* MUSICA_H_ */
