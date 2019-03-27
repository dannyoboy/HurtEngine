#pragma once

#include <iostream>
#include <string>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "hurtEngine/math/vec3.h"
#include "hurtEngine/input/inputManager.h"

using namespace std;

class Game {
public:
	static Game * instance();
	void initGame(int width, int height, string * title, Vec3 * clearColor);
	void resizeWindow(int width, int height);
	void setClearColor(Vec3 * clearColor);
	void close(int status);
private:
	GLFWwindow * window = nullptr;
	bool closed = false;

	inline Game() {};
	void initContext();
	GLFWwindow * createWindow(int width, int height, string * title);
	void checkGLAD();
	void initConfig(Vec3 * clearColor);
	void gameLoop(GLFWwindow * window);
	void cleanUp();
};