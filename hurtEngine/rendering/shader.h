#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <string>
#include <iostream>
#include <fstream>
#include <streambuf>
#include "hurtEngine/math/vec2.h"
#include "hurtEngine/math/vec3.h"
#include "hurtEngine/math/vec4.h"
#include "hurtEngine/math/mat4.h"

using namespace std;

class Shader {
public:
	Shader(string * vertexFile, string * fragmentFile);
	void loadFloat(string * name, float val);
	void loadInt(string * name, int val);
	void loadBool(string * name, bool val);
	void loadVec2(string * name, Vec2 * vec);
	void loadVec3(string * name, Vec3 * vec);
	void loadVec4(string * name, Vec4 * vec);
	void loadMat4(string * name, Mat4 * mat);
	void use();
	~Shader();
private:
	unsigned int program;
};