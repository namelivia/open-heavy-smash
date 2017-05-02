#include <iostream>
#include <string>
#include "SDL2/SDL.h"
#include "Entity.h"
#include "Sprite.h"
#ifndef IMAGEENTITY_H_
#define IMAGEENTITY_H_

class ImageEntity : public Entity{
private:
	std::string path;
	Sprite sprite;
public:
	ImageEntity(unsigned id, std::string name) {
		this->id = id;
		this->name = name;
		this->path = "No path";
	}
	void print();
	void update();
	void load_image(char* path,ResourceManager *resourceManager);
	void draw(SDL_Renderer *sdlRenderer);
};

#endif /* IMAGEENTITY_H_ */
