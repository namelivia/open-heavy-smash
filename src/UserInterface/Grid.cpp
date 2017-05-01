#include "Grid.h"

void Grid::set_color(int color){
	if (color<0 || color>2)
		return;
	set_source_x(0+width*color);
	set_source_y(0);
}

void Grid::set_position(int x, int y){
	set_x(x);
	set_y(y);
	set_width(width);
	set_height(height);
}

