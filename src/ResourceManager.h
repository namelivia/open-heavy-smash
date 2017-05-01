/*
 * ResourceManager.h
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"

class ResourceManager {
private:
	typedef struct {
		SDL_Surface *image;
		char *identificator;
	} ImageResource;

	typedef struct {
		Mix_Music *music;
		char *identificator;
	} MuiscResource;

	typedef struct {
		Mix_Chunk *sound;
		char *identificator;
	} SoundResource;


	ImageResource images[5];
	int imagesIndex;

	MuiscResource musics[5];
	int musicsIndex;

	SoundResource sounds[5];
	int soundsIndex;

public:
	ResourceManager () {
		imagesIndex = 0;
		musicsIndex = 0;
		soundsIndex = 0;
	};

	int load_image(char *path);
	int load_music(char *path);
	int load_sound(char *path);
	SDL_Surface *get_image(char *path);
	Mix_Music *get_music(char *path);
	Mix_Chunk *get_sound(char *path);
	void terminar();
};

#endif /* RESOURCEMANAGER_H_ */
