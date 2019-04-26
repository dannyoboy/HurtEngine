#pragma once

#include "hurtEngine/math/vec2.h"
#include "hurtEngine/math/vec3.h"
#include "hurtEngine/math/mat4.h"
#include "hurtEngine/input/cursor.h"
#include "hurtEngine/utils/time.h"

constexpr float DEFAULT_TURN_SPEED = 360;

class Camera {
public:
	Camera(Vec3 * posIn, Vec3 * forwardIn, Vec3 * upIn, float fov, int windowWidth, int windowHeight, float zNear, float zFar);
	void moveRight(float delta);
	void moveUp(float delta);
	void moveForward(float delta);
	void moveY(float delta);
	void moveRightXZ(float delta);
	void moveForwardXZ(float delta);
	void turnHorizontal(float delta);
	void turnVertical(float delta);
	void updateLocked(Vec2 * windowSize);
	bool isLocked();
	void setLocked(bool locked);
	float getTurnSpeed();
	void setTurnSpeed(float speed);
	Vec3 * getPos();
	void setPos(Vec3 * posIn);
	Vec3 * getForward();
	void setForward(Vec3 * forwardIn);
	Vec3 * getUp();
	void setUp(Vec3 * upIn);
	Mat4 * viewMatrix();
	Mat4 * projectionMatrix();
	~Camera();
private:
	Vec3 * pos;
	Vec3 * forward;
	Vec3 * up;
	Mat4 * projection;
	bool locked = false;
	float turnSpeed = DEFAULT_TURN_SPEED;
};