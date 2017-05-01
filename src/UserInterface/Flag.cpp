/*
 * Flag.cpp
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#include "Flag.h"

void Flag::set_country(int country){
	if (country<0 || country>9)
		return;
	set_source_x((country/2)*width);
	set_source_y(90+(country%2)*height);
}

void Flag::set_position(int x, int y){
	set_x(x);
	set_y(y);
	set_width(width);
	set_height(height);
}

