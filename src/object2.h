#pragma once

#include "hurtEngine/hurtEngine.h"

class Object2 : public Entity {
public:
	Object2(string * tag, Vec3 * colorIn);
	void onSceneLoad() override;
	void onUpdate() override;
	void onAdd() override;
	void onGameStart() override;
private:
	Vec3 * color;
};