#include "guiImage.h"

GUIImage::GUIImage(string * file, Vec2 * positionIn, Vec2 * dimensionsIn) : position(positionIn), dimensions(dimensionsIn) {
	// TODO
}

Vec2 * GUIImage::getPosition() {
	return position;
}

void GUIImage::setPosition(Vec2 * positionIn) {
	delete position;
	position = positionIn;
}

Vec2 * GUIImage::getDimensions() {
	return dimensions;
}

void GUIImage::setDimensions(Vec2 * dimensionsIn) {
	delete dimensions;
	dimensions = dimensionsIn;
}

void GUIImage::loadAndRender(Shader * guiImageShader) {
	// TODO
}

GUIImage::~GUIImage() {
	// TODO: delete tex
	
	delete position;
	delete dimensions;
}