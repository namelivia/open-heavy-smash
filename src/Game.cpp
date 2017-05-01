#include "Game.h"

using namespace std;

void Game::init(){
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	printf("Started\n");
	currentScreen = 0;
	gameState = new GameState();
	screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT, 16, SDL_HWSURFACE);
	if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 1, 4096)!=0){
		cerr<<"Audio could not start\n";
	}
	SDL_WM_SetCaption("Heavy Smash","Heavy Smash");

	//Resource loading
	this->resourceManager = new ResourceManager();

	//Graphics
	resourceManager->load_image((char *)G_SELECTSCREEN);
	resourceManager->load_image((char *)G_UI);
	resourceManager->load_image((char *)G_PORTRAITS);
	resourceManager->load_image((char *)G_WORLDMAP);
	resourceManager->load_image((char *)G_INTRO);

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
			if (event.type == SDL_QUIT) exit = true;
		}

		int loops = fps_sync();
		int i;
		if (currentScreen ==0) {
			for (i=0;i<loops;i++) selectTeamScreen.read_keyboard();
			selectTeamScreen.update();
			selectTeamScreen.draw(screen);
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
			mapScreen.draw(screen);
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
			vsScreen.draw(screen);
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
			match.draw(screen);
		}
		SDL_Flip(screen);
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
	//match.finish();
	vsScreen.finish();
	Mix_CloseAudio();
	SDL_Quit();
}
