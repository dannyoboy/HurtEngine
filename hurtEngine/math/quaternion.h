#pragma once

class Quaternion {
public:
	float x, y, z, w;
	Quaternion(float xIn, float yIn, float zIn, float wIn);
	Quaternion * conjugated();
	Quaternion * mul(float vecX, float vecY, float vecZ);
	Quaternion * mul(Quaternion * quat);
};