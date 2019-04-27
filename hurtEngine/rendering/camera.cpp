#include "camera.h"

static Vec3 Y_AXIS(0, 1, 0);

Camera::Camera(Vec3 * posIn, Vec3 * forwardIn, Vec3 * upIn, float fov, int windowWidth, int windowHeight, float zNear, float zFar) : pos(posIn) {
	forward = forwardIn->normalized();
	up = upIn->normalized();

	delete forwardIn;
	delete upIn;

	float fovRad = hurtDegToRad(fov);
	float tanHalfFov = (float)tan(fovRad / 2);
	float zRange = zNear - zFar;
	float aspectRatio = (float)windowWidth / windowHeight;
	float * projectionVals = new float[16]{
		-1 / (tanHalfFov * aspectRatio),	0,				0,							0,
		0,									1 / tanHalfFov, 0,							0,
		0,									0,				-(zNear + zFar) / zRange,	2 * zFar * zNear / zRange,
		0,									0,				1,							0
	};
	projection = new Mat4(projectionVals);
}

void Camera::moveRight(float delta) {
	Vec3 * right = forward->cross(up);
	Vec3 * rightNorm = right->normalized();
	Vec3 * rightScaled = rightNorm->mul(-delta);
	Vec3 * newPos = pos->add(rightScaled);

	delete right;
	delete rightNorm;
	delete rightScaled;
	delete pos;

	pos = newPos;
}

void Camera::moveUp(float delta) {
	Vec3 * upScaled = up->mul(delta);
	Vec3 * newPos = pos->add(upScaled);

	delete upScaled;
	delete pos;

	pos = newPos;
}

void Camera::moveForward(float delta) {
	Vec3 * forwardScaled = forward->mul(delta);
	Vec3 * newPos = pos->add(forwardScaled);

	delete forwardScaled;
	delete pos;

	pos = newPos;
}

void Camera::moveY(float delta) {
	Vec3 * yScaled = Y_AXIS.mul(delta);
	Vec3 * newPos = pos->add(yScaled);

	delete yScaled;
	delete pos;

	pos = newPos;
}

void Camera::moveRightXZ(float delta) {
	Vec3 forwardXZ(forward->x, 0, forward->z);
	Vec3 * forwardXZNorm = forwardXZ.normalized();
	Vec3 * rightXZ = forwardXZNorm->cross(&Y_AXIS);
	Vec3 * rightXZNorm = rightXZ->normalized();
	Vec3 * rightXZScaled = rightXZNorm->mul(-delta);
	Vec3 * newPos = pos->add(rightXZScaled);

	delete forwardXZNorm;
	delete rightXZ;
	delete rightXZNorm;
	delete rightXZScaled;
	delete pos;
	
	pos = newPos;
}

void Camera::moveForwardXZ(float delta) {
	Vec3 forwardXZ(forward->x, 0, forward->z);
	Vec3 * forwardXZNorm = forwardXZ.normalized();
	Vec3 * forwardXZScaled = forwardXZNorm->mul(delta);
	Vec3 * newPos = pos->add(forwardXZScaled);

	delete forwardXZNorm;
	delete forwardXZScaled;
	delete pos;

	pos = newPos;
}

void Camera::turnHorizontal(float delta) {
	if (delta == 0) {
		return;
	}

	Vec3 * horizontal = Y_AXIS.cross(forward);
	Vec3 * horizontalNorm = horizontal->normalized();

	forward->rotate(&Y_AXIS, delta);
	Vec3 * forwardNorm = forward->normalized();

	Vec3 * newUp = forwardNorm->cross(horizontalNorm);
	Vec3 * newUpNorm = newUp->normalized();

	delete horizontal;
	delete horizontalNorm;
	delete newUp;
	delete forward;
	delete up;

	forward = forwardNorm;
	up = newUpNorm;
}

void Camera::turnVertical(float delta) {
	if (delta == 0) {
		return;
	}

	Vec3 * horizontal = Y_AXIS.cross(forward);
	Vec3 * horizontalNorm = horizontal->normalized();

	forward->rotate(horizontalNorm, -delta);
	Vec3 * forwardNorm = forward->normalized();

	Vec3 * newUp = forwardNorm->cross(horizontalNorm);
	Vec3 * newUpNorm = newUp->normalized();

	delete horizontal;
	delete horizontalNorm;
	delete newUp;
	delete forward;
	delete up;

	forward = forwardNorm;
	up = newUpNorm;
}

void Camera::updateLocked(Vec2 * windowSize) {
	if (locked) {
		Vec2 * turnDelta = hurtGetCursorPos();
		float timeDelta = Time::instance()->getDelta();
		float aspectRatio = windowSize->x / windowSize->y;
		turnHorizontal(turnDelta->x * turnSpeed * timeDelta * aspectRatio);
		turnVertical(turnDelta->y * turnSpeed * timeDelta);
		hurtSetCursorPos(&Vec2(0, 0));
	}
}

bool Camera::isLocked() {
	return locked;
}

void Camera::setLocked(bool locked) {
	if (locked) {
		hurtSetCursorVisible(false);
		hurtSetCursorPos(&Vec2(0, 0));
	}
	else {
		hurtSetCursorVisible(true);
	}

	this->locked = locked;
}

float Camera::getTurnSpeed() {
	return turnSpeed;
}

void Camera::setTurnSpeed(float speed) {
	turnSpeed = speed;
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
	Vec3 * right = forward->cross(up);
	float * rotationVals = new float[16]{
		right->x,	right->y,	right->z,	0,
		up->x,		up->y,		up->z,		0,
		forward->x, forward->y, forward->z, 0,
		0,			0,			0,			1
	};
	Mat4 * rotation = new Mat4(rotationVals);

	float * translationVals = new float[16]{
		1, 0, 0, -pos->x,
		0, 1, 0, -pos->y,
		0, 0, 1, -pos->z,
		0, 0, 0, 1
	};
	Mat4 * translation = new Mat4(translationVals);

	Mat4 * viewMatrix = rotation->mul(translation);

	delete right;
	delete rotation;
	delete translation;

	return viewMatrix;
}

Mat4 * Camera::projectionMatrix() {
	return projection;
}

Camera::~Camera() {
	delete pos;
	delete forward;
	delete up;
	delete projection;
}