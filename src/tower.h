#pragma once

#include "hurtEngine/hurtEngine.h"

#define TOWER_OFFSET new Vec3(0, .5f, 0)
constexpr float TOWER_RADIUS = 2.5f;

extern bool selectionMade;

class Tower : public Entity {
public:
	Tower(float rangeIn, Entity * rangeVisualIn, Transform * transformIn, Material * material, Mesh * mesh, float camFactorIn, float towerYIn);
	void onUpdate() override;
	void lockRangeVisual();
	float getRange();
	~Tower();
private:
	float range;
	Entity * rangeVisual;
	Transform * transform;
	Collideable * collide;
	MousePicker * mouse;
	float camFactor;
	float towerY;
};