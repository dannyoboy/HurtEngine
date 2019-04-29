#include "Radio.h"

static constexpr float RADIO_COOLDOWN = 0;
static constexpr int RADIO_DAMAGE = 0;
static constexpr int RADIO_COST = 0;
constexpr float ENEMY_SPEED = 12;

Radio::Radio(float rangeIn, Entity * rangeVisualIn, Transform * transformIn, Material * material, Mesh * mesh, float camFactorIn, float towerYIn) :
	Tower(rangeIn, rangeVisualIn, transformIn, material, mesh, camFactorIn, towerYIn, RADIO_RADIUS, RADIO_OFFSET) {
	setTowerValues(RADIO_COOLDOWN, RADIO_DAMAGE, RADIO_COST);
	enemiesInRange = new list<Entity *>();
}

void Radio::onLateUpdate() {
	if (mouse->isSelected() && hurtButtonPressed(HURT_BUTTON_LEFT)) {
		lockRangeVisual();
	}
	if (!enemiesInRange->empty()) {
		for (list<Entity *>::iterator iter = enemiesInRange->begin(); iter != enemiesInRange->end(); ++iter) {
			Entity * enemy = *iter;
			Collideable * collideable = enemy->getCollideable();
			if ((this->getCollideable()->collisionWith(collideable)) == nullptr) {
				enemiesInRange->erase(iter);
				// return to normal speed
				Vec3 * newVel = enemy->getKinematics()->getVel()->mul(2.0f);
				enemy->getKinematics()->setVel(newVel);
			}
		}
	}
	if (currCoolDown == 0) {
		Scene * gameScene = Game::instance()->getScene(&string("main"));
		list<Entity *> * enemies = gameScene->getEntities(&string("Enemy"));
		for (list<Entity *>::iterator iter = enemies->begin(); iter != enemies->end(); ++iter) {
			Entity * enemy = *iter;
			Collideable * collideable = enemy->getCollideable();
			bool inList = false;
			for (list<Entity *>::iterator iter2 = enemiesInRange->begin(); iter2 != enemiesInRange->end(); ++iter2) {
				Entity * enemy2 = *iter2;
				if (enemy2 == enemy) {
					inList = true;
				}
			}
			if ((this->getCollideable()->collisionWith(collideable)) != nullptr && !inList) {
				enemiesInRange->push_back(enemy);
				// slow down enemy
				Vec3 * newVel = enemy->getKinematics()->getVel()->mul(0.5f);
				enemy->getKinematics()->setVel(newVel);
				currCoolDown = coolDown;
			}
		}
		delete enemies;
	}
	else {
		currCoolDown -= TIME_SYNC;
	}
}