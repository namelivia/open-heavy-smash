#ifndef PLAYERUI_H_
#define PLAYERUI_H_

#include "Flag.h"
#include "PowerBar.h"
#include "Score.h"
#include "SpriteText.h"

class PlayerUI {
private:

public:
	Flag *flag;
	PowerBar *powerbar;
	Score *score;
	//SpriteText playerName;
	//SpriteText teamName;

	PlayerUI(){
	}
	PlayerUI(int x, int y, bool right, int power, int score, int team){
		if (right){
			this ->powerbar = new PowerBar(x,y,power);
			this->score = new Score(x+this->powerbar->get_width(),y,score);
			this->flag = new Flag(x+this->powerbar->get_width()+this->score->get_width(),y,team);
		}
		else {
			this->flag = new Flag(x,y,team);
			this->score = new Score(x+this->flag->get_width(),y,score);
			this ->powerbar = new PowerBar(x+this->flag->get_width()+this->score->get_width(),y,power);

		}
	}
	void draw(SDL_Renderer *sdlRenderer);
	void load_image(char *path,ResourceManager *resourceManager);
	int get_width();
	int get_height();
	void set_power(int power);
	void set_score(int score);

};

#endif /* PLAYERUI_H_ */
