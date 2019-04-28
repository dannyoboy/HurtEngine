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
		Entity * enemy = *iter;
		Collideable * collideable = enemy->getCollideable();
		Vec3 * collision;
		if ((collision = this->getCollideable()->collisionWith(collideable)) != nullptr) {
			theScene->removeEntity(enemy);
			//TODO: do damage to health because enemy reached the end
		}
		delete collision;
	}
	delete enemies;
}