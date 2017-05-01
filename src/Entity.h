#include <iostream>
#include <string>
#include "SDL2/SDL.h"
#ifndef ENTITY_H_
#define ENTITY_H_

class Entity{
private:
	std::string name;
	unsigned id;
	unsigned counter;
	int x;
	int y;
public:
	Entity() {}
	Entity(unsigned id, std::string name) {
		this->id = id;
		this->name = name;
		this->counter = 0;
		this->x = 0;
		this->y = 0;
	}
	void print();
	void update();
	void draw(SDL_Renderer *sdlRenderer);
};

#endif /* Entity_H_ */
