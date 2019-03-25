#include "game.h"

static Game * gameInstance = nullptr;

// Public

Game * Game::instance() {
	if (gameInstance == nullptr) {
		gameInstance = new Game();
	}

	return gameInstance;
}

void Game::initGame(int width, int height, char * title, Vec3 * clearColor) {
	initContext();
	GLFWwindow* window = createWindow(width, height, title);
	checkGLAD();
	initConfig(clearColor);

	gameLoop(window);
	cleanUp();
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

GLFWwindow * Game::createWindow(int width, int height, char * title) {
	GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);

	if (window == NULL) {
		cerr << "Failed to create GLFW window" << endl;
		glfwTerminate();
		exit(-1);
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); });

	return window;
}

void Game::checkGLAD() {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cerr << "Failed to initialize GLAD" << endl;
		exit(-1);
	}
}

void Game::initConfig(Vec3 * clearColor) {
	glClearColor(clearColor->x, clearColor->y, clearColor->z, 1.0f);
}

void Game::gameLoop(GLFWwindow * window) {
	while (!(glfwWindowShouldClose(window) || closed)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// TODO: update input here

		// TODO: Add additional updating here

		glfwSwapBuffers(window);
	}
}

void Game::cleanUp() {
	// TODO: Add additional resource clean up here

	glfwTerminate();
}