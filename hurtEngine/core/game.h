#pragma once

#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "hurtEngine/math/vec3.h"

using namespace std;

class Game {
public:
	static Game * instance();
	void initGame(int width, int height, char * title, Vec3 * clearColor);
	void close(int status);
private:
	bool closed = false;

	inline Game() {};
	void initContext();
	GLFWwindow * createWindow(int width, int height, char * title);
	void checkGLAD();
	void initConfig(Vec3 * clearColor);
	void gameLoop(GLFWwindow * window);
	void cleanUp();
};