#include "Radio.h"

static string TAG("radio");

static constexpr float RADIO_COOLDOWN = 0;
static constexpr int RADIO_DAMAGE = 0;
static constexpr int RADIO_COST = 0;

Radio::Radio(float rangeIn, Entity * rangeVisualIn, Transform * transformIn, Material * material, Mesh * mesh, float camFactorIn, float towerYIn) :
	Tower(rangeIn, rangeVisualIn, transformIn, material, mesh, camFactorIn, towerYIn, RADIO_RADIUS, RADIO_OFFSET, &TAG) {
}