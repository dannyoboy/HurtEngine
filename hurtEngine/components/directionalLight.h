#pragma once

#include <string>
#include "hurtEngine/math/vec3.h"
#include "hurtEngine/rendering/shader.h"

using namespace std;

class DirectionalLight {
public:
	DirectionalLight(Vec3 * colorIn, float intensityIn, Vec3 * directionIn);
	void load(Shader * shader, int index);
	Vec3 * getColor();
	void setColor(Vec3 * colorIn);
	float getIntensity();
	void setIntensity(float intensityIn);
	Vec3 * getDirection();
	void setDirection(Vec3 * directionIn);
	~DirectionalLight();
private:
	Vec3 * color;
	float intensity;
	Vec3 * direction;
};