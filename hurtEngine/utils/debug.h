#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "hurtEngine/input/keys.h"

namespace hurt {
	class Debug {
	public:
		void enabled(bool enableIn);
		void update();
		bool getWireframeMode();
		bool getShowBspheres();
	private:
		bool enable = false;
		bool wireframeMode = false;
		bool showBspheres = false;
	};
}