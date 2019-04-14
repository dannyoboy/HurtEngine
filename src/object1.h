#pragma once

#include "hurtEngine/hurtEngine.h"

class Object1 : public Entity {
public:
	Object1(string * tag, Vec3 * colorIn);
	void onSceneLoad() override;
	void onUpdate() override;
	void onAdd() override;
private:
	Vec3 * color;
};