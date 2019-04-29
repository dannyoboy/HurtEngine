#pragma once

#include "hurtEngine/hurtEngine.h"
#include "projectileAssets.h"
#include "src/Enemy.h"

class Cannonball : public Entity {
public:
	Cannonball(Vec3 * pos, Vec3 * direction);
	void onUpdate() override;
	~Cannonball();
};