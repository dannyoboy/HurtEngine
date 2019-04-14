// Include this file wherever the engine is used
#include "hurtEngine/hurtEngine.h"

// TODO: for test code (remove)
#include "object1.h"
#include "object2.h"

int main() {
	// Start coding here

	// TODO: test code below (remove)
	
	string name1("scene1");
	string name2("scene2");
	Scene * scene1 = new Scene(&name1);
	Scene * scene2 = new Scene(&name2);
	
	string tag1("obj1");
	Vec3 color1(0, 1, 0);
	scene1->addEntity(new Object1(&tag1, &color1));

	string tag2("obj2");
	Vec3 color2(1, 1, 0);
	scene2->addEntity(new Object2(&tag2, &color2));

	Game * game = Game::instance();
	game->addScene(scene1);
	game->addScene(scene2);
	game->initGame(1080, 608, &string("Dank memes!"), &Vec3(0, 0, 0));

	return 0;
}