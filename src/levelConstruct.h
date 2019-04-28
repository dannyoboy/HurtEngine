#pragma once

#include "hurtEngine/hurtEngine.h"
#include "hud.h"
#include "towerPlacer.h"
#include "tower.h"

constexpr int HUD_DISTANCE = 25;
constexpr float TOWER_Y = 1;
constexpr float TOWER_SIZE = 2 * TOWER_RADIUS;

void constructLevel(Scene * scene, float fov, float cam_distance);