#pragma once

#include "hurtEngine/hurtEngine.h"
#include "health.h"

constexpr int NUM_GAME_OVER_DIGITS = 4;

class GameOver : public Entity {
public:
	GameOver(Scene * scene, float camFactor);
	void onSceneLoad() override;
	~GameOver();
private:
	Entity * gameOverLabel;
	Entity * scoreLabel;
	Entity * digits[NUM_GAME_OVER_DIGITS];
};