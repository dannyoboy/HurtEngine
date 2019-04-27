#pragma once

#include "hurtEngine/hurtEngine.h"

class Enemy : public Entity {
public:
	Enemy(Scene * scene, Vec3 * enemyStartPos);
	void death();
};

