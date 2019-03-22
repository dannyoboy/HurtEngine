#pragma once

#include "hurtEngine/hurtEngine.h"

class Game {
public:
	static void instance();
	void initGame(int width, int height, char * title, Vec3 * clearColor);
	void close(int status);
private:
	Game();
	void initContext();
	void checkGLAD();
	void initConfig(Vec3 * clearColor);
	void gameLoop(GLFWwindow * window);
	void cleanUp();
};