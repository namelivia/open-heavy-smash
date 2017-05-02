#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "SDL2/SDL.h"
#include "../Scene.h"
#ifndef SCENE_ONE_H_
#define SCENE_ONE_H_

class SceneOne : public Scene {
public:
	SceneOne(unsigned id, std::string name) {
		this->id = id;
		this->name = name;
		//this->addEntity(1, "foo");
	}
	void print(void);
};

#endif /* SCENE_ONE_H_ */
