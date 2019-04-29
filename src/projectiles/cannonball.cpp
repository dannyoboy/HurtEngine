#include "cannonball.h"

constexpr float CANNONBALL_SPEED = 50;
constexpr float CANNONBALL_SIZE = 1.25f;
constexpr float CANNONBALL_BOUNDS = 1;
constexpr float SPLASH_RANGE = 5;

static string TAG("cannonball");

Cannonball::Cannonball(Vec3 * pos, Vec3 * direction) : Entity(&TAG) {
	Transform * transform = new Transform(pos, new Vec3(0, 0, 0), new Vec3(CANNONBALL_SIZE, CANNONBALL_SIZE, CANNONBALL_SIZE));
	Vec3 * vel = direction->mul(CANNONBALL_SPEED);
	Kinematics * kinematics = new Kinematics(transform, vel, new Vec3(0, 0, 0), new Vec3(0, 0, 0), new Vec3(0, 0, 0));
	Collideable * collideable = new Collideable(transform, new Vec3(0, 0, 0), CANNONBALL_BOUNDS);

	attachTransform(transform);
	attachKinematics(kinematics);
	attachCollideable(collideable);
	attachMaterial(cannonballMaterial);
	attachMesh(HURT_SPHERE);

	delete direction;
}

void Cannonball::onUpdate() {
	Scene * mainScene = Game::instance()->getScene(&string("main"));
	Vec3 * pos = getTransform()->getPos();
	if (pos->x < -1000 || pos->x > 1000 || pos->z < -1000 || pos->z > 1000) {
		mainScene->removeEntity(this);
		return;
	}

	list<Entity *> * enemies = mainScene->getEntities(&string("Enemy"));
	bool collisionOccurred = false;
	for (list<Entity *>::iterator iter = enemies->begin(); iter != enemies->end(); ++iter) {
		Enemy * enemy = (Enemy *)(*iter);
		Vec3 * collision = getCollideable()->collisionWith(enemy->getCollideable());

		if (collision != nullptr) {
			collisionOccurred = true;
			delete collision;
			break;
		}
	}

	if (collisionOccurred) {
		for (list<Entity *>::iterator iter = enemies->begin(); iter != enemies->end(); ++iter) {
			Enemy * enemy = (Enemy *)(*iter);
			Vec3 * diff = enemy->getTransform()->getPos()->sub(getTransform()->getPos());
			float distance = diff->length();
			delete diff;

			if (distance <= SPLASH_RANGE) {
				enemy->takeDamage(1);
			}
		}

		mainScene->removeEntity(this);
	}
}

Cannonball::~Cannonball() {
	delete getTransform();
	delete getKinematics();
	delete getCollideable();
}