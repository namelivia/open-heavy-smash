#include "Entity.h"

void Entity::print()
{
	std::cout << "|-[ENTITY]\n";
	std::cout << "|-Name:" << this->name << "\n";
	std::cout << "|-Id:" << this->id << "\n";
	std::cout << "|-Counter:" << this->counter << "\n";
}

void Entity::update()
{
	this->counter++;
}

void Entity::draw(SDL_Renderer *sdlRenderer)
{
	std::cout << "Drawing Entity ID:" << this->id << "\n";
}
