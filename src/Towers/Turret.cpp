#include "Turret.h"

constexpr float BULLET_HEIGHT = 2.25f;

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
		Vec3 * thisPos = getTransform()->getPos();
		Vec3 * pos = new Vec3(thisPos->x, thisPos->y + BULLET_HEIGHT, thisPos->z);
		Vec3 * diff = furthestEnemy->getTransform()->getPos()->sub(pos);
		Vec3 * dir = diff->normalized();
		Bullet * bullet = new Bullet(pos, dir);

		mainScene->addEntity(bullet);
		cooldown = TURRET_COOLDOWN;

		if (diff->x != 0 || diff->z != 0) {
			float rotY = (&Vec3(diff->x, 0, diff->z))->angleBetween(&Vec3(0, 0, diff->x < 0 ? -1.0f : 1.0f)) + (diff->x < 0 ? 0 : 180);
			getTransform()->setRot(new Vec3(0, rotY, 0));
		}

		delete diff;
	}

	cooldown -= TIME_SYNC;
}