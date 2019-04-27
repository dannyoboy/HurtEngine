#include "controller.h"

void Controller::onUpdate() {
	Camera * cam = Game::instance()->getScene(&string("mainScene"))->getCamera();
	float delta = Time::instance()->getDelta();

	float turnVert = 0;
	if (hurtKeyDown(HURT_KEY_UP)) {
		turnVert += CAM_TURN_SPEED;
	}
	if (hurtKeyDown(HURT_KEY_DOWN)) {
		turnVert -= CAM_TURN_SPEED;
	}
	cam->turnVertical(turnVert * delta);

	float turnHoriz = 0;
	if (hurtKeyDown(HURT_KEY_RIGHT)) {
		turnHoriz += CAM_TURN_SPEED;
	}
	if (hurtKeyDown(HURT_KEY_LEFT)) {
		turnHoriz -= CAM_TURN_SPEED;
	}
	cam->turnHorizontal(turnHoriz * delta);

	float moveForward = 0;
	if (hurtKeyDown(HURT_KEY_W)) {
		moveForward += CAM_MOVE_SPEED;
	}
	if (hurtKeyDown(HURT_KEY_S)) {
		moveForward -= CAM_MOVE_SPEED;
	}
	cam->moveForward(moveForward * delta);

	float moveRight = 0;
	if (hurtKeyDown(HURT_KEY_D)) {
		moveRight += CAM_MOVE_SPEED;
	}
	if (hurtKeyDown(HURT_KEY_A)) {
		moveRight -= CAM_MOVE_SPEED;
	}
	cam->moveRight(moveRight * delta);
}