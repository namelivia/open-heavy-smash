#include "ResourceManager.h"

void ResourceManager::finish(){
}

SDL_Texture *ResourceManager::get_image(char *path){
	for (int i=0;i<5;i++){
		if (images[i].identificator == path)
			return images[i].image;
	}
	return NULL;
}

Mix_Music *ResourceManager::get_music(char *path){
	for (int i=0;i<5;i++){
		if (musics[i].identificator == path)
			return musics[i].music;
	}
	return NULL;
}

Mix_Chunk *ResourceManager::get_sound(char *path){
	for (int i=0;i<5;i++){
		if (sounds[i].identificator == path){
			return sounds[i].sound;
		}
	}
	return NULL;
}

int ResourceManager::load_image(char *path, SDL_Renderer *sdlRenderer){
	SDL_Surface *image = IMG_Load(path);
	if (image == NULL)
	{
 		printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
		return 1;
	}
	else {
		images[imagesIndex].identificator = path;
 		SDL_Texture *newTexture = SDL_CreateTextureFromSurface( sdlRenderer, image);
		if( newTexture == NULL ) {
			printf(
				"Unable to create texture from %s! SDL Error: %s\n",
				path,
				SDL_GetError()
			);
		}
		SDL_FreeSurface(image);
		images[imagesIndex].image = newTexture;
		imagesIndex++;
		return 0;
	}
}

int ResourceManager::load_music(char *path){
	Mix_Music *tmp;
	tmp = Mix_LoadMUS(path);
	if (tmp == NULL)
	{
		return 1;
	}
	else {
		musics[musicsIndex].identificator = path;
		musics[musicsIndex].music = tmp;
		musicsIndex++;
		return 0;
	}
}

int ResourceManager::load_sound(char *path){
	Mix_Chunk *tmp;
	tmp = Mix_LoadWAV(path);
	if (tmp == NULL)
	{
		return 1;
	}
	else {
		sounds[soundsIndex].identificator = path;
		sounds[soundsIndex].sound = tmp;
		soundsIndex++;
		return 0;
	}
}
