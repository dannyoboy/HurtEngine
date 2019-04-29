#pragma once

#include "hurtEngine/hurtEngine.h"
#include "../tower.h"

class Radio : public Tower {
public:
	Radio(float rangeIn, Entity * rangeVisualIn, Transform * transformIn, Material * material, Mesh * mesh, float camFactorIn, float towerYIn);
	void onLateUpdate() override;
private:
	list<Entity *> * enemiesInRange;
};