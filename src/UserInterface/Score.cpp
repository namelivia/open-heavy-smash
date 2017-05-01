#include "Score.h"

void Score::load_image(char* path,ResourceManager *resourceManager){
	background.load_image(path,resourceManager);
	numbers[0].load_image(path,resourceManager);
	numbers[1].load_image(path,resourceManager);
}

void Score::draw(SDL_Renderer *sdlRenderer){
	background.draw(sdlRenderer);
	numbers[0].draw(sdlRenderer);
	numbers[1].draw(sdlRenderer);
}

void Score::set_score(Uint8 score){
	if (score<0 || score>99)
		return;
	numbers[0].set_source_x(((score/10)%5)*11);
	numbers[0].set_source_y(60+(((score/10)/5)*15));
	numbers[1].set_source_x(((score%10)%5)*11);
	numbers[1].set_source_y(60+(((score%10)/5)*15));
}

void Score::set_position(Uint16 x, Uint16 y){
	background.set_x(x);
	background.set_y(y);
	background.set_source_x(45);
	background.set_source_y(24);
	background.set_width(width);
	background.set_height(height);

	numbers[0].set_x(x+3);
	numbers[0].set_y(y+4);
	numbers[0].set_width(11);
	numbers[0].set_height(15);

	numbers[1].set_x(x+17);
	numbers[1].set_y(y+4);
	numbers[1].set_width(11);
	numbers[1].set_height(15);
}

int Score::get_width(){
	return width;
}

int Score::get_height(){
	return height;
}
