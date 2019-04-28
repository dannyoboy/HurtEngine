#pragma once
#include "hurtEngine/hurtEngine.h"

constexpr float SELECTOR_SIZE = .15f;

class Selector : public Entity {
public:
	Selector(Vec2 *posIn, string *image_file, float cam_factor, float selector_y);
	void onUpdate() override;
	bool isSelected();
	~Selector();

private:
	bool selected = false;
	Vec2 *pos;
	Transform *transform;
	Material *material;
};