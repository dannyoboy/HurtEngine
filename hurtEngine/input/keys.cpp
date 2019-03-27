#include "keys.h"

static std::vector<bool> keysPressed(NUM_KEYS, false);
static std::vector<bool> keysDown(NUM_KEYS, false);
static std::vector<bool> keysReleased(NUM_KEYS, false);

void hurt::updateKeys(GLFWwindow * window) {
	for (int key = 0; key < NUM_KEYS; key++) {
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