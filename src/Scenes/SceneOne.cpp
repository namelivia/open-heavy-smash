#include "SceneOne.h"

void SceneOne::print(void)
{
	std::cout << "[SCENE_ONE]\n";
	std::cout << "Name:" << this->name << "\n";
	std::cout << "Id:" << this->id << "\n";
	std::cout << "Counter:" << this->counter << "\n";
	std::cout << "SceneOneCounter:" << this->sceneOneCounter << "\n";
	std::cout << "[Entities]\n";
	for(auto const& entity: this->entities) {
		entity->print();
	}
}

int SceneOne::update(int userInput)
{
	Scene::update(userInput);
	this->sceneOneCounter++;
	return this->id;
}
