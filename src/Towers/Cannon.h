#pragma once

#include "hurtEngine/hurtEngine.h"
#include "../tower.h"

class Cannon : public Tower {
public:
	Cannon(float rangeIn, Entity * rangeVisualIn, Transform * transformIn, Material * material, Mesh * mesh, float camFactorIn, float towerYIn);
};