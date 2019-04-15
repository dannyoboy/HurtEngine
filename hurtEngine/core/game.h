#pragma once

#include <iostream>
#include <string>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "hurtEngine/math/vec3.h"
#include "hurtEngine/input/inputManager.h"
#include "hurtEngine/ecs/scene.h"
#include "hurtEngine/utils/time.h"

using namespace std;

class Game {
public:
	static Game * instance();
	void initGame(int width, int height, string * title, Vec3 * clearColor);
	void resizeWindow(int width, int height);
	void setClearColor(Vec3 * clearColor);
	bool addScene(Scene * scene);
	Scene * getScene(string * name);
	bool setCurrentScene(string * name);
	bool isInitialized();
	void close(int status);
private:
	GLFWwindow * window = nullptr;
	bool initialized = false;
	bool closed = false;
	list<Scene *> * scenes = new list<Scene *>();
	Scene * currScene = nullptr;

	inline Game() {};
	void initContext();
	GLFWwindow * createWindow(int width, int height, string * title);
	void checkGLAD();
	void initConfig(Vec3 * clearColor);
	void gameLoop(GLFWwindow * window);
	void updateCurrentScene();
	void runOnGameStart();
	void runOnGameStop();
	~Game();
};