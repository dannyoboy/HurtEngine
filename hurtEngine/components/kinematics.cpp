#include "kinematics.h"

Kinematics::Kinematics(Transform * transformIn, Vec3 * velIn, Vec3 * angVelIn, Vec3 * accIn, Vec3 * angAccIn) : transform(transformIn), vel(velIn), angVel(angVelIn), acc(accIn), angAcc(angAccIn) {}

void Kinematics::update() {
	float deltaTime = Time::instance()->getDelta();
	
	Vec3 * deltaVel = acc->mul(deltaTime);
	Vec3 * newVel = vel->add(deltaVel);
	delete deltaVel;
	delete vel;
	vel = newVel;

	Vec3 * deltaAngVel = angAcc->mul(deltaTime);
	Vec3 * newAngVel = angVel->add(deltaAngVel);
	delete deltaAngVel;
	delete angVel;
	angVel = newAngVel;

	Vec3 * pos = transform->getPos();
	Vec3 * deltaPos = vel->mul(deltaTime);
	Vec3 * newPos = pos->add(deltaPos);
	transform->setPos(newPos);
	delete deltaPos;

	Vec3 * angPos = transform->getRot();
	Vec3 * deltaAngPos = angVel->mul(deltaTime);
	Vec3 * newAngPos = angPos->add(deltaAngPos);
	transform->setRot(newAngPos);
	delete deltaAngPos;
}

Vec3 * Kinematics::getVel() {
	return vel;
}

void Kinematics::setVel(Vec3 * velIn) {
	delete vel;
	vel = velIn;
}

Vec3 * Kinematics::getAngVel() {
	return angVel;
}

void Kinematics::setAngVel(Vec3 * angVelIn) {
	delete angVel;
	angVel = angVelIn;
}

Vec3 * Kinematics::getAcc() {
	return acc;
}

void Kinematics::setAcc(Vec3 * accIn) {
	delete acc;
	acc = accIn;
}

Vec3 * Kinematics::getAngAcc() {
	return angAcc;
}

void Kinematics::setAngAcc(Vec3 * angAccIn) {
	delete angAcc;
	angAcc = angAccIn;
}

Kinematics::~Kinematics() {
	delete vel;
	delete angVel;
	delete acc;
	delete angAcc;
}