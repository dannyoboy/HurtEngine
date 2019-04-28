#pragma once

#include "hurtEngine/hurtEngine.h"
#include "Levels/Level1.h"

class Enemy : public Entity {
public:
	Enemy(Scene * scene, Vec3 * enemyStartPos, int healthAmt, int meshNum, Level1 * level);
	void death();
	void takeDamage(int damage);
private:
	int health;
	Scene * theScene;
	Level1 * level1;
};