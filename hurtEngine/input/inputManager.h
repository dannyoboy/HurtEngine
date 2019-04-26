#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "keys.h"
#include "buttons.h"
#include "cursor.h"

namespace hurt {
	void initInput(GLFWwindow * window);
	void updateInput(GLFWwindow * window);
};