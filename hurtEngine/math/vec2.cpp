#include "vec2.h"

Vec2 * Vec2::add(Vec2 * vec) {
	return new Vec2(this->x + vec->x, this->y + vec->y);
}

Vec2 * Vec2::sub(Vec2 * vec) {
	return new Vec2(this->x - vec->x, this->y - vec->y);
}

Vec2 * Vec2::mul(float val) {
	return new Vec2(this->x * val, this->y * val);
}

Vec2 * Vec2::pieceMul(Vec2 * vec) {
	return new Vec2(this->x * vec->x, this->y * vec->y);
}

float Vec2::dot(Vec2 * vec) {
	return this->x * vec->x + this->y * vec->y;
}

Vec2 * Vec2::normalized() {
	float len = this->length();
	return new Vec2(x / len, y / len);
}

float Vec2::length() {
	return (float)sqrt(x * x + y * y);
}

float Vec2::angleBetween(Vec2 * vec) {
	float dotProduct = this->dot(vec);
	float v1Len = this->length();
	float v2Len = vec->length();

	float thetaRad = acos(dotProduct / (v1Len * v2Len));
	float thetaDeg = radToDeg(thetaRad);

	return thetaDeg;
}