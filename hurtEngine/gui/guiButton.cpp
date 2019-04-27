#include "guiButton.h"

GUIButton::GUIButton(string * idIn, string * defaultFile, string * hoveredFile, string * heldFile, Vec2 * texCoordsLow, Vec2 * texCoordsHigh, Vec2 * positionIn, Vec2 * dimensionsIn) : id(idIn), position(positionIn), dimensions(dimensionsIn) {
	mesh = new GUIQuad(texCoordsLow, texCoordsHigh);
	defaultTex = new Texture(defaultFile);
	hoveredTex = new Texture(hoveredFile);
	heldTex = new Texture(heldFile);
}

void GUIButton::update() {
	float lowX = position->x - dimensions->x / 2;
	float highX = position->x + dimensions->x / 2;
	float lowY = position->y - dimensions->y / 2;
	float highY = position->y + dimensions->y / 2;

	Vec2 * cur = hurtGetCursorPos();
	bool xInBounds = cur->x >= lowX && cur->x <= highX;
	bool yInBounds = cur->y >= lowY && cur->y <= highY;
	bool cursorOver = xInBounds && yInBounds;

	clicked = cursorOver && hurtButtonPressed(HURT_BUTTON_LEFT);
	if (clicked) {
		wasPressed = true;
	}

	released = wasPressed && hurtButtonReleased(HURT_BUTTON_LEFT);
	if (released) {
		wasPressed = false;
	}

	hovered = cursorOver;
	held = wasPressed;
}

void GUIButton::loadAndRender(Shader * guiImageShader) {
	Transform * transform = new Transform(new Vec3(position->x, position->y, 0), new Vec3(0, 0, 0), new Vec3(dimensions->x, dimensions->y, 0));
	Mat4 * transformationMatrix = transform->transformationMatrix();
	guiImageShader->loadMat4(&string("transform"), transformationMatrix);

	mesh->bind();
	if (held) {
		heldTex->bindToUnit(0);
	}
	else if (hovered) {
		hoveredTex->bindToUnit(0);
	}
	else {
		defaultTex->bindToUnit(0);
	}

	glDrawElements(GL_TRIANGLES, mesh->getIndexCount(), GL_UNSIGNED_INT, 0);

	delete transformationMatrix;
	delete transform;
}

bool GUIButton::isClicked() {
	return clicked;
}

bool GUIButton::isHovered() {
	return hovered;
}

bool GUIButton::isHeld() {
	return held;
}

bool GUIButton::isReleased() {
	return released;
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
	delete mesh;
	delete defaultTex;
	delete hoveredTex;
	delete heldTex;
	delete id;
	delete position;
	delete dimensions;
}