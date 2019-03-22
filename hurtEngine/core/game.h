#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "hurtEngine/math/vec3.h"

class Game {
public:
	static Game * instance();
	void initGame(int width, int height, char * title, Vec3 * clearColor);
	void close(int status);
private:
	void initContext();
	void checkGLAD();
	void initConfig(Vec3 * clearColor);
	void gameLoop(GLFWwindow * window);
	void cleanUp();
};