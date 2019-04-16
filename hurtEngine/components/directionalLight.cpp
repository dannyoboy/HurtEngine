#include "directionalLight.h"

DirectionalLight::DirectionalLight(Vec3 * colorIn, float intensityIn, Vec3 * directionIn) : color(colorIn), intensity(intensityIn), direction(directionIn) {}

void DirectionalLight::load(Shader * shader, int index) {
	shader->loadVec3(&(string("directionalLights[") + to_string(index) + string("].basic.color")), color);
	shader->loadFloat(&(string("directionalLights[") + to_string(index) + string("].basic.intensity")), intensity);
	shader->loadVec3(&(string("directionalLights[") + to_string(index) + string("].direction")), direction);
}

Vec3 * DirectionalLight::getColor() {
	return color;
}

void DirectionalLight::setColor(Vec3 * colorIn) {
	delete color;
	color = colorIn;
}

float DirectionalLight::getIntensity() {
	return intensity;
}

void DirectionalLight::setIntensity(float intensityIn) {
	intensity = intensityIn;
}

Vec3 * DirectionalLight::getDirection() {
	return direction;
}

void DirectionalLight::setDirection(Vec3 * directionIn) {
	delete direction;
	direction = directionIn;
}

DirectionalLight::~DirectionalLight() {
	delete color;
	delete direction;
}