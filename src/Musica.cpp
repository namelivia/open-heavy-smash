/*
 * Musica.cpp
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#include "Musica.h"
#include <iostream>
#include "SDL/SDL_mixer.h"

using namespace std;

int Musica::cargar(char* path,ResourceManager *resourceManager){
	musica = resourceManager->get_music(path);
	return 0;
}

int Musica::reproducir(){
	if(Mix_PlayMusic(musica, -1) == -1) {
			cerr<<Mix_GetError();
			cerr<<"\n";
		    return 1;
		  }
	return 0;
}

void Musica::liberar(){Mix_FreeMusic(musica);}
