#pragma once

#include "hurtEngine/hurtEngine.h"

class Tester : public Entity {
public:
	inline Tester() : Entity(&string("tester")) {}
	void onUpdate() override;
};