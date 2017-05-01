/*
 * Juego.cpp
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#include "Juego.h"

using namespace std;

void Juego::iniciar(){
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
		printf("Started\n");
		currentScreen = 0;
		gameState = new GameState();
		screen = SDL_SetVideoMode(ANCHO_PANTALLA,ALTO_PANTALLA, 16, SDL_HWSURFACE);
		if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 1, 4096)!=0){
			cerr<<"El audio no puede iniciarse\n";
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

		//Fin de la carga de recursos

		this->newMatch = new NewMatch(0,0,0);

		SelectTeamScreen newSelectTeamScreen(10,resourceManager,gameState);
		selectTeamScreen = newSelectTeamScreen;
		salir = false;
}

void Juego::bucle(){
	while(not salir) {
	        while (SDL_PollEvent(&event)) {
	            if (event.type == SDL_QUIT) salir = true;
	            }

	int repeticiones = fps_sincronizar();
	int i;
	if (currentScreen ==0) {
		for (i=0;i<repeticiones;i++) selectTeamScreen.leer_teclado();
			selectTeamScreen.update();
			selectTeamScreen.draw(screen);
			if (selectTeamScreen.get_destroyMe()){
				if (gameState->getLastDefeated() == -1)
				{
					gameState->Defeat(selectTeamScreen.get_selectedTeam());
				}
				newMatch->setPlayer1Team(selectTeamScreen.get_selectedTeam());
				newMatch->setPlayer2Team(2);
				selectTeamScreen.terminar();
				currentScreen++;
				MapScreen newMapScreen(newMatch,resourceManager,gameState);
				mapScreen = newMapScreen;
			}
	}
	else if (currentScreen == 1){
		for (i=0;i<repeticiones;i++) mapScreen.leer_teclado();
			mapScreen.update();
			mapScreen.draw(screen);
		if (mapScreen.get_destroyMe()){
			mapScreen.terminar();
					currentScreen++;
					newMatch->setTime(90);
					VsScreen newVsScreen(newMatch,resourceManager);
					vsScreen = newVsScreen;
				}
	}
	else if (currentScreen == 2){
		for (i=0;i<repeticiones;i++) vsScreen.leer_teclado();
		vsScreen.update();
		vsScreen.draw(screen);
		if (vsScreen.get_destroyMe()){
			vsScreen.terminar();
			currentScreen++;
			Match selectedMatch(newMatch,resourceManager);
			match = selectedMatch;
		}
	}
	else {
		for (i=0;i<repeticiones;i ++) match.leer_teclado();
		match.update();
		match.draw(screen);
	}
    SDL_Flip(screen);
	}
}

int Juego::fps_sincronizar (void)
{
	static int t;
	static int tmp;
	static int tl = 0;
	t = SDL_GetTicks ();
	if (t - tl >= FRECUENCIA){
		tmp = (t - tl) / FRECUENCIA;
		tl += tmp * FRECUENCIA;
		return tmp;
	}
	else{
		SDL_Delay (FRECUENCIA - (t - tl));
		tl += FRECUENCIA;
		return 1;
	}
}

void Juego::finalizar(){
    //match.terminar();
	vsScreen.terminar();
    Mix_CloseAudio();
    SDL_Quit();
}
