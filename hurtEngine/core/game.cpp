#include "game.h"

static Game * gameInstance = nullptr;

// Public

Game * Game::instance() {
	if (gameInstance == nullptr) {
		gameInstance = new Game();
	}

	return gameInstance;
}

void Game::initGame(int width, int height, string * title, Vec3 * clearColor) {
	initContext();
	window = createWindow(width, height, title);
	checkGLAD();
	initConfig(clearColor);
	
	gameLoop(window);
	cleanUp();
}

void Game::resizeWindow(int width, int height) {
	glfwSetWindowSize(window, width, height);
}

void Game::setClearColor(Vec3 * clearColor) {
	glClearColor(clearColor->x, clearColor->y, clearColor->z, 1.0f);
}

void Game::close(int status) {
	if (status) {
		cerr << "Game terminated early" << endl;
		exit(-1);
	}
	else {
		closed = true;
	}
}

// Private

void Game::initContext() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

GLFWwindow * Game::createWindow(int width, int height, string * title) {
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	GLFWwindow* newWindow = glfwCreateWindow(width, height, title->c_str(), NULL, NULL);

	if (newWindow == NULL) {
		cerr << "Failed to create GLFW window" << endl;
		glfwTerminate();
		exit(-1);
	}

	glfwMakeContextCurrent(newWindow);
	glfwSetFramebufferSizeCallback(newWindow, [](GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); });

	return newWindow;
}

void Game::checkGLAD() {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cerr << "Failed to initialize GLAD" << endl;
		exit(-1);
	}
}

void Game::initConfig(Vec3 * clearColor) {
	setClearColor(clearColor);
}

void Game::gameLoop(GLFWwindow * window) {
	while (!(glfwWindowShouldClose(window) || closed)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		hurt::updateInput(window);

		// TODO: Add additional updating here

		glfwSwapBuffers(window);
	}
}

void Game::cleanUp() {
	// TODO: Add additional resource clean up here

	glfwTerminate();
}