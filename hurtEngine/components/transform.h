#pragma once

#include "hurtEngine/math/vec3.h"
#include "hurtEngine/math/mat4.h"
#include "hurtEngine/math/trig.h"

class Transform {
public:
	Transform(Vec3 * posIn, Vec3 * rotIn, Vec3 * scaleIn);
	Mat4 * transformationMatrix();
	Vec3 * getPos();
	void setPos(Vec3 * posIn);
	Vec3 * getRot();
	void setRot(Vec3 * rotIn);
	Vec3 * getScale();
	void setScale(Vec3 * scaleIn);
	~Transform();
private:
	Vec3 * pos;
	Vec3 * rot;
	Vec3 * scale;
};