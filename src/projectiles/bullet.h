#pragma once

#include "hurtEngine/hurtEngine.h"
#include "projectileAssets.h"
#include "src/Enemy.h"

class Bullet : public Entity {
public:
	Bullet(Vec3 * pos, Vec3 * direction);
	void onUpdate() override;
	~Bullet();
};