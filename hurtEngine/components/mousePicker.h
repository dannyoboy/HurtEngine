#pragma once

#include "hurtEngine/components/collideable.h"
#include "hurtEngine/rendering/camera.h"

class MousePicker {
public:
	MousePicker(Collideable * collideableIn, bool enabledIn);
	void updateSelected(Camera * cam, Vec3 * ray);
	bool isSelected();
	bool isEnabled();
	void setEnabled(bool enabledIn);
private:
	Collideable * collideable;
	bool enabled;
	bool selected = false;
};