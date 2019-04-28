#pragma once

#include "hurtEngine/hurtEngine.h"

class PathNode : public Entity {
public:
	PathNode(Scene * scene, Vec3 * pos, Vec3 * velToSet);
	void death();
	void onUpdate() override;
private:
	Vec3 * velChange;
};