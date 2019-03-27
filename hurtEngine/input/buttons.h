#pragma once

#include <vector>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

constexpr int NUM_BUTTONS = 8;

namespace hurt {
	void updateButtons(GLFWwindow * window);
};

bool hurtButtonPressed(int button);
bool hurtButtonDown(int button);
bool hurtButtonReleased(int button);

constexpr int HURT_BUTTON_1 = GLFW_MOUSE_BUTTON_1;
constexpr int HURT_BUTTON_2 = GLFW_MOUSE_BUTTON_2;
constexpr int HURT_BUTTON_3 = GLFW_MOUSE_BUTTON_3;
constexpr int HURT_BUTTON_4 = GLFW_MOUSE_BUTTON_4;
constexpr int HURT_BUTTON_5 = GLFW_MOUSE_BUTTON_5;
constexpr int HURT_BUTTON_6 = GLFW_MOUSE_BUTTON_6;
constexpr int HURT_BUTTON_7 = GLFW_MOUSE_BUTTON_7;
constexpr int HURT_BUTTON_8 = GLFW_MOUSE_BUTTON_8;
constexpr int HURT_BUTTON_LAST = GLFW_MOUSE_BUTTON_LAST;
constexpr int HURT_BUTTON_LEFT = GLFW_MOUSE_BUTTON_LEFT;
constexpr int HURT_BUTTON_RIGHT = GLFW_MOUSE_BUTTON_RIGHT;
constexpr int HURT_BUTTON_MIDDLE = GLFW_MOUSE_BUTTON_MIDDLE;