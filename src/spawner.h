#pragma once

#include "hurtEngine/hurtEngine.h"
#include "Enemy.h"
#include "Levels/Level1.h"

constexpr float SPAWN_TIME = 0.5f;

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
	float spawnTime = SPAWN_TIME;
};