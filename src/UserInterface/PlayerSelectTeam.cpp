#include "PlayerSelectTeam.h"

void PlayerSelectTeam::draw(SDL_Surface *screen){
	portrait->draw(screen);
	frame->draw(screen);
	playerName->draw(screen);
	grid->draw(screen);
	stats->draw(screen);
	captain->draw(screen);
}

void PlayerSelectTeam::load_image(char *path_selectTeam,char *path_ui,char *path_portraits, ResourceManager *resourceManager){
	portrait->load_image(path_portraits,resourceManager);
	frame->load_image(path_ui,resourceManager);
	playerName->load_image(path_selectTeam,resourceManager);
	grid->load_image(path_selectTeam,resourceManager);
	stats->load_image(path_selectTeam,resourceManager);
	captain->load_image(path_selectTeam,resourceManager);
}

int PlayerSelectTeam::get_width(){
	return this->portrait->get_width();
}

int PlayerSelectTeam::get_height(){
	return this->portrait->get_height();
}

void PlayerSelectTeam::update(){
	stats->update();
}

void PlayerSelectTeam::set_team(int team){
	portrait->set_country(team);
	captain->set_country(team);
	stats->set_country(team);
}
