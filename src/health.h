#pragma once

#include "hurtEngine/hurtEngine.h"

constexpr int INIT_HEALTH = 150;
constexpr int NUM_PLACES = 6;
constexpr int NUM_SCORE_PLACES = 4;

constexpr float MONEY_LABEL_OFFSET = 0.04f;
constexpr float MONEY_LABEL_SIZE = 0.15f;

constexpr float DIGIT_OFFSET = 0.02f;
constexpr float DIGIT_SIZE = 0.05f;

constexpr float SCORE_OFFSET = 0.015f;
constexpr float SCORE_SIZE = 0.035f;

constexpr int TICKS_PER_SECOND = (int)(1 / TIME_SYNC) + 1;

extern int healthMoney;
extern int score;

class Health:public Entity {
public:
	Health(Scene * scene, float hud_width, float hud_height, float camFactor, float hudY);
	void onLateUpdate() override;
	~Health();

private:
	Entity *money_label;
	Entity *digits[NUM_PLACES];
	Entity *scoreDisplay[NUM_PLACES];
	float currTick = 0;
};