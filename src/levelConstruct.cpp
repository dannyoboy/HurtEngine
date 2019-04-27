#include "levelConstruct.h"
#include "Enemy.h"
#include "PathNode.h"

Entity * background;
Enemy * test;
PathNode * pn;


void constructLevel(Scene * scene, int cam_distance, int fov_angle) {
	// creates the background
	string tag("background");
	background = new Entity(&tag);
	Mesh * mesh = HURT_PLANE;
	int wh = 2 * cam_distance * tan(hurtDegToRad(fov_angle / 2)) + 1; //height/width given FOV
	Transform * transform = new Transform(new Vec3(0, 0, 0), new Vec3(0, 0, 0), new Vec3(wh, 1, wh)); //change to depend on FOV 
	Material * material = new Material(new Vec3(0.337f, 0.49f, 0.275f), 0.5f, 0.4f, 0, 32);
	DirectionalLight * directionalLight = new DirectionalLight(new Vec3(1, 1, 1), 1, new Vec3(0, -1, 0));
	background->attachTransform(transform);
	background->attachMesh(mesh);
	background->attachMaterial(material);
	background->attachDirectionalLight(directionalLight);
	scene->addEntity(background);

	//create for particular level
	Vec3 * enemyStartPos = new Vec3(-(wh / 2) + 1, 5, (wh / 2)- 9);
	test = new Enemy(scene, enemyStartPos);
	Vec3 * testPathPos = new Vec3(-(wh / 2) + 30, 5, (wh / 2) - 9);
	pn = new PathNode(scene, testPathPos, new Vec3(0, 0, 0));
	


	//string testtag("test");
	//test = new Entity(&testtag);
	//Mesh * testmesh = HURT_PLANE;
	//Transform * testtransform = new Transform(new Vec3(0, 1, 0), new Vec3(0, 0, 0), new Vec3(30, 0, 4)); //change to depend on FOV 
	//Material * testmaterial = new Material(new Vec3(0.21f, 0.105f, 0.3f), 0.01f, 0.4f, 0.7f, 8);
	//DirectionalLight * testdirectionalLight = new DirectionalLight(new Vec3(1, 1, 1), 1, new Vec3(0, -1, 0));
	//test->attachTransform(testtransform);
	//test->attachMesh(testmesh);
	//test->attachMaterial(testmaterial);
	//test->attachDirectionalLight(testdirectionalLight);
	//scene->addEntity(test);
}

void freeLevelComponents() {
	delete background->getTransform();
	delete background->getMaterial();
	delete background->getDirectionalLight();

	/*delete test->getTransform();
	delete test->getMaterial();
	delete test->getDirectionalLight();*/
	test->death();
	pn->death();
}