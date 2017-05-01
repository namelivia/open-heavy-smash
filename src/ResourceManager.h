#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

class ResourceManager {
private:
	typedef struct {
		SDL_Texture *image;
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

	int load_image(char *path, SDL_Renderer *sdlRenderer);
	int load_music(char *path);
	int load_sound(char *path);
	SDL_Texture *get_image(char *path);
	Mix_Music *get_music(char *path);
	Mix_Chunk *get_sound(char *path);
	void finish();
};

#endif /* RESOURCEMANAGER_H_ */
