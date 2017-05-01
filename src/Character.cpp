#include "Character.h"

void Character::move_character(int what_direction){
	switch(what_direction){
		case 1:
			sprite.set_x(sprite.get_x()+speed);
			direction = 0;
			if (step >= 1) step = 0;
			else step++;
					break;
		case 2:
			sprite.set_x(sprite.get_x()-speed);
			direction = 1;
			if (step >= 1) step = 0;
			else step++;
					break;
		case 3:
			sprite.set_y(sprite.get_y()+speed);
			direction = 2;
			if (step >= 2) step = 0;
			else step++;
					break;
		case 4:
			sprite.set_y(sprite.get_y()-speed);
			direction = 3;
			if (step >= 2) step = 0;
			else step++;
					break;
	}
	switch (direction){
	case 0:
		sprite.set_source_x(8+step);
		break;
	case 1:
		sprite.set_source_x(0+step);
		break;
	case 2:
			sprite.set_source_x(2+step);
		break;
	case 3:
			sprite.set_source_x(5+step);
		break;
	}
}

void Character::stop_moving(){
	switch (direction){
	case 0:
		sprite.set_source_x(8);
		break;
	case 1:
		sprite.set_source_x(0);
		break;
	case 2:
			sprite.set_source_x(2);
		break;
	case 3:
			sprite.set_source_x(5);
		break;
	}
}

void Character::draw(SDL_Surface *screen,Camera *camera){
	sprite.draw(screen,camera);
}

int Character::get_speed(){
	return speed;
}
