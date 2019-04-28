#include "Turret.h"

static constexpr float TURRET_COOLDOWN = 0;
static constexpr int TURRET_DAMAGE = 0;
static constexpr int TURRET_COST = 0;

Turret::Turret(float rangeIn, Entity * rangeVisualIn, Transform * transformIn, Material * material, Mesh * mesh, float camFactorIn, float towerYIn) :
	Tower(rangeIn, rangeVisualIn, transformIn, material, mesh, camFactorIn, towerYIn, TURRET_RADIUS, TURRET_OFFSET) {
	setTowerValues(TURRET_COOLDOWN, TURRET_DAMAGE, TURRET_COST);
}