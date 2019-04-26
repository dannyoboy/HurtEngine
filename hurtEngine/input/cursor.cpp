#include "cursor.h"

static GLFWwindow * window = nullptr;
static Vec2 cursorPos(0, 0);

void hurt::setCursorWindow(GLFWwindow * windowIn) {
	window = windowIn;
}

void hurt::updateCursor() {
	double cursorX, cursorY;
	glfwGetCursorPos(window, &cursorX, &cursorY);
	Vec2 * windowSize = Game::instance()->getWindowSize();
	cursorPos.x = (float)(cursorX * 2 / windowSize->x - 1);
	cursorPos.y = (float)(cursorY * -2 / windowSize->y + 1);
}

Vec2 * hurtGetCursorPos() {
	return &cursorPos;
}

void hurtSetCursorPos(Vec2 * pos) {
	Vec2 * windowSize = Game::instance()->getWindowSize();
	double winPosX = (pos->x + 1) * windowSize->x / 2.0;
	double winPosY = (pos->y - 1) * windowSize->y / -2.0;
	glfwSetCursorPos(window, winPosX, winPosY);

	cursorPos.x = (float)winPosX;
	cursorPos.y = (float)winPosY;
}

void hurtSetCursorVisible(bool visible) {
	glfwSetInputMode(window, GLFW_CURSOR, visible ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_HIDDEN);
}