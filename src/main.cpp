// Include this file wherever the engine is used
#include "hurtEngine/hurtEngine.h"

// TODO: for test code (remove)
#include "object1.h"
#include "object2.h"

int main() {
	// Start coding here

	// TODO: test code below (remove)
	
	Scene * scene1 = new Scene(&string("scene1"));
	scene1->addEntity(new Object1(&string("obj1"), &Vec3(0, 1, 0)));

	Scene * scene2 = new Scene(&string("scene2"));
	scene2->addEntity(new Object2(&string("obj2"), &Vec3(1, 1, 0)));

	Game * game = Game::instance();
	game->addScene(scene1);
	game->addScene(scene2);
	game->initGame(1080, 608, &string("Dank memes!"), &Vec3(1, 1, 1));

	return 0;
}