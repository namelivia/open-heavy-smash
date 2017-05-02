#include "Game.h"

using namespace std;

int Game::initSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		 printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		 return 1;
	};
	return 0;
}

int Game::initRenderer()
{
	sdlRenderer = SDL_CreateRenderer(
		sdlWindow,
		-1,
		SDL_RENDERER_ACCELERATED //TODO: Renderer flags
	);
	if(sdlRenderer == NULL ) {
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError()); 
		return 1;
	}
	return 0;
}

int Game::initWindow()
{
	sdlWindow = SDL_CreateWindow(
		"SDL Tutorial",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		0 //TODO: Window flags
	);
	if(sdlWindow == NULL ) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError()); 
		return 1;
	}
	return 0;
}

int Game::initSdlImage()
{
	int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
		printf("SDL_Image could not start\n"); 
		return 1;
	}
	return 0;
}

int Game::loadImages()
{
	resourceManager.get()->load_image((char *)G_SELECTSCREEN, sdlRenderer);
	resourceManager.get()->load_image((char *)G_UI, sdlRenderer);
	resourceManager.get()->load_image((char *)G_PORTRAITS, sdlRenderer);
	resourceManager.get()->load_image((char *)G_WORLDMAP, sdlRenderer);
	resourceManager.get()->load_image((char *)G_INTRO, sdlRenderer);
	return 0;
}

int Game::loadMusic()
{
	resourceManager.get()->load_music((char *)M_TEAMSELECTION);
	resourceManager.get()->load_music((char *)M_USA);
	resourceManager.get()->load_music((char *)M_VS);
	return 0;
}

int Game::loadSoundEffects()
{
	resourceManager.get()->load_sound((char *)S_CURSOR);
	resourceManager.get()->load_sound((char *)S_SHINY);
	return 0;
}

int Game::initMixer()
{
	if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 1, 4096)!=0){
		printf("Audio could not start\n"); 
		return 1;
	}
	return 0;
}

int Game::init()
{
	if (
		Game::initSDL() > 0 ||
		Game::initWindow() > 0 ||
		Game::initRenderer() > 0 ||
		Game::initSdlImage() > 0 ||
		Game::initMixer() > 0
	) {
		return 1;
	}

	//Resource loading
	this->resourceManager = std::make_shared<ResourceManager>();
	if (
		Game::loadImages() > 0 ||
		Game::loadMusic() > 0 ||
		Game::loadSoundEffects() > 0
	) {
		return 1;
	}

	//Init other stuff
	//SDL_SetRenderDrawColor(sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	//printf("Started\n");
	currentScreen = 0;
	this->sceneIndex = 0;
	gameState = new GameState();

	//this->newMatch = new NewMatch(0,0,0);

	//SelectTeamScreen newSelectTeamScreen(10,resourceManager,gameState);
	//selectTeamScreen = newSelectTeamScreen;
	exit = false;
	this->scenes.push_back(
			std::make_unique<SceneOne>(
				0,
				"Scene 0",
				this->resourceManager
			)
	);
	return 0;
}

void Game::loop(){
	while(not exit) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				printf("Exiting...\n");
				exit = true;
			}
		}
		SDL_RenderClear(sdlRenderer);

		int loops = fps_sync();
		int key;
		for (int i=0;i<loops;i++) {
			key = Game::readKeyboard();
		}
		int nextScene = this->scenes[sceneIndex]->update(key);
		//this->scenes[sceneIndex]->print();
		this->scenes[sceneIndex]->draw(sdlRenderer);
		/*
		int i;
		if (currentScreen == 0) {
			for (i=0;i<loops;i++) {
				selectTeamScreen.read_keyboard();
			}
			selectTeamScreen.update();
			selectTeamScreen.draw(sdlRenderer);
			if (selectTeamScreen.get_destroyMe()){
				if (gameState->getLastDefeated() == -1)
				{
					gameState->Defeat(selectTeamScreen.get_selectedTeam());
				}
				newMatch->setPlayer1Team(selectTeamScreen.get_selectedTeam());
				newMatch->setPlayer2Team(2);
				selectTeamScreen.finish();
				currentScreen++;
				MapScreen newMapScreen(newMatch,resourceManager,gameState);
				mapScreen = newMapScreen;
			}
		}
		else if (currentScreen == 1){
			for (i=0;i<loops;i++) mapScreen.read_keyboard();
			mapScreen.update();
			mapScreen.draw(sdlRenderer);
			if (mapScreen.get_destroyMe()){
				mapScreen.finish();
				currentScreen++;
				newMatch->setTime(90);
				VsScreen newVsScreen(newMatch,resourceManager);
				vsScreen = newVsScreen;
			}
		}
		else if (currentScreen == 2){
			for (i=0;i<loops;i++) vsScreen.read_keyboard();
			vsScreen.update();
			vsScreen.draw(sdlRenderer);
			if (vsScreen.get_destroyMe()){
				vsScreen.finish();
				currentScreen++;
				Match selectedMatch(newMatch,resourceManager);
				match = selectedMatch;
			}
		}
		else {
			for (i=0;i<loops;i ++) match.read_keyboard();
			match.update();
			match.draw(sdlRenderer);
		}
		*/
		SDL_RenderPresent(sdlRenderer);
		sceneIndex = nextScene;
	}
}

int Game::fps_sync (void)
{
	static int t;
	static int tmp;
	static int tl = 0;
	t = SDL_GetTicks ();
	if (t - tl >= FREQ){
		tmp = (t - tl) / FREQ;
		tl += tmp * FREQ;
		return tmp;
	}
	else{
		SDL_Delay (FREQ - (t - tl));
		tl += FREQ;
		return 1;
	}
}

int Game::readKeyboard(){
	const Uint8 *keystate = SDL_GetKeyboardState(NULL);
	if (keystate[SDL_SCANCODE_UP]) return 1;
	else if (keystate[SDL_SCANCODE_DOWN])return 2;
	else if (keystate[SDL_SCANCODE_LEFT])return 3;
	else if (keystate[SDL_SCANCODE_RIGHT])return 4;
	else if (keystate[SDL_SCANCODE_RETURN]) return 5;
	else return 0;
}

void Game::finish(){
	SDL_DestroyRenderer(sdlRenderer);
	SDL_DestroyWindow(sdlWindow);
	//match.finish();
	//vsScreen.finish();
	Mix_CloseAudio();
	IMG_Quit();
	SDL_Quit();
	printf("Bye!\n");
}
