#include "Music.h"
#include <iostream>
#include "SDL/SDL_mixer.h"

using namespace std;

int Music::load(char* path,ResourceManager *resourceManager){
	music = resourceManager->get_music(path);
	return 0;
}

int Music::play(){
	if(Mix_PlayMusic(music, -1) == -1) {
			cerr<<Mix_GetError();
			cerr<<"\n";
		    return 1;
		  }
	return 0;
}

void Music::free(){Mix_FreeMusic(music);}
