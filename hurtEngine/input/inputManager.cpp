#include "inputManager.h"

void hurt::initInput(GLFWwindow * window) {
	hurt::setCursorWindow(window);
}

void hurt::updateInput(GLFWwindow * window) {
	glfwPollEvents();
	hurt::updateKeys(window);
	hurt::updateButtons(window);
	hurt::updateCursor();
}