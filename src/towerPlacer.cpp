#include "towerPlacer.h"

static string TAG("towerPlacer");

TowerPlacer::TowerPlacer(HUD * hudIn, Entity * turretIndicatorIn, Entity * cannonIndicatorIn, Entity * radioIndicatorIn, Entity * rangeVisualIn, float camFactorIn, float towerYIn, Scene * sceneIn) : Entity(&TAG),
	hud(hudIn), turretIndicator(turretIndicatorIn), cannonIndicator(cannonIndicatorIn), radioIndicator(radioIndicatorIn), rangeVisual(rangeVisualIn), camFactor(camFactorIn), towerY(towerYIn), scene(sceneIn) {
	turretIndicator->setActive(false);
	cannonIndicator->setActive(false);
	radioIndicator->setActive(false);
	rangeVisual->setActive(false);
}

void TowerPlacer::onLateUpdate() {
	// Release selection
	if (hurtKeyPressed(HURT_KEY_ESCAPE) && pickedIndicator != nullptr) {
		pickedIndicator->setActive(false);
		rangeVisual->setActive(false);
		pickedIndicator = nullptr;
	}

	// Tower placement on click
	if (hurtButtonPressed(HURT_BUTTON_LEFT) && pickedIndicator != nullptr) {
		Tower * tower = nullptr;
		if (pickedIndicator == turretIndicator) {
			Vec3 * p = turretIndicator->getTransform()->getPos();
			Vec3 * r = turretIndicator->getTransform()->getRot();
			Vec3 * s = turretIndicator->getTransform()->getScale();
			Vec3 * pos = new Vec3(p->x, p->y, p->z);
			Vec3 * rot = new Vec3(r->x, r->y, r->z);
			Vec3 * scale = new Vec3(s->x, s->y, s->z);
			tower = new Tower(TURRET_RANGE, rangeVisual, new Transform(pos, rot, scale), turretIndicator->getMaterial(), turretIndicator->getMesh(), camFactor, towerY, TURRET_RADIUS, TURRET_OFFSET);
		}
		else if (pickedIndicator == cannonIndicator) {
			Vec3 * p = cannonIndicator->getTransform()->getPos();
			Vec3 * r = cannonIndicator->getTransform()->getRot();
			Vec3 * s = cannonIndicator->getTransform()->getScale();
			Vec3 * pos = new Vec3(p->x, p->y, p->z);
			Vec3 * rot = new Vec3(r->x, r->y, r->z);
			Vec3 * scale = new Vec3(s->x, s->y, s->z);
			tower = new Tower(CANNON_RANGE, rangeVisual, new Transform(pos, rot, scale), cannonIndicator->getMaterial(), cannonIndicator->getMesh(), camFactor, towerY, CANNON_RADIUS, CANNON_OFFSET);
		}
		else if (pickedIndicator == radioIndicator) {
			Vec3 * p = radioIndicator->getTransform()->getPos();
			Vec3 * r = radioIndicator->getTransform()->getRot();
			Vec3 * s = radioIndicator->getTransform()->getScale();
			Vec3 * pos = new Vec3(p->x, p->y, p->z);
			Vec3 * rot = new Vec3(r->x, r->y, r->z);
			Vec3 * scale = new Vec3(s->x, s->y, s->z);
			tower = new Tower(RADIO_RANGE, rangeVisual, new Transform(pos, rot, scale), radioIndicator->getMaterial(), radioIndicator->getMesh(), camFactor, towerY, RADIO_RADIUS, RADIO_OFFSET);
		}
		scene->addEntity(tower);

		pickedIndicator->setActive(false);
		rangeVisual->setActive(false);
		pickedIndicator = nullptr;
	}

	// Check if towers selected
	if (hud->getTurretSelected()) {
		turretIndicator->setActive(true);
		rangeVisual->setActive(true);
		rangeVisual->getTransform()->setScale(new Vec3(TURRET_RANGE * camFactor, 1, TURRET_RANGE * camFactor));
		pickedIndicator = turretIndicator;
	}
	else if (hud->getCannonSelected()) {
		cannonIndicator->setActive(true);
		rangeVisual->setActive(true);
		rangeVisual->getTransform()->setScale(new Vec3(CANNON_RANGE * camFactor, 1, CANNON_RANGE * camFactor));
		pickedIndicator = cannonIndicator;
	}
	else if (hud->getRadioSelected()) {
		radioIndicator->setActive(true);
		rangeVisual->setActive(true);
		rangeVisual->getTransform()->setScale(new Vec3(RADIO_RANGE * camFactor, 1, RADIO_RANGE * camFactor));
		pickedIndicator = radioIndicator;
	}
	else if (hurtButtonPressed(HURT_BUTTON_LEFT) && !selectionMade) {
		rangeVisual->setActive(false);
	}
	selectionMade = false;

	// Lock selected tower to mouse location
	if (pickedIndicator != nullptr) {
		Vec2 * cur = hurtGetCursorPos();
		rangeVisual->getTransform()->setPos(new Vec3(cur->x * camFactor, towerY, cur->y * camFactor));
		pickedIndicator->getTransform()->setPos(new Vec3(cur->x * camFactor, towerY + 0.001f, cur->y * camFactor));
	}
}

TowerPlacer::~TowerPlacer() {
	delete turretIndicator->getTransform();
	delete turretIndicator->getMesh();
	delete turretIndicator->getMaterial();

	delete cannonIndicator->getTransform();
	delete cannonIndicator->getMesh();
	delete cannonIndicator->getMaterial();

	delete radioIndicator->getTransform();
	delete radioIndicator->getMesh();
	delete radioIndicator->getMaterial();

	delete rangeVisual->getTransform();
	delete rangeVisual->getMesh();
	delete rangeVisual->getMaterial();
}