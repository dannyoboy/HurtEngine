#include "quaternion.h"

Quaternion::Quaternion(float xIn, float yIn, float zIn, float wIn) : x(xIn), y(yIn), z(zIn), w(wIn) {}

Quaternion * Quaternion::conjugated() {
	return new Quaternion(-x, -y, -z, w);
}

Quaternion * Quaternion::mul(float vecX, float vecY, float vecZ) {
	float pX = w * vecX + y * vecZ - z * vecY;
	float pY = w * vecY + z * vecX - x * vecZ;
	float pZ = w * vecZ + x * vecY - y * vecX;
	float pW = -x * vecX - y * vecY - z * vecZ;

	return new Quaternion(pX, pY, pZ, pW);
}

Quaternion * Quaternion::mul(Quaternion * quat) {
	float pX = x * quat->w + y * quat->z - z * quat->y + w * quat->x;
	float pY = -x * quat->z + y * quat->w + z * quat->x + w * quat->y;
	float pZ = x * quat->y - y * quat->x + z * quat->w + w * quat->z;
	float pW = -x * quat->x - y * quat->y - z * quat->z + w * quat->w;

	return new Quaternion(pX, pY, pZ, pW);
}