#pragma once

#include "hurtEngine/math/vec3.h"

class Collideable {
public:
	Collideable(Vec3 * offsetIn, float radiusIn);
	bool collidesWith(Collideable * collideable);
	~Collideable();
private:
	Vec3 * color;
	Vec3 * offset;
	float radius;
};