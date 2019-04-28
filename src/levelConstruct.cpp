#include "levelConstruct.h"
#include "Enemy.h"
#include "PathNode.h"
#include "Levels/Level1.h"

Entity * background;
Enemy * test;



void constructLevel(Scene * scene, int cam_distance, int fov_angle) {
	// creates the background
	string tag("background");
	background = new Entity(&tag);
	Mesh * mesh = HURT_PLANE;
	int wh = int(2 * cam_distance * tan(hurtDegToRad((float)fov_angle / 2)) + 1); //height/width given FOV
	Transform * transform = new Transform(new Vec3(0, 0, 0), new Vec3(0, 0, 0), new Vec3((float)wh, 1, (float)wh)); //change to depend on FOV 
	Material * material = new Material(new Vec3(0.337f, 0.49f, 0.275f), 0.5f, 0.4f, 0, 32);
	DirectionalLight * directionalLight = new DirectionalLight(new Vec3(1, 1, 1), 1, new Vec3(0, -1, 0));
	background->attachTransform(transform);
	background->attachMesh(mesh);
	background->attachMaterial(material);
	background->attachDirectionalLight(directionalLight);
	scene->addEntity(background);

	//create for particular level
	Vec3 * enemyStartPos = new Vec3(-((float)wh / 2) + 1, 5, ((float)wh / 2)- 9);
	test = new Enemy(scene, enemyStartPos);
	
	Level1 * lvl = new Level1(scene, (float)wh);
}

void freeLevelComponents() {
	delete background->getTransform();
	delete background->getMaterial();
	delete background->getDirectionalLight();
	test->death();
}

void endLevel(Scene * scene) {
	scene->removeEntities(&string("Enemy"));
	scene->removeEntities(&string("PathNode"));
	scene->removeEntities(&string("EndNode"));
}