/*
 * SpriteText.h
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#ifndef SPRITETEXT_H_
#define SPRITETEXT_H_

#include "../Constantes.h"
#include "../Sprite.h"
#include <string>

class SpriteText {
private:
public:
    Sprite characters[MAX_NOMBRE];

    SpriteText(char text[MAX_NOMBRE]){}
    void draw (SDL_Surface* screen,Camara *camara);
};

#endif /* SPRITETEXT_H_ */
