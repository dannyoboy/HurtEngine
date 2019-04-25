// Include this file wherever the engine is used
#include "hurtEngine/hurtEngine.h"

// TODO: for test code (remove)
#include "object1.h"
#include "object2.h"
#include "dragon.h"

constexpr int WIDTH = 1080;
constexpr int HEIGHT = 608;

int main() {
	// Start coding here

	Game * game = Game::instance();
	game->init(WIDTH, HEIGHT, &string("Dank memes!"), &Vec3(0, 0, 0));
	game->setDebugToolsEnabled(true);

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
	
	PointLight * pointLight = new PointLight(new Vec3(1, 1, 1), 1, new Vec3(0.01f, 0.01f, 0.01f), new Vec3(-3, 0, 5), 100);
	light->attachPointLight(pointLight);
	scene1->addEntity(light);

	string tag4("guy");
	//Material * guyMaterial = new Material(&string("res/guy.png"), &string("res/guyLight.png"), 4);
	Material * guyMaterial = new Material(new Vec3(1, 0, 0), 0.3f, 0.3f, 0.3f, 64);
	Mesh * guyMesh = new Mesh(&string("hurtEngine/assets/sphere.obj"));
	Transform * guyTransform = new Transform(new Vec3(0, 0, 5), new Vec3(0, 0, 0), new Vec3(2, 2, 2));
	Kinematics * guyKinematics = new Kinematics(guyTransform, new Vec3(0, 0, 0), new Vec3(0, 0, 0), new Vec3(0, 0, 0), new Vec3(0, 0, 0));
	Collideable * guyCollideable = new Collideable(guyTransform, new Vec3(-2, 2, 0), 2);
	Entity * guy = new Entity(&tag4);
	guy->attachMaterial(guyMaterial);
	//guy->attachMesh(guyMesh);
	guy->attachMesh(HURT_CUBE);
	guy->attachTransform(guyTransform);
	guy->attachKinematics(guyKinematics);
	guy->attachCollideable(guyCollideable);
	scene1->addEntity(guy);

	string tag5("dragon");
	Material * dragonMaterial = new Material(new Vec3(0, 0, 1), 0.4f, 0.3f, 0.3f, 64);
	Mesh * dragonMesh = new Mesh(&string("res/dragon.obj"));
	Transform * dragonTransform = new Transform(new Vec3(5, 0, 5), new Vec3(0, 0, 0), new Vec3(0.1f, 0.1f, 0.1f));
	Collideable * dragonCollideable = new Collideable(dragonTransform, new Vec3(0, 0.8f, 0), 1);
	string textures[] = {
		string("res/skyboxTex/R.png"), string("res/skyboxTex/L.png"), string("res/skyboxTex/U.png"), string("res/skyboxTex/D.png"), string("res/skyboxTex/F.png"), string("res/skyboxTex/B.png")
	};
	Skybox * dragonSkybox = new Skybox(textures, new Vec3(0, 0, 0));
	Dragon * dragon = new Dragon(&tag5);
	dragon->attachMaterial(dragonMaterial);
	dragon->attachMesh(dragonMesh);
	dragon->attachTransform(dragonTransform);
	dragon->attachCollideable(dragonCollideable);
	dragon->attachSkybox(dragonSkybox);
	scene1->addEntity(dragon);

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
	delete guyCollideable;
	delete dragonMaterial;
	delete dragonMesh;
	delete dragonTransform;
	delete dragonCollideable;
	delete dragonSkybox;

	return 0;
}