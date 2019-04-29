#pragma once

#include "hurtEngine/hurtEngine.h"

constexpr int INIT_HEALTH = 100;
constexpr int NUM_PLACES = 6;

constexpr float MONEY_LABEL_OFFSET = 0.04f;
constexpr float MONEY_LABEL_SIZE = 0.15f;

constexpr float DIGIT_OFFSET = 0.02f;
constexpr float DIGIT_SIZE = 0.05f;

extern int healthMoney;

class Health:public Entity {
public:
	Health(Scene * scene, float hud_width, float hud_height, float camFactor, float hudY);
	void onLateUpdate() override;
	~Health();

private:
	Entity *money_label;
	Entity *digits[NUM_PLACES];
};