#pragma once

#include <math.h>
#include "trig.h"

class Vec2 {
public:
	float x, y;

	inline Vec2(float xIn, float yIn) : x(xIn), y(yIn) {}
	Vec2 * add(Vec2 * vec);
	Vec2 * sub(Vec2 * vec);
	Vec2 * mul(float val);
	Vec2 * pieceMul(Vec2 * vec);
	float dot(Vec2 * vec);
	Vec2 * normalized();
	float length();
	float angleBetween(Vec2 * vec);
};