#ifndef GAME_H_
#define GAME_H_

#include "SDL2/SDL.h"
#include "Match.h"
#include "VsScreen.h"
#include "MapScreen/MapScreen.h"
#include "SelectTeamScreen.h"
#include "GameState.h"
#include "NewMatch.h"
#include "Constants.h"
#include "Scene.h"
#include "Scenes/SceneOne.h"
#include <vector>
#include <memory>

class Game{
private:
	SDL_Window *sdlWindow;
	SDL_Renderer *sdlRenderer;
	std::vector<std::unique_ptr<Scene>> scenes;
	/*
	Match match;
	NewMatch *newMatch;
	VsScreen vsScreen;
	MapScreen mapScreen;
	SelectTeamScreen selectTeamScreen;
	*/
	SDL_Event event;
	ResourceManager *resourceManager;
	GameState *gameState;
	bool exit;
	int currentScreen;
	int sceneIndex;

	int initSDL();
	int initWindow();
	int initRenderer();
	int initSdlImage();
	int initMixer();

	int loadImages();
	int loadMusic();
	int loadSoundEffects();

	int readKeyboard();
  int fps_sync();

public:

	int init();
	void loop();
	void finish();
	void setUpFirstScene();
	void setUpSecondScene();
	void setUpThirdScene();
};

#endif /* GAME_H_ */
