#ifndef VSSCREEN_H_
#define VSSCREEN_H_

#include "Music.h"
#include "Constants.h"
#include "UserInterface/Portrait.h"
#include "CurrentScreen.h"
#include "SoundFX.h"
#include "UserInterface/UserInterface.h"

class VsScreen : CurrentScreen{
private:
	static const Uint8 horizontalMargin = 24;
public:
	Music *music;
	SoundFX *sound;
	Portrait *portrait1;
	Portrait *portrait2;
	Sprite *vs;

	VsScreen () {};
	VsScreen(NewMatch *newMatch,ResourceManager *resourceManager){
		music = new Music();
		sound = new SoundFX();
		music->load((char *)M_VS,resourceManager);
		sound->load((char *)S_SHINY,resourceManager);
		portrait1 = new Portrait(horizontalMargin,-210,newMatch->getPlayer1Team());
		portrait1->load_image((char *)G_PORTRAITS,resourceManager);
		portrait2 = new Portrait(SCREEN_WIDTH-(horizontalMargin+80),SCREEN_HEIGHT+50,newMatch->getPlayer2Team());
		portrait2->load_image((char *)G_PORTRAITS,resourceManager);

		vs = new Sprite();
		vs->load_image((char *)G_UI,resourceManager);
		vs->set_x(SCREEN_WIDTH/2-72/2);
		vs->set_y(SCREEN_HEIGHT/2-60/2);
		vs->set_width(72);
		vs->set_height(60);
		vs->set_source_x(118);
		vs->set_source_y(0);
		//vs->make_flasheable(255);

		portrait2->load_image((char *)G_PORTRAITS,resourceManager);
		music->play();
	}
	void update();
	void draw(SDL_Renderer *sdlRenderer);
	int read_keyboard();
	void finish();
	bool get_destroyMe();
};

#endif /* VSSCREEN_H_ */
