#include "inputManager.h"

void hurt::initInput(GLFWwindow * window, Vec2 * windowSize) {
	hurt::setCursorWindow(window, windowSize);
}

void hurt::updateInput(GLFWwindow * window) {
	glfwPollEvents();
	hurt::updateKeys(window);
	hurt::updateButtons(window);
	hurt::updateCursor();
}