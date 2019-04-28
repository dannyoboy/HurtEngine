#include "enemy.h"

constexpr int ENEMY_SIZE = 3;
static string TAG("Enemy");

Enemy::Enemy(Scene * scene, Vec3 * enemyStartPos, int healthAmt, int meshNum, Level1 * level) : Entity(&TAG) { //ADD PARAMETER FOR STARTING POS BASED ON LVL
	Mesh * mesh = HURT_SPHERE;					        //change below
	Transform * transform = new Transform(enemyStartPos, new Vec3(0, 0, 0), new Vec3(ENEMY_SIZE, ENEMY_SIZE, ENEMY_SIZE)); //change to depend on FOV 
	Material * material = new Material(new Vec3(0.753f, 0.753f, 0.753f), 0.01f, 0.4f, 0, 8);
	Kinematics * kinematics = new Kinematics(transform, new Vec3(12, 0, 0), new Vec3(30, 0, 0), new Vec3(0, 0, 0), new Vec3(0, 0, 0));
	Collideable * collideable = new Collideable(transform, new Vec3(0, 0, 0), ENEMY_SIZE/2);
	this->attachTransform(transform);
	this->attachMesh(mesh);
	this->attachMaterial(material);
	this->attachKinematics(kinematics);
	this->attachCollideable(collideable);
	health = healthAmt;
	scene->addEntity(this);
	theScene = scene;
	level1 = level;
}

void Enemy::death() {
	theScene->removeEntity(this);
	level1->decrementEnemyCount();
}

void Enemy::takeDamage(int damage) {
	health -= damage;
	if (health <= 0) {
		death();
	}
}