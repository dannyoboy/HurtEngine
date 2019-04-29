#include "EndNode.h"
#include "Enemy.h"

static string TAG("EndNode");

EndNode::EndNode(Scene * scene, Vec3 * pos) : Entity(&TAG) {
	Transform * transform = new Transform(pos, new Vec3(0, 0, 0), new Vec3(1, 1, 1));;
	Collideable * collideable = new Collideable(transform, new Vec3(0, 0, 0), 1);
	this->attachTransform(transform);
	this->attachCollideable(collideable);
	scene->addEntity(this);
	theScene = scene;
}

void EndNode::onUpdate() {
	list<Entity *> * enemies = theScene->getEntities(&string("Enemy"));
	for (list<Entity *>::iterator iter = enemies->begin(); iter != enemies->end(); ++iter) {
		Enemy * enemy = (Enemy *)(*iter);
		Collideable * collideable = enemy->getCollideable();
		Vec3 * collision = this->getCollideable()->collisionWith(collideable);
		if (collision != nullptr) {
			theScene->removeEntity(enemy);
			healthMoney -= enemy->getDamage();
			delete collision;
		}
	}
}