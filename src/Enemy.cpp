#include "enemy.h"

constexpr int ENEMY_SIZE = 3;
static string TAG("Enemy");
constexpr float ENEMY_SPEED = 12;
constexpr float SLOW_SPEED = 6;

Enemy::Enemy(Scene * scene, Vec3 * enemyStartPos, int healthAmt, Mesh * mesh, Material * material, int rewardIn, int damageIn, float scaleFactor) : Entity(&TAG), reward(rewardIn), damage(damageIn) {
	Transform * transform = new Transform(enemyStartPos, new Vec3(60, 0, 0), new Vec3(ENEMY_SIZE * scaleFactor, ENEMY_SIZE * scaleFactor, ENEMY_SIZE * scaleFactor));
	Kinematics * kinematics = new Kinematics(transform, new Vec3(ENEMY_SPEED, 0, 0), new Vec3(0, 0, 0), new Vec3(0, 0, 0), new Vec3(0, 0, 0));
	Collideable * collideable = new Collideable(transform, new Vec3(0, 0, 0), ENEMY_SIZE/2);
	this->attachTransform(transform);
	this->attachMesh(mesh);
	this->attachMaterial(material);
	this->attachKinematics(kinematics);
	this->attachCollideable(collideable);
	health = healthAmt;
	scene->addEntity(this);
	theScene = scene;
}

void Enemy::death() {
	theScene->removeEntity(this);
	healthMoney += reward;
}

void Enemy::takeDamage(int damage) {
	health -= damage;
	if (health <= 0) {
		death();
	}
}

void Enemy::onUpdate() {
	list<Entity *> * radios = Game::instance()->getScene(&string("main"))->getEntities(&string("radio"));
	bool inRadioRange = false;
	for (list<Entity *>::iterator iter = radios->begin(); iter != radios->end(); ++iter) {
		Radio * radio = (Radio *)(*iter);
		Vec3 * diff = getTransform()->getPos()->sub(radio->getTransform()->getPos());
		float distance = diff->length();
		delete diff;

		if (distance < radio->getRange() * radio->getCamFactor() / 2) {
			Vec3 * dir = getKinematics()->getVel();
			Vec3 * normDir = dir->normalized();
			Vec3 * newVel = normDir->mul(SLOW_SPEED);
			getKinematics()->setVel(newVel);
			delete normDir;
			inRadioRange = true;
			break;
		}
	}

	if (!inRadioRange) {
		Vec3 * dir = getKinematics()->getVel();
		Vec3 * normDir = dir->normalized();
		Vec3 * newVel = normDir->mul(ENEMY_SPEED);
		getKinematics()->setVel(newVel);
		delete normDir;
	}

	distanceTraveled += getKinematics()->getVel()->length() * TIME_SYNC;
}

float Enemy::getDistanceTraveled() {
	return distanceTraveled;
}

int Enemy::getDamage() {
	return damage;
}

Enemy::~Enemy() {
	delete getTransform();
	delete getKinematics();
	delete getCollideable();
}