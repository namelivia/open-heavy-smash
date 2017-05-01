#include "Game.h"

using namespace std;

void Game::init(){
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		 printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	};
	printf("Started\n");
	currentScreen = 0;
	gameState = new GameState();
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
	}
	sdlRenderer = SDL_CreateRenderer(
		sdlWindow,
		-1,
		SDL_RENDERER_ACCELERATED //TODO: Renderer flags
	);
	if(sdlRenderer == NULL ) {
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError()); 
	}
	SDL_SetRenderDrawColor(sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
		cerr<<"SDL_Image could not start\n";
	}

	if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 1, 4096)!=0){
		cerr<<"Audio could not start\n";
	}

	//Resource loading
	this->resourceManager = new ResourceManager();

	//Graphics
	resourceManager->load_image((char *)G_SELECTSCREEN, sdlRenderer);
	resourceManager->load_image((char *)G_UI, sdlRenderer);
	resourceManager->load_image((char *)G_PORTRAITS, sdlRenderer);
	resourceManager->load_image((char *)G_WORLDMAP, sdlRenderer);
	resourceManager->load_image((char *)G_INTRO, sdlRenderer);

	//Music
	resourceManager->load_music((char *)M_TEAMSELECTION);
	resourceManager->load_music((char *)M_USA);
	resourceManager->load_music((char *)M_VS);

	//Sound
	resourceManager->load_sound((char *)S_CURSOR);
	resourceManager->load_sound((char *)S_SHINY);

	//Resource load finished

	this->newMatch = new NewMatch(0,0,0);

	SelectTeamScreen newSelectTeamScreen(10,resourceManager,gameState);
	selectTeamScreen = newSelectTeamScreen;
	exit = false;
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
		SDL_RenderPresent(sdlRenderer);
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
