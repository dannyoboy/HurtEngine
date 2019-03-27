#include "inputManager.h"

void hurt::updateInput(GLFWwindow * window) {
	glfwPollEvents();
	hurt::updateKeys(window);
	hurt::updateButtons(window);
}