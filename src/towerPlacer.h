#pragma once

#include "hurtEngine/hurtEngine.h"
#include "hud.h"
#include "ranges.h"
#include "tower.h"
#include "Towers/Turret.h"
#include "Towers/Cannon.h"
#include "Towers/Radio.h"

class TowerPlacer : public Entity {
public:
	TowerPlacer(HUD * hudIn, Entity * turretIndicatorIn, Entity * cannonIndicatorIn, Entity * radioIndicatorIn, Entity * rangeVisualIn, float camFactorIn, float towerYIn, Scene * sceneIn);
	void onLateUpdate() override;
	~TowerPlacer();
private:
	HUD * hud;
	Entity * turretIndicator;
	Entity * cannonIndicator;
	Entity * radioIndicator;
	Entity * rangeVisual;
	float camFactor;
	float towerY;
	Entity * pickedIndicator = nullptr;
	Scene * scene;
};