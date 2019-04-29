#pragma once

#include "hurtEngine/hurtEngine.h"
#include "../tower.h"
#include "src/Enemy.h"
#include "src/projectiles/bullet.h"

constexpr float TURRET_COOLDOWN = 1;

class Turret : public Tower {
public:
	Turret(float rangeIn, Entity * rangeVisualIn, Transform * transformIn, Material * material, Mesh * mesh, float camFactorIn, float towerYIn);
	void onLateUpdate() override;
private:
	float cooldown = 0;
};