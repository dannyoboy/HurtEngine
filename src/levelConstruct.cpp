#include "levelConstruct.h"

static string TOWER_INDICATOR_TAG("towerIndicator");
static string RANGE_TAG("rangeVisual");
static string TOWER_PLACER_TAG("towerPlacer");

Entity * background;

void constructLevel(Scene * scene, float fov, float cam_distance) {
	// HUD
	float cam_factor = (float)(HUD_DISTANCE * tan(0.5 * hurtDegToRad(fov)));
	HUD * hud = new HUD(new Vec3(0.3f, 0.3f, 0.3f), cam_factor, cam_distance - HUD_DISTANCE, &string("res/turretPic.png"), &string("res/radioPic.png"), &string("res/cannonPic.png"), scene);
	scene->addEntity(hud);

	// Turret indicator
	Entity * turretIndicator = new Entity(&TOWER_INDICATOR_TAG);
	turretIndicator->attachMesh(new Mesh(&string("res/turret.obj")));
	turretIndicator->attachMaterial(new Material(&string("res/turret.png"), 0.3f, 0.5f, 0, 1));
	turretIndicator->attachTransform(new Transform(new Vec3(0, 0, 0), new Vec3(0, 0, 0), new Vec3(TURRET_SIZE, TURRET_SIZE, TURRET_SIZE)));
	scene->addEntity(turretIndicator);

	// Cannon indicator
	Entity * cannonIndicator = new Entity(&TOWER_INDICATOR_TAG);
	cannonIndicator->attachMesh(new Mesh(&string("res/cannon.obj")));
	cannonIndicator->attachMaterial(new Material(&string("res/cannon.png"), 0.4f, 0.6f, 0.1f, 16));
	cannonIndicator->attachTransform(new Transform(new Vec3(0, 0, 0), new Vec3(0, 0, 0), new Vec3(CANNON_SIZE, CANNON_SIZE, CANNON_SIZE)));
	scene->addEntity(cannonIndicator);

	// Radio indicator
	Entity * radioIndicator = new Entity(&TOWER_INDICATOR_TAG);
	radioIndicator->attachMesh(new Mesh(&string("res/radio.obj")));
	radioIndicator->attachMaterial(new Material(&string("res/radio.png"), 0.4f, 0.7f, 0.9f, 8));
	radioIndicator->attachTransform(new Transform(new Vec3(0, 0, 0), new Vec3(0, 0, 0), new Vec3(RADIO_SIZE, RADIO_SIZE, RADIO_SIZE)));
	scene->addEntity(radioIndicator);

	// Range Visual
	Entity * rangeVisual = new Entity(&RANGE_TAG);
	rangeVisual->attachMesh(HURT_PLANE);
	rangeVisual->attachMaterial(new Material(&string("res/rangeIndicator.png"), 1, 0, 0, 1));
	rangeVisual->attachTransform(new Transform(new Vec3(0, 0, 0), new Vec3(0, 180, 180), new Vec3(1, 1, 1)));
	scene->addEntity(rangeVisual);

	// Tower Placer
	float towersCamFactor = (float)((cam_distance - TOWER_Y) * tan(0.5 * hurtDegToRad(fov)));
	TowerPlacer * towerPlacer = new TowerPlacer(hud, turretIndicator, cannonIndicator, radioIndicator, rangeVisual, towersCamFactor, TOWER_Y, scene);
	scene->addEntity(towerPlacer);

	// Light
	Entity * light = new Entity(&string("light"));
	DirectionalLight * directionalLight = new DirectionalLight(new Vec3(1, 1, 1), 1, new Vec3(0, -1, 0));
	light->attachDirectionalLight(directionalLight);
	scene->addEntity(light);

	// Creates the background
	string tag("background");
	background = new Entity(&tag);
	Mesh * mesh = HURT_PLANE;
	int wh = int(2 * cam_distance * tan(hurtDegToRad((float)fov / 2)) + 1); //height/width given FOV
	Transform * transform = new Transform(new Vec3(0, 0, 0), new Vec3(0, 180, 180), new Vec3((float)wh, -1, (float)wh)); //change to depend on FOV
	Material * material = new Material(&string("res/backdrop.png"), 1, 0, 0, 1);
	background->attachTransform(transform);
	background->attachMesh(mesh);
	background->attachMaterial(material);
	scene->addEntity(background);

	// Create health display
	Health * health = new Health(scene, hud->getHUDWidth(), hud->getHUDHeight(), cam_factor, cam_distance - HUD_DISTANCE);
	scene->addEntity(health);

	//create particular level
	Level1 * lvl = new Level1(scene, (float)wh);
}

void freeLevelComponents() {
	delete background->getTransform();
	delete background->getMaterial();
	delete background->getDirectionalLight();
}

void endLevel(Scene * scene) {
	scene->removeEntities(&string("Enemy"));
	scene->removeEntities(&string("PathNode"));
	scene->removeEntities(&string("EndNode"));
}