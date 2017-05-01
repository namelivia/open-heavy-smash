#ifndef SPRITETEXT_H_
#define SPRITETEXT_H_

#include "../Constants.h"
#include "../Sprite.h"
#include <string>

class SpriteText {
private:
public:
    Sprite characters[MAX_NAME];

    SpriteText(char text[MAX_NAME]){}
    void draw (SDL_Surface* screen,Camera *camera);
};

#endif /* SPRITETEXT_H_ */
