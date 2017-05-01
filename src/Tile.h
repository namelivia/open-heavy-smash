/*
 * Tile.h
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#ifndef TILE_H_
#define TILE_H_

#include "Sprite.h"

class Tile : public Sprite {
private:
    char tipo;
public:
    Tile() {}
    void set_tipo(char nuevo_tipo);
    char get_tipo();
};
#endif /* TILE_H_ */
