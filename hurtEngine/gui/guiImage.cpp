#include "guiImage.h"

GUIImage::GUIImage(string * file, Vec2 * positionIn, Vec2 * dimensionsIn) : position(positionIn), dimensions(dimensionsIn) {
	tex = new Texture(file);
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
	Transform * transform = new Transform(new Vec3(position->x, position->y, 0), new Vec3(0, 0, 0), new Vec3(dimensions->x, dimensions->y, 0));
	Mat4 * transformationMatrix = transform->transformationMatrix();

	guiImageShader->loadMat4(&string("transform"), transformationMatrix);
	tex->bindToUnit(0);
	glDrawElements(GL_TRIANGLES, HURT_QUAD->getIndexCount(), GL_UNSIGNED_INT, 0);

	delete transformationMatrix;
	delete transform;
}

GUIImage::~GUIImage() {
	delete tex;
	delete position;
	delete dimensions;
}