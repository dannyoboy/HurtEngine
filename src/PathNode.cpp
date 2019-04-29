#include "PathNode.h"

Scene * gameScene;
static string TAG("PathNode");

PathNode::PathNode(Scene * scene, Vec3 * pos, Vec3 * velToSet) : Entity(&TAG) {
	Transform * transform = new Transform(pos, new Vec3(0, 0, 0), new Vec3(1, 1, 1));;
	Collideable * collideable = new Collideable(transform, new Vec3(0, 0, 0), 1);
	this->attachTransform(transform);
	this->attachCollideable(collideable);
	scene->addEntity(this);
	gameScene = scene;
	velChange = velToSet;
}

void PathNode::onUpdate() {
	list<Entity *> * enemies = gameScene->getEntities(&string("Enemy"));
	for (list<Entity *>::iterator iter = enemies->begin(); iter != enemies->end(); ++iter) {
		Entity * enemy = *iter;
		Collideable * collideable = enemy->getCollideable();
		Vec3 * collision = this->getCollideable()->collisionWith(collideable);
		if (collision != nullptr) {
			Vec3 * newPos = enemy->getTransform()->getPos()->sub(collision);
			enemy->getTransform()->setPos(newPos); //push enemy back to get out of collision loop
			enemy->getKinematics()->setVel(new Vec3(velChange->x, velChange->y, velChange->z));
			delete collision;
		}
	}
}