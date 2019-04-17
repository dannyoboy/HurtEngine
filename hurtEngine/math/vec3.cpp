#include "vec3.h"

Vec3 * Vec3::add(Vec3 * vec) {
	return new Vec3(this->x + vec->x, this->y + vec->y, this->z + vec->z);
}

Vec3 * Vec3::sub(Vec3 * vec) {
	return new Vec3(this->x - vec->x, this->y - vec->y, this->z - vec->z);
}

Vec3 * Vec3::mul(float val) {
	return new Vec3(this->x * val, this->y * val, this->z * val);
}

Vec3 * Vec3::pieceMul(Vec3 * vec) {
	return new Vec3(this->x * vec->x, this->y * vec->y, this->z * vec->z);
}

float Vec3::dot(Vec3 * vec) {
	return this->x * vec->x + this->y * vec->y + this->z * vec->z;
}

Vec3 * Vec3::normalized() {
	float len = this->length();
	return new Vec3(x / len, y / len, z / len);
}

float Vec3::length() {
	return (float)sqrt(x * x + y * y + z * z);
}

float Vec3::angleBetween(Vec3 * vec) {
	float dotProduct = this->dot(vec);
	float v1Len = this->length();
	float v2Len = vec->length();

	float thetaRad = (float)acos(dotProduct / (v1Len * v2Len));
	float thetaDeg = hurtRadToDeg(thetaRad);

	return thetaDeg;
}

Vec3 * Vec3::cross(Vec3 * vec) {
	float cX = this->y * vec->z - this->z * vec->y;
	float cY = -(this->x * vec->z - this->z * vec->x);
	float cZ = this->x * vec->y - this->y * vec->x;

	return new Vec3(cX, cY, cZ);
}

void Vec3::rotate(Vec3 * axis, float theta) {
	float halfThetaRad = hurtDegToRad(theta) / 2;
	float sinHalfTheta = (float)sin(halfThetaRad);
	float cosHalfTheta = (float)cos(halfThetaRad);

	float rX = axis->x * sinHalfTheta;
	float rY = axis->y * sinHalfTheta;
	float rZ = axis->z * sinHalfTheta;
	float rW = cosHalfTheta;

	Quaternion * rotation = new Quaternion(rX, rY, rZ, rW);
	Quaternion * conjugate = rotation->conjugated();
	Quaternion * temp = rotation->mul(x, y, z);
	Quaternion * result = temp->mul(conjugate);

	x = result->x;
	y = result->y;
	z = result->z;

	delete rotation;
	delete conjugate;
	delete temp;
	delete result;
}