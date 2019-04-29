#include "Turret.h"

constexpr float BULLET_OFFSET = 2;

static string TAG("turret");

Turret::Turret(float rangeIn, Entity * rangeVisualIn, Transform * transformIn, Material * material, Mesh * mesh, float camFactorIn, float towerYIn) :
	Tower(rangeIn, rangeVisualIn, transformIn, material, mesh, camFactorIn, towerYIn, TURRET_RADIUS, TURRET_OFFSET, &TAG) {
}

void Turret::onLateUpdate() {
	Scene * mainScene = Game::instance()->getScene(&string("main"));
	list<Entity *> * enemies = mainScene->getEntities(&string("Enemy"));
	float furthestDistance = 0;
	Enemy * furthestEnemy = nullptr;
	for (list<Entity *>::iterator iter = enemies->begin(); iter != enemies->end(); ++iter) {
		Enemy * enemy = (Enemy *)(*iter);
		Vec3 * diff = enemy->getTransform()->getPos()->sub(getTransform()->getPos());
		float distance = diff->length();
		delete diff;

		if (distance < getRange() * getCamFactor() / 2 && enemy->getDistanceTraveled() > furthestDistance) {
			furthestDistance = enemy->getDistanceTraveled();
			furthestEnemy = enemy;
		}
	}

	if (furthestEnemy != nullptr && cooldown <= 0) {
		Vec3 * diff = furthestEnemy->getTransform()->getPos()->sub(getTransform()->getPos());
		Vec3 * dir = diff->normalized();
		Vec3 * offset = dir->mul(BULLET_OFFSET);
		Vec3 * pos = getTransform()->getPos()->add(offset);
		Bullet * bullet = new Bullet(pos, dir);
		mainScene->addEntity(bullet);
		delete diff;
		delete offset;
		cooldown = TURRET_COOLDOWN;

		// TODO: change turret rotation
	}

	cooldown -= TIME_SYNC;
}