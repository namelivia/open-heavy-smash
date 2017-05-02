#include <iostream>
#include <string>
#include "SDL2/SDL.h"
#include "Entity.h"
#ifndef TEXTENTITY_H_
#define TEXTENTITY_H_

class TextEntity : public Entity{
private:
	std::string text;
public:
	TextEntity(unsigned id, std::string name) {
		this->id = id;
		this->name = name;
		this->text = "No text";
	}
	void print();
	void update();
	void draw(SDL_Renderer *sdlRenderer);
};

#endif /* TEXTENTITY_H_ */
