/*
 * PlayerName.cpp
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#include "PlayerName.h"

void PlayerName::set_name(int name){
	if (name<0 || name>2)
		return;
	set_source_x(215);
	set_source_y(48+height*name);
}

void PlayerName::set_position(int x, int y){
	set_x(x);
	set_y(y);
	set_width(width);
	set_height(height);
}

