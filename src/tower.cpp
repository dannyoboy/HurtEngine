#include "tower.h"
#include "enemy.h"

static string TAG("tower");
bool selectionMade = false;

Tower::Tower(float rangeIn, Entity * rangeVisualIn, Transform * transformIn, Material * material, Mesh * mesh, float camFactorIn, float towerYIn) :
	Entity(&TAG), range(rangeIn), rangeVisual(rangeVisualIn), transform(transformIn), camFactor(camFactorIn), towerY(towerYIn) {
	attachMesh(mesh);
	attachMaterial(material);
	attachTransform(transform);
	collide = new Collideable(transform, TOWER_OFFSET, TOWER_RADIUS);
	mouse = new MousePicker(collide, true);
	attachCollideable(collide);
	attachMousePicker(mouse);
	currCoolDown = 0.0f;
}

void Tower::onUpdate() {
	if (mouse->isSelected() && hurtButtonPressed(HURT_BUTTON_LEFT)) {
		lockRangeVisual();
	}
	if (currCoolDown == 0) {
		Scene * gameScene = Game::instance()->getScene(&string("main"));
		list<Entity *> * enemies = gameScene->getEntities(&string("Enemy"));
		for (list<Entity *>::iterator iter = enemies->begin(); iter != enemies->end(); ++iter) {
			Entity * enemy = *iter;
			Collideable * collideable = enemy->getCollideable();
			if ((this->getCollideable()->collisionWith(collideable)) != nullptr) {
				((Enemy *)enemy)->takeDamage(damage);
				currCoolDown = coolDown;
			}
		}
		delete enemies;
	}
	else {
		currCoolDown -= TIME_SYNC;
	}
}

void Tower::lockRangeVisual() {
	Vec3 *scale = new Vec3(range * camFactor, 1, range * camFactor);
	rangeVisual->getTransform()->setScale(scale);
	Vec3 *pos = new Vec3(transform->getPos()->x, towerY, transform->getPos()->z);
	rangeVisual->getTransform()->setPos(pos);
	rangeVisual->setActive(true);
	selectionMade = true;
}

float Tower::getRange() {
	return range;
}

Tower::~Tower() {
	delete transform;
	delete collide;
	delete mouse;
}

void Tower::setTowerValues(float cooldownVal, int damageVal, int costVal) {
	coolDown = cooldownVal;
	damage = damageVal;
	cost = costVal;
}