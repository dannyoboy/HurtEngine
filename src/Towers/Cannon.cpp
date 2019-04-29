#include "Cannon.h"

constexpr float CANNONBALL_HEIGHT = 1.65f;

static string TAG("cannon");

Cannon::Cannon(float rangeIn, Entity * rangeVisualIn, Transform * transformIn, Material * material, Mesh * mesh, float camFactorIn, float towerYIn) :
	Tower(rangeIn, rangeVisualIn, transformIn, material, mesh, camFactorIn, towerYIn, CANNON_RADIUS, CANNON_OFFSET, &TAG) {
}

void Cannon::onLateUpdate() {
	if (cooldown <= 0) {
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

		if (furthestEnemy != nullptr) {
			Vec3 * thisPos = getTransform()->getPos();
			Vec3 * pos = new Vec3(thisPos->x, thisPos->y + CANNONBALL_HEIGHT, thisPos->z);
			Vec3 * diff = furthestEnemy->getTransform()->getPos()->sub(pos);
			Vec3 * dir = diff->normalized();
			Cannonball * cannonball = new Cannonball(pos, dir);

			mainScene->addEntity(cannonball);
			cooldown = CANNON_COOLDOWN;

			if (diff->x != 0 || diff->z != 0) {
				float rotY = (&Vec3(diff->x, 0, diff->z))->angleBetween(&Vec3(0, 0, diff->x < 0 ? -1.0f : 1.0f)) + (diff->x < 0 ? 180 : 0);
				getTransform()->setRot(new Vec3(0, rotY, 0));
			}

			delete diff;
		}
	}

	cooldown -= TIME_SYNC;
}