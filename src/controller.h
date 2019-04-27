#pragma once

#include "hurtEngine/hurtEngine.h"

constexpr float CAM_MOVE_SPEED = 10;
constexpr float CAM_TURN_SPEED = 70;

class Controller : public Entity {
public:
	inline Controller(string * tag) : Entity(tag) {}
	void onUpdate() override;
};