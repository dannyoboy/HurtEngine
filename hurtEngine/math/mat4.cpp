#include "mat4.h"

Mat4::Mat4(float * valsIn) : vals(valsIn) {}

float Mat4::getVal(int row, int col) {
	return vals[row * 4 + col];
}

float * Mat4::getVals() {
	return vals;
}

Mat4 * Mat4::add(Mat4 * mat) {
	float * sum = new float[16];
	
	for (int i = 0; i < 16; i++) {
		sum[i] = this->vals[i] + mat->vals[i];
	}

	return new Mat4(sum);
}

Mat4 * Mat4::sub(Mat4 * mat) {
	float * diff = new float[16];

	for (int i = 0; i < 16; i++) {
		diff[i] = this->vals[i] - mat->vals[i];
	}

	return new Mat4(diff);
}

Mat4 * Mat4::mul(Mat4 * mat) {
	float * product = new float[16];

	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			product[r * 4 + c] =	this->vals[r * 4] * mat->vals[c] +
									this->vals[r * 4 + 1] * mat->vals[4 + c] +
									this->vals[r * 4 + 2] * mat->vals[8 + c] +
									this->vals[r * 4 + 3] * mat->vals[12 + c];
		}
	}

	return new Mat4(product);
}

Mat4 * Mat4::mul(float val) {
	float * product = new float[16];

	for (int i = 0; i < 16; i++) {
		product[i] = this->vals[i] * val;
	}

	return new Mat4(product);
}

Vec4 * Mat4::mul(Vec4 * vec) {
	float pX = vals[0] * vec->x + vals[1] * vec->y + vals[2] * vec->z + vals[3] * vec->w;
	float pY = vals[4] * vec->x + vals[5] * vec->y + vals[6] * vec->z + vals[7] * vec->w;
	float pZ = vals[8] * vec->x + vals[9] * vec->y + vals[10] * vec->z + vals[11] * vec->w;
	float pW = vals[12] * vec->x + vals[13] * vec->y + vals[14] * vec->z + vals[15] * vec->w;

	return new Vec4(pX, pY, pZ, pW);
}

Mat4 * Mat4::transpose() {
	float * trans = new float[16];

	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			trans[r * 4 + c] = this->vals[r * 4 + c];
		}
	}

	return new Mat4(trans);
}

Mat4::~Mat4() {
	delete[] vals;
}