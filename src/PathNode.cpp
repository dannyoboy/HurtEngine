#include "PathNode.h"


PathNode::PathNode(Scene * scene, Vec3 * pos, Vec3 * velToSet) : Entity(&string("Enemy")) {
	Transform * transform = new Transform(pos, new Vec3(0, 0, 0), new Vec3(1, 1, 1));;
	Collideable * collideable = new Collideable(transform, new Vec3(0, 0, 0), 1);
	this->attachTransform(transform);
	this->attachCollideable(collideable);
	scene->addEntity(this);

}

void PathNode::death() {
	delete this->getTransform();
	delete this->getCollideable();
	delete this->getMaterial();
}

void PathNode::onUpdate() {
	//TODO: what chris wrote on paper
}