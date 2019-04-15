#include "material.h"

Material::Material(Vec3 * colorIn, float ambientIn, float diffuseIn, float specularIn, int shininessIn) : color(colorIn), ambient(ambientIn), diffuse(diffuseIn), specular(specularIn), shininess(shininessIn) {
	diffuseMap = nullptr;
	lightMap = nullptr;
}

Material::Material(string * diffuseMapFile, float ambientIn, float diffuseIn, float specularIn, int shininessIn) : ambient(ambientIn), diffuse(diffuseIn), specular(specularIn), shininess(shininessIn) {
	diffuseMap = new Texture(diffuseMapFile);
	color = nullptr;
	lightMap = nullptr;
}

Material::Material(string * diffuseMapFile, string * lightMapFile, int shininessIn) : shininess(shininessIn) {
	diffuseMap = new Texture(diffuseMapFile);
	lightMap = new Texture(lightMapFile);
	color = nullptr;
	ambient = 0;
	diffuse = 0;
	specular = 0;
}

void Material::loadAndBind(Shader * shader) {
	if (color != nullptr) {
		shader->loadVec3(&string("material.color"), color);
	}
	if (diffuseMap != nullptr) {
		diffuseMap->bindToUnit(0);
		shader->loadInt(&string("material.diffuseMap"), 0);
	}
	if (lightMap != nullptr) {
		lightMap->bindToUnit(1);
		shader->loadInt(&string("material.lightMap"), 1);
	}

	shader->loadBool(&string("material.useDiffuseMap"), diffuseMap != nullptr);
	shader->loadBool(&string("material.useLightMap"), lightMap != nullptr);
	shader->loadFloat(&string("material.ambient"), ambient);
	shader->loadFloat(&string("material.diffuse"), diffuse);
	shader->loadFloat(&string("material.specular"), specular);
	shader->loadInt(&string("material.shininess"), shininess);
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