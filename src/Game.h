#ifndef GAME_H_
#define GAME_H_

#include "SDL/SDL.h"
#include "Match.h"
#include "VsScreen.h"
#include "MapScreen/MapScreen.h"
#include "SelectTeamScreen.h"
#include "GameState.h"
#include "NewMatch.h"
#include "Constants.h"

class Game{
private:
	SDL_Surface *screen;
	Match match;
	NewMatch *newMatch;
	VsScreen vsScreen;
	MapScreen mapScreen;
	SelectTeamScreen selectTeamScreen;
	SDL_Event event;
	ResourceManager *resourceManager;
	GameState *gameState;
	bool exit;
	int currentScreen;

public:

	void init();
	void loop();
	void finish();
  int fps_sync();
};

#endif /* GAME_H_ */
