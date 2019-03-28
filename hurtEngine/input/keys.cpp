#include "keys.h"

static std::vector<bool> keysPressed(HURT_NUM_KEYS, false);
static std::vector<bool> keysDown(HURT_NUM_KEYS, false);
static std::vector<bool> keysReleased(HURT_NUM_KEYS, false);

void hurt::updateKeys(GLFWwindow * window) {
	for (int key = 0; key < HURT_NUM_KEYS; key++) {
		bool keyDown = glfwGetKey(window, key);
		keysReleased[key] = keysDown[key] && !keyDown;
		keysPressed[key] = !keysDown[key] && keyDown;
		keysDown[key] = keyDown;
	}
}

bool hurtKeyPressed(int key) {
	return keysPressed[key];
}

bool hurtKeyDown(int key) {
	return keysDown[key];
}

bool hurtKeyReleased(int key) {
	return keysReleased[key];
}