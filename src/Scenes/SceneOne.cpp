#include "SceneOne.h"

void SceneOne::print(void)
{
	Scene::print();
	std::cout << "My counter:" << this->sceneOneCounter<< "\n";
}

int SceneOne::update(int userInput)
{
	Scene::update(userInput);
	this->sceneOneCounter++;
	return this->id;
}

void SceneOne::initialize()
{
	this->addTextEntity(1, "title");
	this->setTitleText("whatever");
}	

void SceneOne::setTitleText(std::string text)
{
	TextEntity* entity = dynamic_cast<TextEntity *>(this->entities[0].get());
	entity->setText(text);
}
