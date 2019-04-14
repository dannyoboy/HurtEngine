#include "object1.h"

Object1::Object1(string * tag, Vec3 * colorIn) : Entity(tag), color(colorIn) {}

void Object1::onSceneLoad() {
	if (Game::instance()->isInitialized()) {
		Game::instance()->setClearColor(color);
	}
	cout << "Switched to scene 1!" << endl;
}

void Object1::onUpdate() {
	if (hurtKeyPressed(HURT_KEY_N)) {
		Game::instance()->setCurrentScene(&string("scene2"));
	}
	if (hurtKeyDown(HURT_KEY_U)) {
		cout << "Scene 1 update" << endl;
	}
	if (hurtKeyReleased(HURT_KEY_I)) {
		cout << "Scene 1 I released" << endl;
	}
	if (hurtKeyPressed(HURT_KEY_K)) {
		Game::instance()->getScene(&string("scene1"))->addEntity(new Tester());
		cout << "Added an entity!" << endl;
	}
	if (hurtKeyPressed(HURT_KEY_L)) {
		Game::instance()->getScene(&string("scene1"))->removeEntities(&string("tester"));
		cout << "Removed all testers!" << endl;
	}
}

void Object1::onLateUpdate() {
	if (hurtKeyPressed(HURT_KEY_U)) {
		cout << "Scene 1 late update" << endl;
	}
}

void Object1::onAdd() {
	cout << "Object 1 added to scene!" << endl;
}

void Object1::onGameStart() {
	cout << "Game started in scene 1" << endl;
	Game::instance()->setClearColor(&Vec3(1, 0, 1));
}

void Object1::onGameStop() {
	cout << "Game stopping in scene 1..." << endl;
}