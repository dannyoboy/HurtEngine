#pragma once

#include "hurtEngine/hurtEngine.h"

class Enemy : public Entity {
public:
	Enemy(Scene * scene);
	void death();
};

