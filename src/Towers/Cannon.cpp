#include "Cannon.h"

static string TAG("cannon");

static constexpr float CANNON_COOLDOWN = 1;
static constexpr int CANNON_DAMAGE = 25;
static constexpr int CANNON_COST = 0;

Cannon::Cannon(float rangeIn, Entity * rangeVisualIn, Transform * transformIn, Material * material, Mesh * mesh, float camFactorIn, float towerYIn) :
	Tower(rangeIn, rangeVisualIn, transformIn, material, mesh, camFactorIn, towerYIn, CANNON_RADIUS, CANNON_OFFSET, &TAG) {
}