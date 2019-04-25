#include "skybox.h"

static const float SKYBOX_VERTICES[] = {
	-0.5f, -0.5f, -0.5f, // V0
	-0.5f,  0.5f, -0.5f, // V1
	 0.5f,  0.5f, -0.5f, // V2
	 0.5f, -0.5f, -0.5f, // V3
	 0.5f, -0.5f,  0.5f, // V4
	 0.5f,  0.5f,  0.5f, // V5
	-0.5f,  0.5f,  0.5f, // V6
	-0.5f, -0.5f,  0.5f, // V7
	-0.5f, -0.5f,  0.5f, // V8
	-0.5f,  0.5f,  0.5f, // V9
	-0.5f,  0.5f, -0.5f, // V10
	-0.5f, -0.5f, -0.5f, // V11
	 0.5f, -0.5f, -0.5f, // V12
	 0.5f,  0.5f, -0.5f, // V13
	 0.5f,  0.5f,  0.5f, // V14
	 0.5f, -0.5f,  0.5f, // V15
	-0.5f,  0.5f, -0.5f, // V16
	-0.5f,  0.5f,  0.5f, // V17
	 0.5f,  0.5f,  0.5f, // V18
	 0.5f,  0.5f, -0.5f, // V19
	-0.5f, -0.5f,  0.5f, // V20
	-0.5f, -0.5f, -0.5f, // V21
	 0.5f, -0.5f, -0.5f, // V22
	 0.5f, -0.5f,  0.5f  // V23
};

static const unsigned int SKYBOX_INDICES[] = {
	0,  1,  2,  2,  3,  0,  // Front
	4,  5,  6,  6,  7,  4,  // Back
	8,  9,  10, 10, 11, 8,  // Left
	12, 13, 14, 14, 15, 12, // Right
	16, 17, 18, 18, 19, 16, // Top
	20, 21, 22, 22, 23, 20  // Down
};

Skybox::Skybox(string textures[], Vec3 * rotIn) : rot(rotIn) {
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vertVbo);
	glBindBuffer(GL_ARRAY_BUFFER, vertVbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(SKYBOX_VERTICES), SKYBOX_VERTICES, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(SKYBOX_INDICES), SKYBOX_INDICES, GL_STATIC_DRAW);

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_CUBE_MAP, tex);

	stbi_set_flip_vertically_on_load(false);
	int width, height, numChannels;
	for (int i = 0; i < 6; i++) {
		unsigned char * data = stbi_load(textures[i].c_str(), &width, &height, &numChannels, 0);

		if (!data) {
			cerr << "Failed to load skybox texture " << textures[i] << endl;
			stbi_image_free(data);
			system("pause");
			exit(-1);
		}

		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		stbi_image_free(data);
	}

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(true);
}

void Skybox::loadAndRender(Shader * skyboxShader) {
	Vec3 * rotCopy = new Vec3(rot->x, rot->y, rot->z);
	Transform * skyboxTransform = new Transform(new Vec3(0, 0, 0), rotCopy, new Vec3(1, 1, 1));
	Mat4 * skyboxTransformationMatrix = skyboxTransform->transformationMatrix();
	skyboxShader->loadMat4(&string("transform"), skyboxTransformationMatrix);
	delete skyboxTransform;
	delete skyboxTransformationMatrix;

	glBindVertexArray(vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, tex);

	glDepthFunc(GL_LEQUAL);
	glDrawElements(GL_TRIANGLES, sizeof(SKYBOX_INDICES) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);
	glDepthFunc(GL_LESS);
}

Vec3 * Skybox::getRotation() {
	return rot;
}

void Skybox::setRotation(Vec3 * rotIn) {
	delete rot;
	rot = rotIn;
}

Skybox::~Skybox() {
	glDeleteTextures(1, &tex);

	glDeleteBuffers(1, &ebo);
	glDeleteBuffers(1, &vertVbo);
	glDeleteVertexArrays(1, &vao);

	delete rot;
}