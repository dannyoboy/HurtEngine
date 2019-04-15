#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"
#include <string>
#include <iostream>

using namespace std;

class Texture {
public:
	Texture(string * textureFile);
	void bindToUnit(unsigned int unit);
	unsigned int getID();
	~Texture();
private:
	unsigned int id;
};