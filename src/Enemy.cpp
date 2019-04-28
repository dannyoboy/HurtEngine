#include "enemy.h"

constexpr int ENEMY_SIZE = 3;
static string TAG("Enemy");

Enemy::Enemy(Scene * scene, Vec3 * enemyStartPos) : Entity(&TAG) { //ADD PARAMETER FOR STARTING POS BASED ON LVL
	 //half the height/width of window
	Mesh * mesh = new Mesh(&string("res/drone.obj"));					        //change below
	Transform * transform = new Transform(enemyStartPos, new Vec3(60, 0, 0), new Vec3(ENEMY_SIZE, ENEMY_SIZE, ENEMY_SIZE)); //change to depend on FOV
	Material * material = new Material(&string("res/drone.png"), 0.4f, 0.7f, 0.9f, 8);
	Kinematics * kinematics = new Kinematics(transform, new Vec3(12, 0, 0), new Vec3(0, 0, 0), new Vec3(0, 0, 0), new Vec3(0, 0, 0));
	Collideable * collideable = new Collideable(transform, new Vec3(0, 0, 0), ENEMY_SIZE/2);
	this->attachTransform(transform);
	this->attachMesh(mesh);
	this->attachMaterial(material);
	this->attachKinematics(kinematics);
	this->attachCollideable(collideable);
	scene->addEntity(this);
}

void Enemy::death() {
	delete this->getTransform();
	delete this->getMaterial();
	delete this->getKinematics();
	delete this->getCollideable();
}