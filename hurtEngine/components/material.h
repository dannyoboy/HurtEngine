#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <string>
#include "hurtEngine/math/vec3.h"
#include "hurtEngine/rendering/shader.h"
#include "hurtEngine/rendering/texture.h"

using namespace std;

class Material {
public:
	Material(Vec3 * colorIn, float ambientIn, float diffuseIn, float specularIn, int shininessIn);
	Material(string * diffuseMapFile, float ambientIn, float diffuseIn, float specularIn, int shininessIn);
	Material(string * diffuseMapFile, string * lightMapFile, int shininessIn);
	void loadAndBind(Shader * shader);
	~Material();
private:
	Vec3 * color;
	Texture * diffuseMap;
	Texture * lightMap;
	float ambient;
	float diffuse;
	float specular;
	int shininess;
};