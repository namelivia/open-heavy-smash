/*
 * SoundFX.h
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#ifndef SOUNDFX_H_
#define SOUNDFX_H_
#include "SDL/SDL_mixer.h"
#include "ResourceManager.h"

class SoundFX{
private:
	Mix_Chunk *sound;
public:
	SoundFX() {}
	int load(char* path,ResourceManager *resourceManager);
	int play();
	void free();
};

#endif /* SOUNDFX_H_ */
