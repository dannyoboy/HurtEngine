#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "hurtEngine/math/vec2.h"

constexpr float HURT_QUAD_VERTICES[] = {
	-0.5f, -0.5f,
	-0.5f,  0.5f,
	 0.5f,  0.5f,
	 0.5f, -0.5f
};

constexpr unsigned int HURT_QUAD_INDICES[] = {
	0, 1, 2,
	2, 3, 0
};

class GUIQuad {
public:
	GUIQuad(Vec2 * texCoordsLow, Vec2 * texCoordsHigh);
	void bind();
	unsigned int getIndexCount();
	~GUIQuad();
private:
	unsigned int vao;
	unsigned int vertVbo;
	unsigned int texVbo;
	unsigned int indexEbo;
	unsigned int indexCount;
};