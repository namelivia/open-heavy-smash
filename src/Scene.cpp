#include "Scene.h"

void Scene::print()
{
	std::cout << "[SCENE]\n";
	std::cout << "Name:" << this->name << "\n";
	std::cout << "Id:" << this->id << "\n";
	std::cout << "Counter:" << this->counter << "\n";
	std::cout << "[Entities]\n";
	for(auto const& entity: this->entities) {
		entity->print();
	}
}

int Scene::update(int userInput)
{
	this->counter++;
	for(auto const& entity: this->entities) {
		entity->update();
	}
	int nextSceneId = this->id;
	if (this->counter > 500) {
		nextSceneId ++;
	}
	return this->id;
}

void Scene::draw(SDL_Renderer *sdlRenderer)
{
	for(auto const& entity: this->entities) {
		entity->draw(sdlRenderer);
	}
}

void Scene::addEntity()
{
	this->entities.push_back(std::make_unique<Entity>(1, "foo"));
}
