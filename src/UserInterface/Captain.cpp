#include "Captain.h"

void Captain::set_country(int country){
	if (country<0 || country>9)
		return;
	set_source_x(80+(country/2)*width);
	set_source_y((country%2)*height);
}

void Captain::set_position(int x, int y){
	set_x(x);
	set_y(y);
	set_width(width);
	set_height(height);
}

