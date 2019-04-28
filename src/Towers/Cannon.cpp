#include "Cannon.h"

static constexpr float CANNON_COOLDOWN = 0;
static constexpr int CANNON_DAMAGE = 0;
static constexpr int CANNON_COST = 0;

Cannon::Cannon(float rangeIn, Entity * rangeVisualIn, Transform * transformIn, Material * material, Mesh * mesh, float camFactorIn, float towerYIn) :
	Tower(rangeIn, rangeVisualIn, transformIn, material, mesh, camFactorIn, towerYIn) {
	setTowerValues(CANNON_COOLDOWN, CANNON_DAMAGE, CANNON_COST);
}