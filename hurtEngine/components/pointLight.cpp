#include "pointLight.h"

PointLight::PointLight(Vec3 * colorIn, float intensityIn, Vec3 * attenuationIn, Vec3 * positionIn, float rangeIn) : color(colorIn), intensity(intensityIn), attenuation(attenuationIn), position(positionIn), range(rangeIn) {}

void PointLight::load(Shader * shader, int index) {
	shader->loadVec3(&(string("pointLights[") + to_string(index) + string("].basic.color")), color);
	shader->loadFloat(&(string("pointLights[") + to_string(index) + string("].basic.intensity")), intensity);
	shader->loadFloat(&(string("pointLights[") + to_string(index) + string("].attenuation.exponent")), attenuation->x);
	shader->loadFloat(&(string("pointLights[") + to_string(index) + string("].attenuation.linear")), attenuation->y);
	shader->loadFloat(&(string("pointLights[") + to_string(index) + string("].attenuation.constant")), attenuation->z);
	shader->loadVec3(&(string("pointLights[") + to_string(index) + string("].position")), position);
	shader->loadFloat(&(string("pointLights[") + to_string(index) + string("].range")), range);
}

Vec3 * PointLight::getColor() {
	return color;
}

void PointLight::setColor(Vec3 * colorIn) {
	delete color;
	color = colorIn;
}

float PointLight::getIntensity() {
	return intensity;
}

void PointLight::setIntensity(float intensityIn) {
	intensity = intensityIn;
}

Vec3 * PointLight::getAttenuation() {
	return attenuation;
}

void PointLight::setAttenuation(Vec3 * attenuationIn) {
	delete attenuation;
	attenuation = attenuationIn;
}

Vec3 * PointLight::getPosition() {
	return position;
}

void PointLight::setPosition(Vec3 * positionIn) {
	delete position;
	position = positionIn;
}

float PointLight::getRange() {
	return range;
}

void PointLight::setRange(float rangeIn) {
	range = rangeIn;
}

PointLight::~PointLight() {
	delete color;
	delete attenuation;
	delete position;
}