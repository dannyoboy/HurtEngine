#pragma once

#include "hurtEngine/hurtEngine.h"
#include "selector.h"

constexpr float MARGIN_SIZE = .02f;
constexpr int NUM_SELECTORS = 3;

class HUD : public Entity {
public:
	HUD(Vec3 *color, float cam_factor, float selector_y, string *turret_file, string *radio_file, string *cannon_file, Scene * scene);
	bool getTurretSelected();
	bool getRadioSelected();
	bool getCannonSelected();
	~HUD();

private:
	Selector *turret;
	Selector *radio;
	Selector *cannon;
	Material *material;
	Transform *transform;
};