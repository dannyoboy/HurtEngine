#include "transform.h"

Transform::Transform(Vec3 * posIn, Vec3 * rotIn, Vec3 * scaleIn) : pos(posIn), rot(rotIn), scale(scaleIn) {}

Vec3 * Transform::getPos() {
	return pos;
}

Vec3 * Transform::getRot() {
	return rot;
}

Vec3 * Transform::getScale() {
	return scale;
}

Transform::~Transform() {
	delete pos;
	delete rot;
	delete scale;
}