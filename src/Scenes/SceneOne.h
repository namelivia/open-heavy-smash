#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "SDL2/SDL.h"
#include "../Scene.h"
#include "../ResourceManager.h"
#ifndef SCENE_ONE_H_
#define SCENE_ONE_H_

class SceneOne : public Scene {
private:
	void setTitleText(std::string text);
protected:
	unsigned sceneOneCounter;
public:
	SceneOne(
			unsigned id,
			std::string name,
			std::shared_ptr<ResourceManager> &resourceManager
	) {
		this->id = id;
		this->name = name;
		this->sceneOneCounter = 100;
		this->resourceManager = resourceManager;
		this->addTextEntity(1, "title");
	}
	void print(void);
	int update(int userInput);
};

#endif /* SCENE_ONE_H_ */
