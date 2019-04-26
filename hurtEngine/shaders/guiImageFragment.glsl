#version 330 core

in vec2 texCoords;

out vec4 outColor;

uniform sampler2D image;

void main() {
	vec4 texColor = texture(image, texCoords);
	if(texColor.a == 0.0) {
		discard;
	}

	outColor = texColor;
}