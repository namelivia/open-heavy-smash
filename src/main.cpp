#include "Game.h"
#include "Constants.h"

int main(int argc, char** argv) {
	Game game;
	if (game.init() > 0) {
		return 1;
	};
	game.loop();
	game.finish();
	return 0;
}
