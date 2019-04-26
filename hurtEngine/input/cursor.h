#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "hurtEngine/math/vec2.h"

namespace hurt {
	void setCursorWindow(GLFWwindow * window, Vec2 * windowSize);
	void updateCursor();
}

Vec2 * hurtGetCursorPos();
void hurtSetCursorPos(Vec2 * pos);
void hurtSetCursorVisible(bool visible);