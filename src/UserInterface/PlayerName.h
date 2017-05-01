#ifndef PLAYERNAME_H_
#define PLAYERNAME_H_

#include "../Sprite.h"

class PlayerName : public Sprite {
private:
	static const Uint16 width = 123;
	static const Uint16 height = 16;

public:

	PlayerName() {
	}

	PlayerName(int x,int y,int name){
		set_position(x,y);
		set_name(name);
	}

	void set_name(int name);
	void set_position(int x, int y);
};
#endif /* PLAYERNAME_H_ */
