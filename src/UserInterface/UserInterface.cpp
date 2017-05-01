#include "UserInterface.h"

void UserInterface::draw(SDL_Surface *screen){
	clock->draw(screen);
	player1UI->draw(screen);
	player2UI->draw(screen);
}
void UserInterface::load(char *path,ResourceManager *resourceManager){
	clock->load_image(path,resourceManager);
	player1UI->load_image(path,resourceManager);
	player2UI->load_image(path,resourceManager);
}

void UserInterface::update(MatchState *matchState){
	clock->set_time(matchState->getTime());
	player1UI->set_score(matchState->getPlayer1Score());
	player1UI->set_power(matchState->getPlayer1Power());
	player2UI->set_score(matchState->getPlayer2Score());
	player2UI->set_power(matchState->getPlayer2Power());
}
