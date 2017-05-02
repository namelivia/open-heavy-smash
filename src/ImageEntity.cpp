#include "ImageEntity.h"

void ImageEntity::print()
{
	std::cout << "|-[IMAGEENTITY]\n";
	std::cout << "|-Name:" << this->name << "\n";
	std::cout << "|-Id:" << this->id << "\n";
	std::cout << "|-Counter:" << this->counter << "\n";
}

void ImageEntity::update()
{
	Entity::update();
}

void ImageEntity::draw(SDL_Renderer *sdlRenderer)
{
	std::cout << "Drawing The image Entity from file:" << this->path << "\n";
	this->sprite.draw(sdlRenderer);
}

void ImageEntity::load_image(char *path, ResourceManager *resourceManager){
	this->sprite.load_image(path,resourceManager);
}
