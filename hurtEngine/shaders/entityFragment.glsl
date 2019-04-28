#version 330 core

const int MAX_DIRECTIONAL_LIGHTS = 16;
const int MAX_POINT_LIGHTS = 16;

in vec2 texCoords;
in vec3 normal;
in vec3 toCam;
in vec3 worldPos;

out vec4 outColor;

struct Material {
	vec3 color;
	sampler2D diffuseMap;
	int useDiffuseMap;
	sampler2D lightMap;
	int useLightMap;
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
	float exponent;
	float linear;
	float constant;
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
	vec3 baseColor;
	if(material.useDiffuseMap != 0) {
		vec4 texColor = texture(material.diffuseMap, texCoords);
		if(texColor.a < 1.0) {
			discard;
		} else {
			baseColor = texColor.rgb;
		}
	} else {
		baseColor = material.color;
	}

	float ambientFactor;
	float diffuseFactor;
	float specularFactor;
	if(material.useLightMap != 0) {
		vec4 lightValues = texture(material.lightMap, texCoords);
		ambientFactor = lightValues.r;
		diffuseFactor = lightValues.g;
		specularFactor = lightValues.b;
	} else {
		ambientFactor = material.ambient;
		diffuseFactor = material.diffuse;
		specularFactor = material.specular;
	}
	int shininessFactor = material.shininess;

	vec3 ambientColor = vec3(0.0);
	vec3 diffuseColor = vec3(0.0);
	vec3 specularColor = vec3(0.0);
	for(int i = 0; i < numDirectionalLights; i++) {
		DirectionalLight light = directionalLights[i];
		vec3 lightShade = light.basic.color * light.basic.intensity;

		ambientColor += ambientFactor * lightShade;

		float diffuseDot = max(dot(normal, -light.direction), 0.0);
		diffuseColor += diffuseFactor * diffuseDot * lightShade;

		vec3 reflection = reflect(light.direction, normal);
		float specularEffect = pow(max(dot(normalize(toCam), reflection), 0.0), shininessFactor);
		specularColor += specularFactor * specularEffect * lightShade;
	}
	for(int i = 0; i < numPointLights; i++) {
		PointLight light = pointLights[i];
		vec3 lightShade = light.basic.color * light.basic.intensity;

		vec3 direction = worldPos - light.position;
		float distance = length(direction);
		if(distance <= light.range) {
			vec3 directionNorm = normalize(direction);
			
			vec3 ambientAmt = ambientFactor * lightShade;
			
			float diffuseDot = max(dot(normal, -directionNorm), 0.0);
			vec3 diffuseAmt = diffuseFactor * diffuseDot * lightShade;

			vec3 reflection = reflect(directionNorm, normal);
			float specularEffect = pow(max(dot(normalize(toCam), reflection), 0.0), shininessFactor);
			vec3 specularAmt = specularFactor * specularEffect * lightShade;

			Attenuation attenuation = light.attenuation;
			float attenuationFactor = attenuation.exponent * distance * distance + attenuation.linear * distance + attenuation.constant + 0.001;

			ambientColor += ambientAmt / attenuationFactor;
			diffuseColor += diffuseAmt / attenuationFactor;
			specularColor += specularAmt / attenuationFactor;
		}
	}

	vec3 finalColor = baseColor * (ambientColor + diffuseColor) + specularColor;
	outColor = vec4(finalColor, 1.0);
}