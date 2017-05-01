#ifndef MUSIC_H_
#define MUSIC_H_
#include "SDL/SDL_mixer.h"
#include "ResourceManager.h"

class Music{
private:
	Mix_Music * music;
public:
	Music() {}
	int load(char* path,ResourceManager *resourceManager);
	int play();
	void free();
};

#endif /* MUSIC_H_ */
