#pragma once

#include <string>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "hurtEngine/math/vec2.h"
#include "hurtEngine/rendering/shader.h"
#include "hurtEngine/input/cursor.h"
#include "hurtEngine/input/buttons.h"
#include "hurtEngine/rendering/texture.h"
#include "hurtEngine/components/transform.h"
#include "hurtEngine/utils/meshes.h"

class GUIButton {
public:
	GUIButton(string * idIn, string * defaultFile, string * hoveredFile, string * heldFile, Vec2 * positionIn, Vec2 * dimensionsIn);
	void update();
	void loadAndRender(Shader * guiImageShader);
	bool isClicked();
	bool isHovered();
	bool isHeld();
	bool isReleased();
	string * getID();
	Vec2 * getPosition();
	void setPosition(Vec2 * positionIn);
	Vec2 * getDimensions();
	void setDimensions(Vec2 * dimensionsIn);
	~GUIButton();
private:
	Texture * defaultTex;
	Texture * hoveredTex;
	Texture * heldTex;
	string * id;
	Vec2 * position;
	Vec2 * dimensions;
	bool clicked = false;
	bool hovered = false;
	bool held = false;
	bool released = false;
	bool wasPressed = false;
};