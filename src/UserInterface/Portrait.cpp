/*
 * Portrait.cpp
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#include "Portrait.h"

void Portrait::load_image(char* path,ResourceManager *resourceManager){
	dibujo.load_image(path,resourceManager);
}

void Portrait::set_country(int country){
	if (country<0 || country>9)
		return;
	set_source_x((country/2)*80);
	set_source_y((country%2)*160);
}

int Portrait::get_width(){
	return width;
}

int Portrait::get_height(){
	return height;
}

void Portrait::set_position(int x, int y){
	set_x(x);
	set_y(y);
	set_width(width);
	set_height(height);
}

