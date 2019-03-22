#pragma once

#include "hurtEngine/hurtEngine.h"

class Vec4 {
public:
	float x, y, z, w;

	inline Vec4(float xIn, float yIn, float zIn, float wIn) : x(xIn), y(yIn), z(zIn), w(wIn) {}
	Vec4 * add(Vec4 * vec);
	Vec4 * sub(Vec4 * vec);
	Vec4 * mul(float val);
	Vec4 * pieceMul(Vec4 * vec);
	float dot(Vec4 * vec);
	Vec4 * normalized();
	float length();
	float angleBetween(Vec4 * vec);
};