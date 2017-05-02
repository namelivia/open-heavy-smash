#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "SDL2/SDL.h"
#include "Entity.h"
#ifndef SCENE_H_
#define SCENE_H_

class Scene {
protected:
	std::string name;
	unsigned id;
	unsigned counter;
	std::vector<std::unique_ptr<Entity>> entities;
public:
	Scene() {
		this->name = "Unnamed scene";
		this->counter = 0;
	}
	virtual void print(void)=0;
	virtual int update(int userInput);
	virtual void draw(SDL_Renderer *sdlRenderer);
	virtual void addEntity(int id, std::string name);
};

#endif /* SCENE_H_ */
