#include "quaternion.h"

Quaternion::Quaternion(float xIn, float yIn, float zIn, float wIn) : x(xIn), y(yIn), z(zIn), w(wIn) {}

Quaternion * Quaternion::conjugated() {
	return new Quaternion(-x, -y, -z, w);
}

Quaternion * Quaternion::mul(Vec3 * vec) {
	float pX = w * vec->x + y * vec->z - z * vec->y;
	float pY = w * vec->y + z * vec->x - x * vec->z;
	float pZ = w * vec->z + x * vec->y - y * vec->x;
	float pW = -x * vec->x - y * vec->y - z * vec->z;

	return new Quaternion(pX, pY, pZ, pW);
}

Quaternion * Quaternion::mul(Quaternion * quat) {
	float pX = x * quat->w + y * quat->z - z * quat->y + w * quat->x;
	float pY = -x * quat->z + y * quat->w + z * quat->x + w * quat->y;
	float pZ = x * quat->y - y * quat->x + z * quat->w + w * quat->z;
	float pW = -x * quat->x - y * quat->y - z * quat->z + w * quat->w;

	return new Quaternion(pX, pY, pZ, pW);
}