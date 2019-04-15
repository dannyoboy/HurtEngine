#pragma once

#include <math.h>
#include "trig.h"
#include "quaternion.h"

class Vec3 {
public:
	float x, y, z;

	inline Vec3(float xIn, float yIn, float zIn) : x(xIn), y(yIn), z(zIn) {}
	Vec3 * add(Vec3 * vec);
	Vec3 * sub(Vec3 * vec);
	Vec3 * mul(float val);
	Vec3 * pieceMul(Vec3 * vec);
	float dot(Vec3 * vec);
	Vec3 * normalized();
	float length();
	float angleBetween(Vec3 * vec);
	Vec3 * cross(Vec3 * vec);
	void rotate(Vec3 * axis, float theta);
};