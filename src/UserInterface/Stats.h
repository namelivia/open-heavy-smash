#ifndef STATS_H_
#define STATS_H_

#include "../Sprite.h"
#include "../TeamStats.h"

class Stats {
private:
	static const Uint16 width = 10;
	static const Uint16 bgWidth = 40;
	static const Uint16 bgHeight = 102;

	int currentSp;
	int currentPo;
	int currentDe;

	Sprite *sp;
	Sprite *po;
	Sprite *de;
	Sprite *background;
	TeamStats *teamStats;

public:

	Stats() {
	}

	Stats(int x,int y,int color){
		this->teamStats = new TeamStats();
		this->background = new Sprite();
		this->sp = new Sprite();
		this->po = new Sprite();
		this->de = new Sprite();
		background->set_width(bgWidth);
		background->set_height(bgHeight);
		sp->set_width(width);
		po->set_width(width);
		de->set_width(width);
		set_country(0);
		set_position(x,y);
		set_color(color);

	}

	void set_color(int name);
	void set_position(int x, int y);
	void draw(SDL_Surface *screen);
	void load_image(char *path, ResourceManager *resourceManager);
	void set_country(int country);
	void update();
};
#endif /* STATS_H_ */
