#include "buttons.h"

static std::vector<bool> buttonsPressed(NUM_BUTTONS, false);
static std::vector<bool> buttonsDown(NUM_BUTTONS, false);
static std::vector<bool> buttonsReleased(NUM_BUTTONS, false);

void hurt::updateButtons(GLFWwindow * window) {
	for (int button = 0; button < NUM_BUTTONS; button++) {
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