#include "debug.h"

void hurt::Debug::enabled(bool enableIn) {
	enable = enableIn;
}

void hurt::Debug::update() {
	if (enable) {
		if (hurtKeyPressed(HURT_KEY_F10)) {
			if (wireframeMode) {
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}
			else {
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}
			wireframeMode = !wireframeMode;
		}
	}
}