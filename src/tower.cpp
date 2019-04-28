#include "tower.h"

static string TAG("tower");
bool selectionMade = false;

Tower::Tower(float rangeIn, Entity * rangeVisualIn, Transform * transformIn, Material * material, Mesh * mesh, float camFactorIn, float towerYIn, float towerRadius, Vec3 * towerOffset) :
	Entity(&TAG), range(rangeIn), rangeVisual(rangeVisualIn), transform(transformIn), camFactor(camFactorIn), towerY(towerYIn) {
	attachMesh(mesh);
	attachMaterial(material);
	attachTransform(transform);
	collide = new Collideable(transform, towerOffset, towerRadius);
	mouse = new MousePicker(collide, true);
	attachCollideable(collide);
	attachMousePicker(mouse);
}

void Tower::onUpdate() {
	if (mouse->isSelected() && hurtButtonPressed(HURT_BUTTON_LEFT)) {
		lockRangeVisual();
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