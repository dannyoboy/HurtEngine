// Include this file wherever the engine is used
#include "hurtEngine/hurtEngine.h"

// TODO: for test code (remove)
#include "object1.h"
#include "object2.h"

constexpr int WIDTH = 1080;
constexpr int HEIGHT = 608;

int main() {
	// Start coding here

	Game * game = Game::instance();
	game->init(WIDTH, HEIGHT, &string("Dank memes!"), &Vec3(0, 0, 0));

	// TODO: test code below (remove)
	
	Camera * scene1Cam = new Camera(new Vec3(0, 0, 0), new Vec3(0, 0, 1), new Vec3(0, 1, 0), 60, WIDTH, HEIGHT, 0.001f, 1000);
	Camera * scene2Cam = new Camera(new Vec3(0, 0, 0), new Vec3(0, 0, 1), new Vec3(0, 1, 0), 60, WIDTH, HEIGHT, 0.001f, 1000);

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

	string tag3("light");
	DirectionalLight * directionalLight = new DirectionalLight(new Vec3(1, 1, 1), 1, new Vec3(-1, -1, 1));
	Entity * light = new Entity(&tag3);
	//light->attachDirectionalLight(directionalLight);
	
	PointLight * pointLight = new PointLight(new Vec3(1, 1, 1), 1, new Vec3(0.05f, 0.05f, 0.05f), new Vec3(-3, 0, 5), 100);
	light->attachPointLight(pointLight);
	scene1->addEntity(light);

	string tag4("guy");
	Material * guyMaterial = new Material(&string("res/guy.png"), &string("res/guyLight.png"), 4);
	Mesh * guyMesh = new Mesh(&string("res/guy.obj"));
	Transform * guyTransform = new Transform(new Vec3(0, 0, 5), new Vec3(0, 0, 0), new Vec3(1, 1, 1));
	Kinematics * guyKinematics = new Kinematics(new Vec3(0, 0, 0), new Vec3(0, 0, 0), new Vec3(0, 0, 0), new Vec3(0, 0, 0));
	Entity * guy = new Entity(&tag4);
	guy->attachMaterial(guyMaterial);
	guy->attachMesh(guyMesh);
	guy->attachTransform(guyTransform);
	guy->attachKinematics(guyKinematics);
	scene1->addEntity(guy);

	game->addScene(scene1);
	game->addScene(scene2);
	game->start();

	// Delete entity components here

	delete directionalLight;
	delete pointLight;
	delete guyMaterial;
	delete guyMesh;
	delete guyTransform;
	delete guyKinematics;

	return 0;
}