#include "levelConstruct.h"

Entity * background;
//Entity * test;

void constructLevel(Scene * scene, int cam_distance, int fov_angle) {
	// creates the background
	string tag("background");
	background = new Entity(&tag);
	Mesh * mesh = HURT_PLANE;
	int wh = 2 * cam_distance * tan(hurtDegToRad(fov_angle / 2)) + 1;
	Transform * transform = new Transform(new Vec3(0, 0, 0), new Vec3(0, 0, 0), new Vec3(wh, 0, wh)); //change to depend on FOV 
	Material * material = new Material(new Vec3(0.86f, 0.125f, 0.7f), 0.01f, 0.4f, 0.7f, 8);
	DirectionalLight * directionalLight = new DirectionalLight(new Vec3(1, 1, 1), 0.1f, new Vec3(0, -1, 0));
	background->attachTransform(transform);
	background->attachMesh(mesh);
	background->attachMaterial(material);
	background->attachDirectionalLight(directionalLight);
	scene->addEntity(background);

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
}