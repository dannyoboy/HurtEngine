#include "cursor.h"

static GLFWwindow * window = nullptr;
static Vec2 * windowSize;
static Vec2 cursorPos(0, 0);

void hurt::setCursorWindow(GLFWwindow * windowIn, Vec2 * windowSizeIn) {
	window = windowIn;
	windowSize = windowSizeIn;
}

void hurt::updateCursor() {
	double cursorX, cursorY;
	glfwGetCursorPos(window, &cursorX, &cursorY);
	cursorPos.x = (float)(cursorX * 2 / windowSize->x - 1);
	cursorPos.y = (float)(cursorY * -2 / windowSize->y + 1);
}

Vec2 * hurtGetCursorPos() {
	return &cursorPos;
}

void hurtSetCursorPos(Vec2 * pos) {
	double winPosX = (pos->x + 1) * windowSize->x / 2.0;
	double winPosY = (pos->y - 1) * windowSize->y / -2.0;
	glfwSetCursorPos(window, winPosX, winPosY);

	cursorPos.x = (float)winPosX;
	cursorPos.y = (float)winPosY;
}

void hurtSetCursorVisible(bool visible) {
	glfwSetInputMode(window, GLFW_CURSOR, visible ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_HIDDEN);
}