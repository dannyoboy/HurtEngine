#include "guiButton.h"

GUIButton::GUIButton(string * idIn, string * defaultFile, string * hoveredFile, string * pressedFile, Vec2 * positionIn, Vec2 * dimensionsIn) : id(idIn), position(positionIn), dimensions(dimensionsIn) {
	// TODO
}

void GUIButton::update() {
	// TODO: update hovered and pressed
}

void GUIButton::loadAndRender(Shader * guiImageShader) {
	// TODO
}

bool GUIButton::isHovered() {
	return hovered;
}

bool GUIButton::isPressed() {
	return pressed;
}

string * GUIButton::getID() {
	return id;
}

Vec2 * GUIButton::getPosition() {
	return position;
}

void GUIButton::setPosition(Vec2 * positionIn) {
	delete position;
	position = positionIn;
}

Vec2 * GUIButton::getDimensions() {
	return dimensions;
}
void GUIButton::setDimensions(Vec2 * dimensionsIn) {
	delete dimensions;
	dimensions = dimensionsIn;
}

GUIButton::~GUIButton() {
	// TODO: textures

	delete id;
	delete position;
	delete dimensions;
}