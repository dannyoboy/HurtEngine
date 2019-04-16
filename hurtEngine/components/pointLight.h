#pragma once

#include <string>
#include "hurtEngine/math/vec3.h"
#include "hurtEngine/rendering/shader.h"

using namespace std;

class PointLight {
public:
	PointLight(Vec3 * colorIn, float intensityIn, Vec3 * attenuationIn, Vec3 * positionIn, float rangeIn);
	void load(Shader * shader, int index);
	Vec3 * getColor();
	void setColor(Vec3 * colorIn);
	float getIntensity();
	void setIntensity(float intensityIn);
	Vec3 * getAttenuation();
	void setAttenuation(Vec3 * attenuationIn);
	Vec3 * getPosition();
	void setPosition(Vec3 * positionIn);
	float getRange();
	void setRange(float rangeIn);
	~PointLight();
private:
	Vec3 * color;
	float intensity;
	Vec3 * attenuation;
	Vec3 * position;
	float range;
};