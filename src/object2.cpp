#include "object2.h"

Object2::Object2(string * tag, Vec3 * colorIn) : Entity(tag), color(colorIn) {}

void Object2::onSceneLoad() {
	if (Game::instance()->isInitialized()) {
		Game::instance()->setClearColor(color);
	}
	cout << "Switched to scene 2!" << endl;
}

void Object2::onUpdate() {
	if (hurtKeyPressed(HURT_KEY_N)) {
		Game::instance()->setCurrentScene(&string("scene1"));
	}
}

void Object2::onAdd() {
	cout << "Object 2 added to scene!" << endl;
}

void Object2::onGameStart() {
	cout << "Game started in scene 2" << endl;
}