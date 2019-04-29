#pragma once

#include "hurtEngine/hurtEngine.h"
#include "Levels/Level1.h"
#include "Towers/Radio.h"

class Enemy : public Entity {
public:
	Enemy(Scene * scene, Vec3 * enemyStartPos, int healthAmt, Mesh * mesh, Material * material);
	void death();
	void takeDamage(int damage);
	void onUpdate() override;
	float getDistanceTraveled();
	~Enemy();
private:
	int health;
	Scene * theScene;
	float distanceTraveled = 0;
};