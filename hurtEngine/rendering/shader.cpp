#include "shader.h"

Shader::Shader(string * vertexFile, string * fragmentFile) {
	ifstream vertexStream(vertexFile->c_str());
	string vertexSourceStr((istreambuf_iterator<char>(vertexStream)), istreambuf_iterator<char>());
	const char * vertexSource = vertexSourceStr.c_str();
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	int success;
	const int LOG_LEN = 1024;
	char log[LOG_LEN];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, LOG_LEN, NULL, log);
		cerr << "Error in vertex shader " << *vertexFile << ":\n" << log << endl;
		system("pause");
		exit(-1);
	}

	ifstream fragmentStream(fragmentFile->c_str());
	string fragmentSourceStr((istreambuf_iterator<char>(fragmentStream)), istreambuf_iterator<char>());
	const char * fragmentSource = fragmentSourceStr.c_str();
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, LOG_LEN, NULL, log);
		cerr << "Error in fragment shader " << *fragmentFile << ":\n" << log << endl;
		system("pause");
		exit(-1);
	}

	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, LOG_LEN, NULL, log);
		cerr << "Failed to link shader program:\n" << log << endl;
		system("pause");
		exit(-1);
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	program = shaderProgram;
}

void Shader::loadFloat(string * name, float val) {
	glUniform1f(glGetUniformLocation(program, name->c_str()), val);
}

void Shader::loadInt(string * name, int val) {
	glUniform1i(glGetUniformLocation(program, name->c_str()), val);
}

void Shader::loadBool(string * name, bool val) {
	glUniform1i(glGetUniformLocation(program, name->c_str()), val);
}

void Shader::loadVec2(string * name, Vec2 * vec) {
	glUniform2f(glGetUniformLocation(program, name->c_str()), vec->x, vec->y);
}

void Shader::loadVec3(string * name, Vec3 * vec) {
	glUniform3f(glGetUniformLocation(program, name->c_str()), vec->x, vec->y, vec->z);
}

void Shader::loadVec4(string * name, Vec4 * vec) {
	glUniform4f(glGetUniformLocation(program, name->c_str()), vec->x, vec->y, vec->z, vec->w);
}

void Shader::loadMat4(string * name, Mat4 * mat) {
	glUniformMatrix4fv(glGetUniformLocation(program, name->c_str()), 1, GL_TRUE, mat->getVals());
}

void Shader::use() {
	glUseProgram(program);
}

Shader::~Shader() {
	glDeleteProgram(program);
}