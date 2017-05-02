#include <iostream>
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#ifndef ENTITY_H_
#define ENTITY_H_

class Entity{
protected:
	std::string name;
	unsigned id;
	unsigned counter;
	int x;
	int y;
public:
	Entity() {
		this->name = "Unnamed entity";
		this->counter = 0;
		this->x = 0;
		this->y = 0;
	}
	virtual void print();
	virtual void update();
	virtual void draw(SDL_Renderer *sdlRenderer);
};

#endif /* ENTITY_H_ */
