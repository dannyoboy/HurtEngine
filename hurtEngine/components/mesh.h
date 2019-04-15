#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <string>

using namespace std;

class Mesh {
public:
	Mesh(string * objFile);
	void bind();
	unsigned int getNumIndices();
	~Mesh();
private:
	unsigned int vao;
	unsigned int vertVbo;
	unsigned int texVbo;
	unsigned int normVbo;
	unsigned int indexEbo;
	unsigned int numIndices;
};