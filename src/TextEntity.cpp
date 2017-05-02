#include "TextEntity.h"

void TextEntity::print()
{
	std::cout << "|-[TEXTENTITY]\n";
	std::cout << "|-Name:" << this->name << "\n";
	std::cout << "|-Id:" << this->id << "\n";
	std::cout << "|-Counter:" << this->counter << "\n";
}

void TextEntity::update()
{
	Entity::update();
}

void TextEntity::draw(SDL_Renderer *sdlRenderer)
{
	std::cout << "Drawing The text Entity Content:" << this->text << "\n";
	//TODO: Currently I have no ttf fonfs
	TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);
	SDL_Color White = {255, 255, 255};
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, this->text.c_str(), White);
	SDL_Texture* Message = SDL_CreateTextureFromSurface(sdlRenderer, surfaceMessage);
	SDL_Rect Message_rect;
	Message_rect.x = this->x;
	Message_rect.y = this->y;
	Message_rect.w = 100;
	Message_rect.h = 100;
	SDL_RenderCopy(sdlRenderer, Message, NULL, &Message_rect);
}
