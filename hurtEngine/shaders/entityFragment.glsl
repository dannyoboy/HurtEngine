#version 330 core

const int MAX_DIRECTIONAL_LIGHTS = 16;
const int MAX_POINT_LIGHTS = 16;

in vec2 texCoords;
in vec3 normal;
in vec3 toCam;

out vec4 outColor;

struct Material {
	vec3 color;
	sampler2D diffuseMap;
	bool useDiffuseMap;
	sampler2D lightMap;
	bool useLightMap;
	float ambient;
	float diffuse;
	float specular;
	int shininess;
};

struct Light {
	vec3 color;
	float intensity;
};

struct DirectionalLight {
	Light basic;
	vec3 direction;
};

struct Attenuation {
	float constant;
	float linear;
	float exponent;
};

struct PointLight {
	Light basic;
	Attenuation attenuation;
	vec3 position;
	float range;
};

uniform Material material;
uniform DirectionalLight directionalLights[MAX_DIRECTIONAL_LIGHTS];
uniform int numDirectionalLights;
uniform PointLight pointLights[MAX_POINT_LIGHTS];
uniform int numPointLights;

void main() {
	// TODO
}