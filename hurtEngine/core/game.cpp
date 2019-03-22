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
	// TODO
}

void Game::close(int status) {
	// TODO
}

// Private

void Game::initContext() {
	// TODO
}

void Game::checkGLAD() {
	// TODO
}

void Game::initConfig(Vec3 * clearColor) {
	// TODO
}

void Game::gameLoop(GLFWwindow * window) {
	// TODO
}

void Game::cleanUp() {
	// TODO
}