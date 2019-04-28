#pragma once

#include "hurtEngine/hurtEngine.h"

class EndNode : public Entity {
public:
	EndNode(Scene * scene, Vec3 * pos);
	void death();
	void onUpdate() override;
private:
	Scene * theScene;
};