#include "hud.h"

static string TAG("hud");

HUD::HUD(Vec3 *color, float cam_factor, float selector_y, string *turret_file, string *radio_file, string *cannon_file, Scene * scene) : Entity(&TAG) {
	attachMesh(HURT_PLANE);
	material = new Material(color, 1, 0, 0, 1);
	attachMaterial(material);
	float hud_width = SELECTOR_SIZE * NUM_SELECTORS + (NUM_SELECTORS + 1) * MARGIN_SIZE;
	float hud_height = SELECTOR_SIZE + 2 * MARGIN_SIZE;
	Vec2 center(-1 + hud_width / 2, -1 + hud_height / 2);
	transform = new Transform(new Vec3(center.x * cam_factor, selector_y - .001f, center.y * cam_factor), new Vec3(0, 0, 0), new Vec3(hud_width * cam_factor, 1, hud_height * cam_factor));
	attachTransform(transform);
	float xPositions[NUM_SELECTORS];
	float low_x = center.x - hud_width / 2 + MARGIN_SIZE + .5f * SELECTOR_SIZE;
	for (int i = 0; i < NUM_SELECTORS; i++) {
		xPositions[i] = low_x + i * (SELECTOR_SIZE + MARGIN_SIZE);
	}
	turret = new Selector(new Vec2(xPositions[0], center.y), turret_file, cam_factor, selector_y);
	radio = new Selector(new Vec2(xPositions[1], center.y), radio_file, cam_factor, selector_y);
	cannon = new Selector(new Vec2(xPositions[2], center.y), cannon_file, cam_factor, selector_y);

	scene->addEntity(turret);
	scene->addEntity(radio);
	scene->addEntity(cannon);
}

bool HUD::getTurretSelected() {
	return turret->isSelected();
}

bool HUD::getRadioSelected() {
	return radio->isSelected();
}

bool HUD::getCannonSelected() {
	return cannon->isSelected();
}

HUD::~HUD() {
	delete material;
	delete transform;
}