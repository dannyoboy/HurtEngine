#include "mesh.h"

Mesh::Mesh(string * objFile) {
	// TODO
}

void Mesh::bind() {
	glBindVertexArray(vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexEbo);
}

unsigned int Mesh::getNumIndices() {
	return numIndices;
}

Mesh::~Mesh() {
	glDeleteBuffers(1, &indexEbo);
	glDeleteBuffers(1, &vertVbo);
	glDeleteBuffers(1, &texVbo);
	glDeleteBuffers(1, &normVbo);
	glDeleteVertexArrays(1, &vao);
}