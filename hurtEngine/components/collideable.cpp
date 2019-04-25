#include "collideable.h"

Collideable::Collideable(Vec3 * offsetIn, float radiusIn) : offset(offsetIn), radius(radiusIn) {
	color = new Vec3(1, 0, 0);
}

bool Collideable::collidesWith(Collideable * collideable) {
	// TODO
}

Collideable::~Collideable() {
	delete color;
	delete offset;
}