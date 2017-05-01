#include "SpaceShuttle.h"

	void SpaceShuttle::load_image(char *path, ResourceManager *resourceManager){
		shuttle.load_image(path,resourceManager);
		fire.load_image(path,resourceManager);
	}
	void SpaceShuttle::draw(SDL_Renderer *sdlRenderer){

		set_position(x,y);
		shuttle.draw(sdlRenderer);

		if (isFlying){
			fire.draw(sdlRenderer);
		}
	}

	void SpaceShuttle::hflip(){
		/*shuttle.hflip();
		fire.hflip();*/
		flipped = true;
		fireFrame = !fireFrame;
	}

	bool SpaceShuttle::update(int destinationX, int destinationY){
		isFlying = false;
		if (x != destinationX-7){
			if (x < destinationX -7){
				x++;
				isFlying = true;
			}
			else{
				x--;;
				isFlying = true;
			}
		}

		if (y != destinationY-4){
			if (y < destinationY -4){
				y++;
				isFlying = true;
			}
			else{
				y--;
				isFlying = true;

			}
		}
		if (isFlying) AnimateFire();
		return (!isFlying);
	}

	void SpaceShuttle::set_position(int x,int y){
		if (flipped){
			shuttle.set_x(x+4);
			fire.set_x(x-12);
		}
		else{
			shuttle.set_x(x-4);
			fire.set_x(x+12);
		}
		fire.set_y(y+3);
		shuttle.set_y(y+1);
	}

	int SpaceShuttle::get_x(){
		return x;
	}

	int SpaceShuttle::get_y(){
		return y;
	}

	void SpaceShuttle::AnimateFire(){
		if (fireFrame){
				fire.set_source_x(fire.get_source_x()-fire.get_width());
				fireFrame = !fireFrame;
		}
		else{
				fire.set_source_x(fire.get_source_x()+fire.get_width());
				fireFrame = !fireFrame;
		}
	}
