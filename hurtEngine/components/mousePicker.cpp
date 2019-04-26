#include "mousePicker.h"

MousePicker::MousePicker(Collideable * collideableIn, bool enabledIn) : collideable(collideableIn), enabled(enabledIn) {}

void MousePicker::updateSelected(Camera * cam, Vec3 * ray) {
	if (enabled) {
		Vec3 * center = collideable->worldCenter();
		Vec3 * toCam = cam->getPos()->sub(center);
		
		float b = ray->dot(toCam);
		float c = toCam->dot(toCam) - collideable->getRadius() * collideable->getRadius();
		float discriminant = b * b - c;

		delete center;
		delete toCam;

		selected = discriminant > 0;

		if (selected) {
			collideable->setColor(HURT_BSPHERE_PICKED);
		}
	}
	else {
		selected = false;
	}

	collideable->setPicked(selected);
}

bool MousePicker::isSelected() {
	return selected;
}

bool MousePicker::isEnabled() {
	return enabled;
}

void MousePicker::setEnabled(bool enabledIn) {
	enabled = enabledIn;
}