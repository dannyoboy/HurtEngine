#pragma once

#include <string>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "hurtEngine/math/vec2.h"
#include "hurtEngine/rendering/shader.h"

class GUIButton {
public:
	GUIButton(string * idIn, string * defaultFile, string * hoveredFile, string * pressedFile, Vec2 * positionIn, Vec2 * dimensionsIn);
	void update();
	void loadAndRender(Shader * guiImageShader);
	bool isHovered();
	bool isPressed();
	string * getID();
	Vec2 * getPosition();
	void setPosition(Vec2 * positionIn);
	Vec2 * getDimensions();
	void setDimensions(Vec2 * dimensionsIn);
	~GUIButton();
private:
	// TODO: tex ids
	string * id;
	Vec2 * position;
	Vec2 * dimensions;
	bool hovered = false;
	bool pressed = false;
};