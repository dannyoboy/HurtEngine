#pragma once

#include "hurtEngine/math/vec3.h"
#include "hurtEngine/utils/time.h"
#include "transform.h"

constexpr float TIME_SYNC = 1.0f / 300;

class Kinematics {
public:
	Kinematics(Transform * transformIn, Vec3 * velIn, Vec3 * angVelIn, Vec3 * accIn, Vec3 * angAccIn);
	void update();
	Vec3 * getVel();
	void setVel(Vec3 * velIn);
	Vec3 * getAngVel();
	void setAngVel(Vec3 * angVelIn);
	Vec3 * getAcc();
	void setAcc(Vec3 * accIn);
	Vec3 * getAngAcc();
	void setAngAcc(Vec3 * angAccIn);
	~Kinematics();
private:
	Transform * transform;
	Vec3 * vel;
	Vec3 * angVel;
	Vec3 * acc;
	Vec3 * angAcc;
};