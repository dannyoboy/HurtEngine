#include "vec2.h"

Vec2 * Vec2::add(Vec2 * vec) {
	Vec2 * sum = new Vec2(this->x + vec->x, this->y + vec->y);
	return sum;
}

Vec2 * Vec2::sub(Vec2 * vec) {
	Vec2 * diff = new Vec2(this->x - vec->x, this->y - vec->y);
	return diff;
}

Vec2 * Vec2::mul(float val) {
	Vec2 * product = new Vec2(this->x * val, this->y * val);
	return product;
}

Vec2 * Vec2::pieceMul(Vec2 * vec) {
	Vec2 * product = new Vec2(this->x * vec->x, this->y * vec->y);
	return product;
}

float Vec2::dot(Vec2 * vec) {
	return this->x * vec->x + this->y * vec->y;
}

Vec2 * Vec2::normalized() {
	float len = this->length();
	Vec2 * norm = new Vec2(x / len, y / len);
	return norm;
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