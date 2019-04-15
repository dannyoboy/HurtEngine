#include "camera.h"

Camera::Camera(Vec3 * posIn, Vec3 * forwardIn, Vec3 * upIn) {
	// TODO
}

void Camera::moveRight(float delta) {
	// TODO
}

void Camera::moveUp(float delta) {
	// TODO
}

void Camera::moveForward(float delta) {
	// TODO
}

void Camera::turnHorizontal(float delta) {
	// TODO
}

void Camera::turnVertical(float delta) {
	// TODO
}

Vec3 * Camera::getPos() {
	return pos;
}

void Camera::setPos(Vec3 * posIn) {
	delete pos;
	pos = posIn;
}

Vec3 * Camera::getForward() {
	return forward;
}

void Camera::setForward(Vec3 * forwardIn) {
	delete forward;
	forward = forwardIn;
}

Vec3 * Camera::getUp() {
	return up;
}

void Camera::setUp(Vec3 * upIn) {
	delete up;
	up = upIn;
}

Mat4 * Camera::viewMatrix() {
	// TODO
}

Camera::~Camera() {
	delete pos;
	delete forward;
	delete up;
}