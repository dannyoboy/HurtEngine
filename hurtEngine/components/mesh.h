#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "hurtEngine/math/vec2.h"
#include "hurtEngine/math/vec3.h"

using namespace std;

class Mesh {
public:
	Mesh(string * objFile);
	void bind();
	unsigned int getIndexCount();
	~Mesh();
private:
	unsigned int vao;
	unsigned int vertVbo;
	unsigned int texVbo;
	unsigned int normVbo;
	unsigned int indexEbo;
	unsigned int indexCount;
};