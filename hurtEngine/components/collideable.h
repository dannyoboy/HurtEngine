#pragma once

#include "hurtEngine/math/vec3.h"
#include "hurtEngine/rendering/shader.h"
#include "transform.h"

#define HURT_BSPHERE_DEFAULT new Vec3(1, 0, 0)
#define HURT_BSPHERE_COLLIDE new Vec3(0, 0, 1)

class Collideable {
public:
	Collideable(Transform * transformIn, Vec3 * offsetIn, float radiusIn);
	Vec3 * collisionWith(Collideable * collideable);
	void load(Shader * bsphereShader);
	void setColor(Vec3 * colorIn);
	~Collideable();
private:
	Transform * transform;
	Vec3 * color;
	Vec3 * offset;
	float radius;
};