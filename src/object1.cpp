#include "object1.h"

Object1::Object1(string * tag, Vec3 * colorIn) : Entity(tag), color(colorIn) {}

void Object1::onSceneLoad() {
	if (Game::instance()->isInitialized()) {
		//Game::instance()->setClearColor(color);
	}
	cout << "Switched to scene 1!" << endl;
}

void Object1::onUpdate() {
	if (hurtKeyPressed(HURT_KEY_N)) {
		Game::instance()->setCurrentScene(&string("scene2"));
	}
}

void Object1::onAdd() {
	cout << "Object 1 added to scene!" << endl;
}