#include "buttons.h"

static std::vector<bool> buttonsPressed(HURT_NUM_BUTTONS, false);
static std::vector<bool> buttonsDown(HURT_NUM_BUTTONS, false);
static std::vector<bool> buttonsReleased(HURT_NUM_BUTTONS, false);

void hurt::updateButtons(GLFWwindow * window) {
	for (int button = 0; button < HURT_NUM_BUTTONS; button++) {
		bool buttonDown = glfwGetMouseButton(window, button);
		buttonsReleased[button] = buttonsDown[button] && !buttonDown;
		buttonsPressed[button] = !buttonsDown[button] && buttonDown;
		buttonsDown[button] = buttonDown;
	}
}

bool hurtButtonPressed(int button) {
	return buttonsPressed[button];
}

bool hurtButtonDown(int button) {
	return buttonsDown[button];
}

bool hurtButtonReleased(int button) {
	return buttonsReleased[button];
}