#pragma once

#include "hurtEngine/hurtEngine.h"
#include "Levels/Level1.h"
#include "Towers/Radio.h"
#include "health.h"

class Enemy : public Entity {
public:
	Enemy(Scene * scene, Vec3 * enemyStartPos, int healthAmt, Mesh * mesh, Material * material, int rewardIn, int damageIn, float scaleFactor);
	void death();
	void takeDamage(int damage);
	void onUpdate() override;
	float getDistanceTraveled();
	int getDamage();
	~Enemy();
private:
	int health;
	Scene * theScene;
	int reward;
	int damage;
	float distanceTraveled = 0;
};