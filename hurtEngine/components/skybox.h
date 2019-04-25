#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"
#include <string>
#include "hurtEngine/math/vec3.h"
#include "hurtEngine/rendering/shader.h"
#include "hurtEngine/components/transform.h"

class Skybox {
public:
	Skybox(string textures[], Vec3 * rotIn); // Texture order: R, L, U, D, F, B
	void loadAndRender(Shader * skyboxShader);
	Vec3 * getRotation();
	void setRotation(Vec3 * rotIn);
	~Skybox();
private:
	unsigned int tex;
	unsigned int vao;
	unsigned int vertVbo;
	unsigned int ebo;
	Vec3 * rot;
};