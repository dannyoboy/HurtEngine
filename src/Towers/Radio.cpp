#include "Radio.h"

static constexpr float RADIO_COOLDOWN = 0;
static constexpr int RADIO_DAMAGE = 0;
static constexpr int RADIO_COST = 0;

Radio::Radio(float rangeIn, Entity * rangeVisualIn, Transform * transformIn, Material * material, Mesh * mesh, float camFactorIn, float towerYIn) :
	Tower(rangeIn, rangeVisualIn, transformIn, material, mesh, camFactorIn, towerYIn) {
	setTowerValues(RADIO_COOLDOWN, RADIO_DAMAGE, RADIO_COST);
}