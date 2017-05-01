#include "VsScreen.h"
#include "Constants.h"

void VsScreen::draw(SDL_Renderer *sdlRenderer){

	portrait1->draw(sdlRenderer);
	portrait2->draw(sdlRenderer);
	vs->draw(sdlRenderer);
}

int VsScreen::read_keyboard(){
	return 0;
}

void VsScreen::update(){
	CurrentScreen::update();
	if (portrait1->get_y()<SCREEN_HEIGHT/2-80)
			portrait1->set_y(portrait1->get_y()+1);
	if (portrait2->get_y()>SCREEN_HEIGHT/2-80)
			portrait2->set_y(portrait2->get_y()-1);
	if (CurrentScreen::get_cycles()>600)
		CurrentScreen::set_destroyMe(true);

	if (CurrentScreen::get_cycles()==400){
		//vs->flash();
		sound->play();
	}

	/*if (CurrentScreen::get_cycles()==403)
		vs->flash();*/
}

bool VsScreen::get_destroyMe(){
	return CurrentScreen::get_destroyMe();
}

void VsScreen::finish(){
	music->free();
	sound->free();
}
