#include "Stats.h"

void Stats::set_color(int color){
	if (color<0 || color>2)
		return;
	background->set_source_x(0);
	background->set_source_y(65);
	sp->set_source_x(40+width*color);
	sp->set_source_y(65);
	po->set_source_x(40+width*color);
	po->set_source_y(65);
	de->set_source_x(40+width*color);
	de->set_source_y(65);
}

void Stats::set_country(int country){
	if (country<0 || country>9)
		return;

	currentSp = teamStats->getSp(country);
	currentPo = teamStats->getPo(country);
	currentDe = teamStats->getDe(country);
}

void Stats::load_image(char *path, ResourceManager *resourceManager){
	background->load_image(path,resourceManager);
	sp->load_image(path,resourceManager);
	po->load_image(path,resourceManager);
	de->load_image(path,resourceManager);
}

void Stats::draw(SDL_Surface *screen){
	background->draw(screen);
	sp->draw(screen);
	po->draw(screen);
	de->draw(screen);
}

void Stats::update(){
 if (po->get_height()!=currentPo){
	 if (po->get_height()<currentPo) po->set_height(po->get_height()+1);
	 else po->set_height(po->get_height()-1);
 }

 if (sp->get_height()!=currentSp){
 	 if (sp->get_height()<currentSp) sp->set_height(sp->get_height()+1);
 	 else sp->set_height(sp->get_height()-1);
 }

 if (de->get_height()!=currentDe){
 	 if (de->get_height()<currentDe) de->set_height(de->get_height()+1);
 	 else de->set_height(de->get_height()-1);
 }

	set_position(background->get_x(),background->get_y());
}

void Stats::set_position(int x, int y){
	background->set_x(x);
	background->set_y(y);
	sp->set_x(x+3);
	sp->set_y(y+83-sp->get_height());
	po->set_x(x+5+width);
	po->set_y(y+83-po->get_height());
	de->set_x(x+7+2*width);
	de->set_y(y+83-de->get_height());
}

