#include "material.h"

Material::Material(Vec3 * colorIn, float ambientIn, float diffuseIn, float specularIn, int shininessIn) : color(colorIn), ambient(ambientIn), diffuse(diffuseIn), specular(specularIn), shininess(shininessIn) {
	diffuseMap = nullptr;
	lightMap = nullptr;
}

Material::Material(string * diffuseMapFile, float ambientIn, float diffuseIn, float specularIn, int shininessIn) {
	// TODO
}

Material::Material(string * diffuseMapFile, string * lightMapFile, int shininessIn) {
	// TODO
}

void Material::loadAndBind(Shader * shader) {
	// TODO
}

Material::~Material() {
	if (color != nullptr) {
		delete color;
	}
	if (diffuseMap != nullptr) {
		delete diffuseMap;
	}
	if (lightMap != nullptr) {
		delete lightMap;
	}
}