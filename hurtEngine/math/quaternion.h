#pragma once

#include "vec3.h"

class Quaternion {
public:
	float x, y, z, w;
	Quaternion(float xIn, float yIn, float zIn, float wIn);
	Quaternion * conjugated();
	Quaternion * mul(Vec3 * vec);
	Quaternion * mul(Quaternion * quat);
};