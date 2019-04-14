#include "vec4.h"

Vec4 * Vec4::add(Vec4 * vec) {
	return new Vec4(this->x + vec->x, this->y + vec->y, this->z + vec->z, this->w + vec->w);
}

Vec4 * Vec4::sub(Vec4 * vec) {
	return new Vec4(this->x - vec->x, this->y - vec->y, this->z - vec->z, this->w - vec->w);
}

Vec4 * Vec4::mul(float val) {
	return new Vec4(this->x * val, this->y * val, this->z * val, this->w * val);
}

Vec4 * Vec4::pieceMul(Vec4 * vec) {
	return new Vec4(this->x * vec->x, this->y * vec->y, this->z * vec->z, this->w * vec->w);
}

float Vec4::dot(Vec4 * vec) {
	return this->x * vec->x + this->y * vec->y + this->z * vec->z + this->w * vec->w;
}

Vec4 * Vec4::normalized() {
	float len = this->length();
	return new Vec4(x / len, y / len, z / len, w / len);
}

float Vec4::length() {
	return (float)sqrt(x * x + y * y + z * z + w * w);
}

float Vec4::angleBetween(Vec4 * vec) {
	float dotProduct = this->dot(vec);
	float v1Len = this->length();
	float v2Len = vec->length();

	float thetaRad = (float)acos(dotProduct / (v1Len * v2Len));
	float thetaDeg = hurtRadToDeg(thetaRad);

	return thetaDeg;
}