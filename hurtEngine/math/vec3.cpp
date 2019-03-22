#include "vec3.h"

Vec3 * Vec3::add(Vec3 * vec) {
	Vec3 * sum = new Vec3(this->x + vec->x, this->y + vec->y, this->z + vec->z);
	return sum;
}

Vec3 * Vec3::sub(Vec3 * vec) {
	Vec3 * diff = new Vec3(this->x - vec->x, this->y - vec->y, this->z - vec->z);
	return diff;
}

Vec3 * Vec3::mul(float val) {
	Vec3 * product = new Vec3(this->x * val, this->y * val, this->z * val);
	return product;
}

Vec3 * Vec3::pieceMul(Vec3 * vec) {
	Vec3 * product = new Vec3(this->x * vec->x, this->y * vec->y, this->z * vec->z);
	return product;
}

float Vec3::dot(Vec3 * vec) {
	return this->x * vec->x + this->y * vec->y + this->z * vec->z;
}

Vec3 * Vec3::normalized() {

}

float Vec3::length() {

}

float Vec3::angleBetween(Vec3 * vec) {

}

Vec3 * Vec3::cross(Vec3 * vec) {

}