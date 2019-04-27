#include "enemy.h"

constexpr int ENEMY_SIZE = 4;

Enemy::Enemy(Scene * scene) : Entity(&string("Enemy")) {
	Mesh * mesh = HURT_PLANE;
	Transform * transform = new Transform(new Vec3(0, 0, 0), new Vec3(0, 0, 0), new Vec3(ENEMY_SIZE, 0, ENEMY_SIZE)); //change to depend on FOV 
	Material * material = new Material(new Vec3(0.192f, 0.192f, 0.192f), 0.01f, 0.4f, 0.7f, 8);
	Kinematics * kinematics = new Kinematics(transform, new Vec3(1, 0, 0), new Vec3(30, 0, 0), new Vec3(0, 0, 0), new Vec3(0, 0, 0));
	this->attachTransform(transform);
	this->attachMesh(mesh);
	this->attachMaterial(material);
	this->attachKinematics(kinematics);
	scene->addEntity(this);
}

void Enemy::death() {
	delete this->getTransform();
	delete this->getMaterial();
}