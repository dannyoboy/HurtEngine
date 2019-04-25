#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "hurtEngine/input/keys.h"

namespace hurt {
	class Debug {
	public:
		void enabled(bool enableIn);
		void update();
	private:
		bool enable = false;
		bool wireframeMode = false;
	};
}