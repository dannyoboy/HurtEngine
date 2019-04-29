#pragma once

#include "hurtEngine/hurtEngine.h"
#include "Enemy.h"
#include "Levels/Level1.h"

constexpr float SPAWN_TIME = 0.5f;

constexpr double ENEMY_1_SPAWN_TIME = 5;
constexpr double ENEMY_1_INIT_SPAWN_RATE = 0.5;
constexpr double ENEMY_1_SPAWN_ACC = 0.00002;

constexpr double ENEMY_2_SPAWN_TIME = 30;
constexpr double ENEMY_2_INIT_SPAWN_RATE = 1;
constexpr double ENEMY_2_SPAWN_ACC = 0.00002;

constexpr double ENEMY_3_SPAWN_TIME = 60;
constexpr double ENEMY_3_INIT_SPAWN_RATE = 1.5;
constexpr double ENEMY_3_SPAWN_ACC = 0.00002;

class Spawner : public Entity {
public:
	Spawner(Scene * sceneIn, float enemyYIn, float windowIn, Level1 * level1In);
	void onUpdate() override;
	~Spawner();
private:
	Scene * scene;
	float enemyY;
	float window;
	Level1 * level1;
	double totalTime = 0;
	double spawnTime1 = 0;
	double spawnRate1 = ENEMY_1_INIT_SPAWN_RATE;
	double spawnTime2 = 0;
	double spawnRate2 = ENEMY_2_INIT_SPAWN_RATE;
	double spawnTime3 = 0;
	double spawnRate3 = ENEMY_3_INIT_SPAWN_RATE;
};