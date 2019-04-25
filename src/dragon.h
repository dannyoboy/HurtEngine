#pragma once

#include "hurtEngine/hurtEngine.h"

class Dragon : public Entity {
public:
	inline Dragon(string * tag) : Entity(tag) {}
	void onUpdate() override;
};