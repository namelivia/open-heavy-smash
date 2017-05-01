#include "PlayerUI.h"

void PlayerUI::draw(SDL_Surface *screen){
	powerbar->draw(screen);
	score->draw(screen);
	flag->draw(screen);
}

void PlayerUI::load_image(char *path,ResourceManager *resourceManager){
	powerbar->load_image(path,resourceManager);
	score->load_image(path,resourceManager);
	flag->load_image(path,resourceManager);
}

int PlayerUI::get_width(){
	return this->flag->get_width()+this->score->get_width()+this->powerbar->get_width();
}

int PlayerUI::get_height(){
	return this->flag->get_height();
}

void PlayerUI::set_power(int power){
	return this->powerbar->set_power(power);
}

void PlayerUI::set_score(int score){
	return this->score->set_score(score);
}
