#include "levelConstruct.h"

static string TOWER_INDICATOR_TAG("towerIndicator");
static string RANGE_TAG("rangeVisual");
static string TOWER_PLACER_TAG("towerPlacer");

void constructLevel(Scene * scene, float fov, float cam_distance) {
	// HUD
	float cam_factor = (float)(HUD_DISTANCE * tan(0.5 * hurtDegToRad(fov)));
	HUD * hud = new HUD(new Vec3(1, 1, 0), cam_factor, cam_distance - HUD_DISTANCE, &string("res/turretPic.png"), &string("res/radioPic.png"), &string("res/cannonPic.png"), scene);
	scene->addEntity(hud);

	// Turret indicator
	Entity * turretIndicator = new Entity(&TOWER_INDICATOR_TAG);
	turretIndicator->attachMesh(new Mesh(&string("res/turret.obj")));
	turretIndicator->attachMaterial(new Material(new Vec3(1, 0, 0), 0.2f, 0.4f, 0.4f, 16));
	turretIndicator->attachTransform(new Transform(new Vec3(0, 0, 0), new Vec3(0, 0, 0), new Vec3(TOWER_SIZE, TOWER_SIZE, TOWER_SIZE)));
	scene->addEntity(turretIndicator);

	// Cannon indicator
	Entity * cannonIndicator = new Entity(&TOWER_INDICATOR_TAG);
	cannonIndicator->attachMesh(new Mesh(&string("res/cannon.obj")));
	cannonIndicator->attachMaterial(new Material(new Vec3(0, 1, 0), 0.2f, 0.4f, 0.4f, 16));
	cannonIndicator->attachTransform(new Transform(new Vec3(0, 0, 0), new Vec3(0, 0, 0), new Vec3(TOWER_SIZE, TOWER_SIZE, TOWER_SIZE)));
	scene->addEntity(cannonIndicator);

	// Radio indicator
	Entity * radioIndicator = new Entity(&TOWER_INDICATOR_TAG);
	radioIndicator->attachMesh(new Mesh(&string("res/radio.obj")));
	radioIndicator->attachMaterial(new Material(new Vec3(0, 0, 1), 0.2f, 0.4f, 0.4f, 16));
	radioIndicator->attachTransform(new Transform(new Vec3(0, 0, 0), new Vec3(0, 0, 0), new Vec3(TOWER_SIZE, TOWER_SIZE, TOWER_SIZE)));
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
}