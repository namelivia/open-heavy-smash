#ifndef SMALLFLAG_H_
#define SMALLFLAG_H_

#include "../Sprite.h"

class SmallFlag : public Sprite {
private:
	static const Uint16 width = 24;
	static const Uint16 height = 16;

public:

	SmallFlag() {
	}

	SmallFlag(int x,int y,int country){
		set_position(x,y);
		set_country(country);
	}

	void set_country(int country);
	void set_position(int x, int y);
};
#endif /* SMALLFLAG_H_ */
