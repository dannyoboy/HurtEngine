#include "guiQuad.h"

GUIQuad::GUIQuad(Vec2 * texCoordsLow, Vec2 * texCoordsHigh) {
	float texCoords[] = {
		texCoordsLow->x, texCoordsLow->y,
		texCoordsLow->x, texCoordsHigh->y,
		texCoordsHigh->x, texCoordsHigh->y,
		texCoordsHigh->x, texCoordsLow->y
	};

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vertVbo);
	glBindBuffer(GL_ARRAY_BUFFER, vertVbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(HURT_QUAD_VERTICES), HURT_QUAD_VERTICES, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &texVbo);
	glBindBuffer(GL_ARRAY_BUFFER, texVbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(1);

	glGenBuffers(1, &indexEbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexEbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(HURT_QUAD_INDICES), HURT_QUAD_INDICES, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void GUIQuad::bind() {
	glBindVertexArray(vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexEbo);
}

unsigned int GUIQuad::getIndexCount() {
	return indexCount;
}

GUIQuad::~GUIQuad() {
	glDeleteBuffers(1, &indexEbo);
	glDeleteBuffers(1, &vertVbo);
	glDeleteBuffers(1, &texVbo);
	glDeleteVertexArrays(1, &vao);
}