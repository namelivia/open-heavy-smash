#ifndef FLAG_H_
#define FLAG_H_

#include "../Sprite.h"

class Flag : public Sprite {
private:
	static const Uint16 width = 32;
	static const Uint16 height = 24;

public:

	Flag() {
	}

	Flag(int x,int y,int country){
		set_position(x,y);
		set_country(country);
	}

	void set_country(int country);
	void set_position(int x, int y);
};
#endif /* FLAG_H_ */
