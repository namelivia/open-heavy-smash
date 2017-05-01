#ifndef TILE_H_
#define TILE_H_

#include "Sprite.h"

class Tile : public Sprite {
private:
    char type;
public:
    Tile() {}
    void set_type(char new_type);
    char get_type();
};
#endif /* TILE_H_ */
