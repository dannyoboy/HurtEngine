#pragma once

#include "hurtEngine/hurtEngine.h"
#include "tester.h"

class Object1 : public Entity {
public:
	Object1(string * tag, Vec3 * colorIn);
	void onSceneLoad() override;
	void onUpdate() override;
	void onLateUpdate() override;
	void onAdd() override;
	void onGameStart() override;
	void onGameStop() override;
private:
	Vec3 * color;
};