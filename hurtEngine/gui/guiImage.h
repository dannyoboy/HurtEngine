#pragma once

#include <string>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "hurtEngine/math/vec2.h"
#include "hurtEngine/rendering/shader.h"
#include "hurtEngine/rendering/texture.h"
#include "hurtEngine/utils/meshes.h"
#include "hurtEngine/components/transform.h"

class GUIImage {
public:
	GUIImage(string * file, Vec2 * positionIn, Vec2 * dimensionsIn);
	Vec2 * getPosition();
	void setPosition(Vec2 * positionIn);
	Vec2 * getDimensions();
	void setDimensions(Vec2 * dimensionsIn);
	void loadAndRender(Shader * guiImageShader);
	~GUIImage();
private:
	Texture * tex;
	Vec2 * position;
	Vec2 * dimensions;
};