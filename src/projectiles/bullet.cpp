#include "bullet.h"

constexpr float BULLET_SPEED = 50;
constexpr float BULLET_SIZE = 0.3f;
constexpr float BULLET_BOUNDS = 1;

static string TAG("bullet");

Bullet::Bullet(Vec3 * pos, Vec3 * direction) : Entity(&TAG) {
	Transform * transform = new Transform(pos, new Vec3(0, 0, 0), new Vec3(BULLET_SIZE, BULLET_SIZE, BULLET_SIZE)); // TODO: change rotation
	Vec3 * vel = direction->mul(BULLET_SPEED);
	Kinematics * kinematics = new Kinematics(transform, vel, new Vec3(0, 0, 0), new Vec3(0, 0, 0), new Vec3(0, 0, 0));
	Collideable * collideable = new Collideable(transform, new Vec3(0, 0, 0), BULLET_BOUNDS);
	
	attachTransform(transform);
	attachKinematics(kinematics);
	attachCollideable(collideable);
	attachMaterial(bulletMaterial);
	attachMesh(bulletMesh);
	
	delete direction;
}

void Bullet::onUpdate() {
	Scene * mainScene = Game::instance()->getScene(&string("main"));
	list<Entity *> * enemies = mainScene->getEntities(&string("Enemy"));
	for (list<Entity *>::iterator iter = enemies->begin(); iter != enemies->end(); ++iter) {
		Enemy * enemy = (Enemy *)(*iter);
		Vec3 * collision = getCollideable()->collisionWith(enemy->getCollideable());

		if (collision != nullptr) {
			// TODO: remove health from enemy, don't remove from scene
			mainScene->removeEntity(enemy);
			mainScene->removeEntity(this);
			delete collision;
			break;
		}
	}
}

Bullet::~Bullet() {
	delete getTransform();
	delete getKinematics();
	delete getCollideable();
}