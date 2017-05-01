#ifndef SELECTTEAMSCREEN_H_
#define SELECTTEAMSCREEN_H_

#include "Music.h"
#include "Constants.h"
#include "UserInterface/Portrait.h"
#include "CurrentScreen.h"
#include "SoundFX.h"
#include "UserInterface/Clock.h"
#include "UserInterface/TiledBackground.h"
#include "UserInterface/SmallFlag.h"
#include "UserInterface/FlagSelector.h"
#include "UserInterface/PlayerSelectTeam.h"
#include "SelectTeamState.h"
#include "GameState.h"

class SelectTeamScreen : CurrentScreen{
private:
	static const Uint8 horizontalMargin = 24;
public:
	Music *music;
	SoundFX *sound;
	Clock *clock;
	TiledBackground *background;
	SmallFlag flags[10];
	FlagSelector *flagSelector;
	PlayerSelectTeam *player1SelectTeam;
	PlayerSelectTeam *player2SelectTeam;
	SelectTeamState *state;
	int pressedKey;
	int maxTime;
	int selectedFlag;

	SelectTeamScreen () {};
	SelectTeamScreen(int time,ResourceManager *resourceManager,GameState *gameState){
		music = new Music();
		sound = new SoundFX();
		music->load((char *)M_TEAMSELECTION,resourceManager);
		sound->load((char*)S_CURSOR,resourceManager);
		this->clock = new Clock((SCREEN_WIDTH-30)/2,14,10);
		this->background = new TiledBackground();
		this->flagSelector = new FlagSelector(0,0);
		this->player1SelectTeam = new PlayerSelectTeam(SCREEN_WIDTH/4,SCREEN_HEIGHT/2,false,4,0);
		this->player2SelectTeam = new PlayerSelectTeam(3*(SCREEN_WIDTH/4),SCREEN_HEIGHT/2,true,3,1);
		this->maxTime = time;
		this->state = new SelectTeamState(time);
		pressedKey = 0;

		for(int i=0;i<10;i++){
			flags[i].load_image((char *)G_UI,resourceManager);
			flags[i].set_position((SCREEN_WIDTH-24)/2,56+17*i);
			flags[i].set_country(i);
			/*if (gameState->getDefeated(i))
				flags[i].make_grayscale();*/
		}

		selectedFlag=0;

		clock->load_image((char *)G_UI,resourceManager);
		flagSelector->load_image((char *)G_SELECTSCREEN,resourceManager);
		background->load_image((char *)G_SELECTSCREEN,resourceManager);
		player1SelectTeam->load_image((char *)G_SELECTSCREEN,(char *)G_UI,(char *)G_PORTRAITS,resourceManager);
		player2SelectTeam->load_image((char *)G_SELECTSCREEN,(char *)G_UI,(char *)G_PORTRAITS,resourceManager);

		SelectFlag(selectedFlag);
		music->play();


	}
	void update();
	void draw(SDL_Renderer *sdlRenderer);
	int read_keyboard();
	void finish();
	int get_selectedTeam();
	bool get_destroyMe();
	void SelectFlag(int whatFlag);
};

#endif /* SELECTTEAMSCREEN_H_ */
