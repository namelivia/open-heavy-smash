#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "SDL2/SDL.h"
#include "Entity.h"
#ifndef SCENE_H_
#define SCENE_H_

class Scene {
private:
	std::string name;
	unsigned id;
	unsigned counter;
	std::vector<std::unique_ptr<Entity>> entities;
public:
	Scene() {};
	Scene(unsigned id, std::string name) {
		this->id = id;
		this->name = name;
		this->counter = 0;
	}
	void print();
	int update(int userInput);
	void draw(SDL_Renderer *sdlRenderer);
	void addEntity();
};

#endif /* SCENE_H_ */
