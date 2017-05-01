/*
 * Frame.cpp
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#include "Frame.h"

void Frame::set_position(int x, int y){
	set_x(x);
	set_y(y);
	set_width(width);
	set_height(height);
	set_source_x(190);
	set_source_y(0);
}

