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
	if (userInput == 4) {
		this->setTitleText("whatever");
	}
	return this->id;
}

void SceneOne::setTitleText(std::string text)
{
	TextEntity* entity = dynamic_cast<TextEntity *>(this->entities[0].get());
	entity->setText(text);
}
