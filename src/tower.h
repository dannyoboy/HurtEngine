#pragma once

#include "hurtEngine/hurtEngine.h"

#define TURRET_OFFSET new Vec3(0, 0.5f, 0)
#define CANNON_OFFSET new Vec3(0, 1, 0)
#define RADIO_OFFSET new Vec3(0, 2.65f, 1)

constexpr float TURRET_RADIUS = 1.5f;
constexpr float CANNON_RADIUS = 1.8f;
constexpr float RADIO_RADIUS = 2;

extern bool selectionMade;

class Tower : public Entity {
public:
	Tower(float rangeIn, Entity * rangeVisualIn, Transform * transformIn, Material * material, Mesh * mesh, float camFactorIn, float towerYIn, float towerRadius, Vec3 * towerOffset);
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