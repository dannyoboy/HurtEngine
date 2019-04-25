#include "dragon.h"

void Dragon::onUpdate() {
	list<Entity *> * guys = Game::instance()->getScene(&string("scene1"))->getEntities(&string("guy"));
	for (list<Entity *>::iterator iter = guys->begin(); iter != guys->end(); ++iter) {
		Vec3 * collision = getCollideable()->collisionWith((*iter)->getCollideable());

		if (collision != nullptr) {
			cout << "Collision: (" << collision->x << "," << collision->y << "," << collision->z << ")" << endl;
		}

		delete collision;
	}

	delete guys;

	if (hurtKeyDown(HURT_KEY_EQUAL)) {
		getSkybox()->setRotation(getSkybox()->getRotation()->add(&Vec3(0, 50 * Time::instance()->getDelta(), 0)));
	}
}