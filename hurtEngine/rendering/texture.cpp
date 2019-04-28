#include "texture.h"

Texture::Texture(string * textureFile) {
	int width, height, numChannels;
	unsigned char * data = stbi_load(textureFile->c_str(), &width, &height, &numChannels, 0);

	if (!data) {
		cerr << "Failed to load texture " << *textureFile << endl;
		stbi_image_free(data);
		system("pause");
		exit(-1);
	}

	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(data);
}

void Texture::bindToUnit(unsigned int unit) {
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, id);
}

unsigned int Texture::getID() {
	return id;
}

Texture::~Texture() {
	glDeleteTextures(1, &id);
}