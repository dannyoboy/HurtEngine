// Include this file wherever the engine is used
#include "hurtEngine/hurtEngine.h"

int main() {
	// Start coding here

	// TODO: test code below (remove)

	Game * game = Game::instance();
	game->initGame(1600, 900, &string("Dank memes!"), &Vec3(1, 1, 0));

	return 0;
}