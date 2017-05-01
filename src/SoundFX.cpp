#include "SoundFX.h"
#include <iostream>
#include "SDL2/SDL_mixer.h"

using namespace std;

int SoundFX::load(char* path,ResourceManager *resourceManager){
	sound = resourceManager->get_sound(path);
	return 0;
}

int SoundFX::play(){
	if(Mix_PlayChannel(-1, sound, 0) == -1) {
			cerr<<Mix_GetError();
			cerr<<"\n";
		    return 1;
		  }
	return 0;
}

void SoundFX::free(){/*Mix_FreeMusic(musica);*/}
