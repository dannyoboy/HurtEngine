#pragma once

#include "hurtEngine/math/vec3.h"
#include "hurtEngine/math/mat4.h"
#include "hurtEngine/math/trig.h"

class Transform {
public:
	Transform(Vec3 * posIn, Vec3 * rotIn, Vec3 * scaleIn);
	Mat4 * transformationMatrix();
	Vec3 * getPos();
	Vec3 * getRot();
	Vec3 * getScale();
	~Transform();
private:
	Vec3 * pos;
	Vec3 * rot;
	Vec3 * scale;
};