#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "hurtEngine/math/vec2.h"
#include "hurtEngine/core/game.h"

namespace hurt {
	void setCursorWindow(GLFWwindow * window);
	void updateCursor();
}

Vec2 * hurtGetCursorPos();
void hurtSetCursorPos(Vec2 * pos);
void hurtSetCursorVisible(bool visible);