#include "object1.h"

static bool mouseVisible = true;

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

	// Guy controls
	float multiplier = hurtKeyDown(HURT_KEY_LEFT_SHIFT) ? 3.0f : 1.0f;
	list<Entity *> * guys = Game::instance()->getScene(&string("scene1"))->getEntities(&string("guy"));
	Entity * guy = guys->front();
	const float acc = 1;
	if (hurtKeyPressed(HURT_KEY_KP_6)) {
		guy->getKinematics()->setVel(new Vec3(acc * multiplier, 0, 0));
	}
	if (hurtKeyReleased(HURT_KEY_KP_6)) {
		guy->getKinematics()->setVel(new Vec3(0, 0, 0));
	}

	const float angAcc = 20;
	if (hurtKeyPressed(HURT_KEY_KP_8)) {
		guy->getKinematics()->setAngVel(new Vec3(angAcc * multiplier, 0, 0));
	}
	if (hurtKeyReleased(HURT_KEY_KP_8)) {
		guy->getKinematics()->setAngVel(new Vec3(0, 0, 0));
	}
	delete guys;

	// Camera controls
	Camera * cam = Game::instance()->getScene(&string("scene1"))->getCamera();
	
	const float turnSpeed = 70;
	float verticalTurnAmt = 0;
	if (hurtKeyDown(HURT_KEY_UP)) {
		verticalTurnAmt += turnSpeed;
	}
	if (hurtKeyDown(HURT_KEY_DOWN)) {
		verticalTurnAmt -= turnSpeed;
	}
	cam->turnVertical(verticalTurnAmt * Time::instance()->getDelta() * multiplier);

	float horizTurnAmt = 0;
	if (hurtKeyDown(HURT_KEY_LEFT)) {
		horizTurnAmt += turnSpeed;
	}
	if (hurtKeyDown(HURT_KEY_RIGHT)) {
		horizTurnAmt -= turnSpeed;
	}
	cam->turnHorizontal(horizTurnAmt * Time::instance()->getDelta() * multiplier);

	const float moveSpeed = 3;
	float forwardMove = 0;
	if (hurtKeyDown(HURT_KEY_W)) {
		forwardMove += moveSpeed;
	}
	if (hurtKeyDown(HURT_KEY_S)) {
		forwardMove -= moveSpeed;
	}
	cam->moveForward(forwardMove * Time::instance()->getDelta() * multiplier);

	float sideMove = 0;
	if (hurtKeyDown(HURT_KEY_D)) {
		sideMove += moveSpeed;
	}
	if (hurtKeyDown(HURT_KEY_A)) {
		sideMove -= moveSpeed;
	}
	cam->moveRight(sideMove * Time::instance()->getDelta() * multiplier);

	float vertMove = 0;
	if (hurtKeyDown(HURT_KEY_Q)) {
		vertMove += moveSpeed;
	}
	if (hurtKeyDown(HURT_KEY_E)) {
		vertMove -= moveSpeed;
	}
	cam->moveUp(vertMove * Time::instance()->getDelta() * multiplier);

	// Mouse
	if (hurtButtonPressed(HURT_BUTTON_LEFT)) {
		Game::instance()->getScene(&string("scene1"))->getCamera()->setLocked(true);
	}
	if (hurtKeyPressed(HURT_KEY_ESCAPE)) {
		Game::instance()->getScene(&string("scene1"))->getCamera()->setLocked(false);
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