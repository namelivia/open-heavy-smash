#ifndef MATCH_H_
#define MATCH_H_

#include "Camera.h"
#include "Music.h"
#include "Constants.h"
#include "CurrentScreen.h"
#include "UserInterface/Portrait.h"
//#include "Scenery.h"
//#include "Character.h"
//#include "Window.h"
#include "UserInterface/UserInterface.h"

class Match : CurrentScreen{
private:
public:
	Camera *camera;
	//Character *character;
	//Scenery *scenery;
	Music *music;
	UserInterface *userInterface;
	MatchState *matchState;

	Match () {};
	Match(NewMatch *newMatch,ResourceManager *resourceManager){
		//scenery = new Scenery();
		//character = new Character(45,1);
		//window_zone = new Window(0,SCREEN_HEIGHT-1.5*TILE_HEIGHT,3,12,500);
		camera = new Camera();
		music = new Music();
		matchState = new MatchState(newMatch->getTime());
		userInterface = new UserInterface(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,newMatch);
		//window_zone ->set_mensaje(nombre);
		//scenery->load_scenery(path_nivel);
		music->load((char *)M_USA,resourceManager);
		//character->sprite.dibujo.load_image(path_character);
		userInterface->load((char *)G_UI,resourceManager);

		music->play();
	}
	void update_camera();
	virtual void update();
	virtual void draw(SDL_Renderer *sdlRenderer);
	virtual int read_keyboard();
	virtual void finish();
};

#endif /* MATCH_H_ */
