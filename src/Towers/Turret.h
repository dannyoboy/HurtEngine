#pragma once

#include "hurtEngine/hurtEngine.h"
#include "../tower.h"

class Turret : public Tower {
public:
	Turret(float rangeIn, Entity * rangeVisualIn, Transform * transformIn, Material * material, Mesh * mesh, float camFactorIn, float towerYIn);
};