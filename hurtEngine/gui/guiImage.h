#pragma once

#include <string>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "hurtEngine/math/vec2.h"
#include "hurtEngine/rendering/shader.h"
#include "hurtEngine/rendering/texture.h"
#include "hurtEngine/utils/meshes.h"
#include "hurtEngine/components/transform.h"
#include "hurtEngine/gui/guiQuad.h"

class GUIImage {
public:
	GUIImage(string * file, Vec2 * texCoordsLow, Vec2 * texCoordsHigh, Vec2 * positionIn, Vec2 * dimensionsIn);
	Vec2 * getPosition();
	void setPosition(Vec2 * positionIn);
	Vec2 * getDimensions();
	void setDimensions(Vec2 * dimensionsIn);
	void loadAndRender(Shader * guiImageShader);
	~GUIImage();
private:
	GUIQuad * mesh;
	Texture * tex;
	Vec2 * position;
	Vec2 * dimensions;
};