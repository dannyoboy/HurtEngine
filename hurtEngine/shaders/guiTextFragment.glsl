#version 330 core

const float TEXT_THRESHOLD = 0.05;

in vec2 texCoords;

out vec4 outColor;

uniform sampler2D image;
uniform vec3 color;

void main() {
	vec4 texColor = texture(image, texCoords);
	if(texColor.r < TEXT_THRESHOLD) {
		discard;
	}

	outColor = vec4(color, 1.0);
}