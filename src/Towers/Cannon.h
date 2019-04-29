#pragma once

#include "hurtEngine/hurtEngine.h"
#include "../tower.h"
#include "src/Enemy.h"
#include "src/projectiles/cannonball.h"

constexpr float CANNON_COOLDOWN = 1.75f;

class Cannon : public Tower {
public:
	Cannon(float rangeIn, Entity * rangeVisualIn, Transform * transformIn, Material * material, Mesh * mesh, float camFactorIn, float towerYIn);
	void onLateUpdate() override;
private:
	float cooldown = 0;
};