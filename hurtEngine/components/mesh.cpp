#include "mesh.h"

Mesh::Mesh(string * objFile) {
	list<Vec3> positionsList;
	list<Vec2> texCoordsList;
	list<Vec3> normalsList;
	list<unsigned int> indicesList;
	
	ifstream file(*objFile);
	string line;
	while (getline(file, line)) {
		if (line.find("vt") == 0) {
			strtok(const_cast<char *>(line.c_str()), " ");
			float texCoordU = (float)atof(strtok(NULL, " "));
			float texCoordV = (float)atof(strtok(NULL, " "));
			texCoordsList.push_back(Vec2(texCoordU, texCoordV));
		}
		else if (line.find("vn") == 0) {
			strtok(const_cast<char *>(line.c_str()), " ");
			float normalX = (float)atof(strtok(NULL, " "));
			float normalY = (float)atof(strtok(NULL, " "));
			float normalZ = (float)atof(strtok(NULL, " "));
			normalsList.push_back(Vec3(normalX, normalY, normalZ));
		}
		else if (line.find("v") == 0) {
			strtok(const_cast<char *>(line.c_str()), " ");
			float posX = (float)atof(strtok(NULL, " "));
			float posY = (float)atof(strtok(NULL, " "));
			float posZ = (float)atof(strtok(NULL, " "));
			positionsList.push_back(Vec3(posX, posY, posZ));
		}
		else if (line.find("f") == 0) {
			strtok(const_cast<char *>(line.c_str()), " ");
			char * value = strtok(NULL, " /");
			while (value) {
				indicesList.push_back((unsigned int)atof(value) - 1);
				value = strtok(NULL, " /");
			}
		}
	}

	if (texCoordsList.size() != 0 && texCoordsList.size() != positionsList.size()) {
		cerr << "Invalid number of texture coordinates in " << *objFile << endl;
		exit(-1);
	}
	if (normalsList.size() != positionsList.size()) {
		cerr << "Invalid number of normal vectors in " << *objFile << endl;
		exit(-1);
	}

	unsigned int numPositions = positionsList.size() * 3;
	unsigned int numTexCoords = texCoordsList.size() * 2;
	unsigned int numNormals = normalsList.size() * 3;
	unsigned int numIndices = indicesList.size();

	float * positions = new float[numPositions];
	float * texCoords = new float[numTexCoords];
	float * normals = new float[numNormals];
	unsigned int * indices = new unsigned int[numIndices];

	int i = 0;
	for (list<Vec3>::iterator iter = positionsList.begin(); iter != positionsList.end(); ++iter) {
		Vec3 pos = *iter;
		positions[i * 3] = pos.x;
		positions[i * 3 + 1] = pos.y;
		positions[i * 3 + 2] = pos.z;
		i++;
	}
	i = 0;
	for (list<Vec2>::iterator iter = texCoordsList.begin(); iter != texCoordsList.end(); ++iter) {
		Vec2 texCoord = *iter;
		texCoords[i * 2] = texCoord.x;
		texCoords[i * 2 + 1] = texCoord.y;
		i++;
	}
	i = 0;
	for (list<Vec3>::iterator iter = normalsList.begin(); iter != normalsList.end(); ++iter) {
		Vec3 normal = *iter;
		normals[i * 3] = normal.x;
		normals[i * 3 + 1] = normal.y;
		normals[i * 3 + 2] = normal.z;
		i++;
	}
	i = 0;
	for (list<unsigned int>::iterator iter = indicesList.begin(); iter != indicesList.end(); ++iter) {
		unsigned int index = *iter;
		indices[i] = index;
		i++;
	}

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	glGenBuffers(1, &vertVbo);
	glBindBuffer(GL_ARRAY_BUFFER, vertVbo);
	glBufferData(GL_ARRAY_BUFFER, numPositions * sizeof(float), positions, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &texVbo);
	glBindBuffer(GL_ARRAY_BUFFER, texVbo);
	glBufferData(GL_ARRAY_BUFFER, numTexCoords * sizeof(float), texCoords, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(1);

	glGenBuffers(1, &normVbo);
	glBindBuffer(GL_ARRAY_BUFFER, normVbo);
	glBufferData(GL_ARRAY_BUFFER, numNormals * sizeof(float), normals, GL_STATIC_DRAW);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(2);

	glGenBuffers(1, &indexEbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexEbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	delete[] positions;
	delete[] texCoords;
	delete[] normals;
	delete[] indices;

	this->numIndices = numIndices;
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