#pragma once

#include "vec4.h"

class Mat4 {
public:
	Mat4(float * valsIn);
	Mat4 * add(Mat4 * mat);
	Mat4 * sub(Mat4 * mat);
	Mat4 * mul(Mat4 * mat);
	Mat4 * mul(float val);
	Vec4 * mul(Vec4 * vec);
	Mat4 * transpose();
	~Mat4();
private:
	float * vals;
};