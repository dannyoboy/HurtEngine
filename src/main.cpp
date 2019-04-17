// Include this file wherever the engine is used
#include "hurtEngine/hurtEngine.h"

// TODO: for test code (remove)
#include "object1.h"
#include "object2.h"

constexpr int WIDTH = 1080;
constexpr int HEIGHT = 608;

int main() {
	// Start coding here

	// TODO: test code below (remove)
	
	Camera * scene1Cam = new Camera(new Vec3(0, 0, 0), new Vec3(0, 0, 1), new Vec3(0, 1, 0), 60, WIDTH, HEIGHT, 0.001, 1000);
	Camera * scene2Cam = new Camera(new Vec3(0, 0, 0), new Vec3(0, 0, 1), new Vec3(0, 1, 0), 60, WIDTH, HEIGHT, 0.001, 1000;

	string name1("scene1");
	string name2("scene2");
	Scene * scene1 = new Scene(&name1, scene1Cam);
	Scene * scene2 = new Scene(&name2, scene2Cam);
	
	string tag1("obj1");
	Vec3 color1(0, 1, 0);
	scene1->addEntity(new Object1(&tag1, &color1));

	string tag2("obj2");
	Vec3 color2(1, 1, 0);
	scene2->addEntity(new Object2(&tag2, &color2));

	Game * game = Game::instance();
	game->addScene(scene1);
	game->addScene(scene2);
	game->initGame(WIDTH, HEIGHT, &string("Dank memes!"), &Vec3(0, 0, 0));

	return 0;
}