/*
 * SmallFlag.cpp
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#include "SmallFlag.h"

void SmallFlag::set_country(int country){
	if (country<0 || country>9)
		return;
	set_source_x((country/2)*24);
	set_source_y(138+(country%2)*16);
}

void SmallFlag::set_position(int x, int y){
	set_x(x);
	set_y(y);
	set_width(width);
	set_height(height);
}

