#include "selector.h"

static string TAG("selector");

Selector::Selector(Vec2 *posIn, string *image_file, float cam_factor, float selector_y) : Entity(&TAG), pos(posIn) {
	attachMesh(HURT_PLANE);
	material = new Material(image_file, 1, 0, 0, 1);
	attachMaterial(material);
	transform = new Transform(new Vec3(pos->x * cam_factor, selector_y, pos->y * cam_factor), new Vec3(0, 180, 180), new Vec3(SELECTOR_SIZE * cam_factor, 1, SELECTOR_SIZE * cam_factor));
	attachTransform(transform);
}

void Selector::onUpdate() {
	bool isClicked = hurtButtonPressed(HURT_BUTTON_LEFT);
	Vec2 *cursor_pos = hurtGetCursorPos();
	float low_x = pos->x - .5f * SELECTOR_SIZE;
	float high_x = pos->x + .5f * SELECTOR_SIZE;
	float low_y = pos->y - .5f * SELECTOR_SIZE;
	float high_y = pos->y + .5f * SELECTOR_SIZE;
	bool isHovered = cursor_pos->x > low_x && cursor_pos->x < high_x && cursor_pos->y > low_y && cursor_pos->y < high_y;

	selected = isClicked && isHovered;
}

bool Selector::isSelected() {
	return selected;
}

Selector::~Selector() {
	delete pos;
	delete transform;
	delete material;
}