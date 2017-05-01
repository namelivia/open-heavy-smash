#ifndef SCORE_H_
#define SCORE_H_

#include "../Sprite.h"

class Score {
private:
	static const Uint8 width = 31;
	static const Uint8 height = 24;

public:
	Sprite numbers[2];
	Sprite background;

	Score();
	Score(Uint16 x, Uint16 y, Uint8 score) {
		set_position(x,y);
		set_score(score);
	}
	void draw(SDL_Renderer *sdlRenderer);
	void load_image(char* path,ResourceManager *resourceManager);
	void set_score(Uint8 score);
	void set_position(Uint16 x,Uint16 y);
	int get_width();
	int get_height();
};

#endif /* SCORE_H_ */
