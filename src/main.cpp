#include "Game.h"
#include "Constants.h"

int main(int argc, char** argv) {
	Game game;
	game.init();
	game.loop();
	game.finish();
	return 0;
}
