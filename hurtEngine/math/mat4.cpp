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

// Source: https://stackoverflow.com/questions/1148309/inverting-a-4x4-matrix

Mat4 * Mat4::inverse() {
	float * iVals = new float[16];

	iVals[0] =	vals[5] * vals[10] * vals[15] -
				vals[5] * vals[11] * vals[14] -
				vals[9] * vals[6] * vals[15] +
				vals[9] * vals[7] * vals[14] +
				vals[13] * vals[6] * vals[11] -
				vals[13] * vals[7] * vals[10];

	iVals[4] =	-vals[4] * vals[10] * vals[15] +
				vals[4] * vals[11] * vals[14] +
				vals[8] * vals[6] * vals[15] -
				vals[8] * vals[7] * vals[14] -
				vals[12] * vals[6] * vals[11] +
				vals[12] * vals[7] * vals[10];

	iVals[8] =	vals[4] * vals[9] * vals[15] -
				vals[4] * vals[11] * vals[13] -
				vals[8] * vals[5] * vals[15] +
				vals[8] * vals[7] * vals[13] +
				vals[12] * vals[5] * vals[11] -
				vals[12] * vals[7] * vals[9];

	iVals[12] = -vals[4] * vals[9] * vals[14] +
				vals[4] * vals[10] * vals[13] +
				vals[8] * vals[5] * vals[14] -
				vals[8] * vals[6] * vals[13] -
				vals[12] * vals[5] * vals[10] +
				vals[12] * vals[6] * vals[9];

	iVals[1] =	-vals[1] * vals[10] * vals[15] +
				vals[1] * vals[11] * vals[14] +
				vals[9] * vals[2] * vals[15] -
				vals[9] * vals[3] * vals[14] -
				vals[13] * vals[2] * vals[11] +
				vals[13] * vals[3] * vals[10];

	iVals[5] =	vals[0] * vals[10] * vals[15] -
				vals[0] * vals[11] * vals[14] -
				vals[8] * vals[2] * vals[15] +
				vals[8] * vals[3] * vals[14] +
				vals[12] * vals[2] * vals[11] -
				vals[12] * vals[3] * vals[10];

	iVals[9] =	-vals[0] * vals[9] * vals[15] +
				vals[0] * vals[11] * vals[13] +
				vals[8] * vals[1] * vals[15] -
				vals[8] * vals[3] * vals[13] -
				vals[12] * vals[1] * vals[11] +
				vals[12] * vals[3] * vals[9];

	iVals[13] = vals[0] * vals[9] * vals[14] -
				vals[0] * vals[10] * vals[13] -
				vals[8] * vals[1] * vals[14] +
				vals[8] * vals[2] * vals[13] +
				vals[12] * vals[1] * vals[10] -
				vals[12] * vals[2] * vals[9];

	iVals[2] =	vals[1] * vals[6] * vals[15] -
				vals[1] * vals[7] * vals[14] -
				vals[5] * vals[2] * vals[15] +
				vals[5] * vals[3] * vals[14] +
				vals[13] * vals[2] * vals[7] -
				vals[13] * vals[3] * vals[6];

	iVals[6] =	-vals[0] * vals[6] * vals[15] +
				vals[0] * vals[7] * vals[14] +
				vals[4] * vals[2] * vals[15] -
				vals[4] * vals[3] * vals[14] -
				vals[12] * vals[2] * vals[7] +
				vals[12] * vals[3] * vals[6];

	iVals[10] = vals[0] * vals[5] * vals[15] -
				vals[0] * vals[7] * vals[13] -
				vals[4] * vals[1] * vals[15] +
				vals[4] * vals[3] * vals[13] +
				vals[12] * vals[1] * vals[7] -
				vals[12] * vals[3] * vals[5];

	iVals[14] = -vals[0] * vals[5] * vals[14] +
				vals[0] * vals[6] * vals[13] +
				vals[4] * vals[1] * vals[14] -
				vals[4] * vals[2] * vals[13] -
				vals[12] * vals[1] * vals[6] +
				vals[12] * vals[2] * vals[5];

	iVals[3] =	-vals[1] * vals[6] * vals[11] +
				vals[1] * vals[7] * vals[10] +
				vals[5] * vals[2] * vals[11] -
				vals[5] * vals[3] * vals[10] -
				vals[9] * vals[2] * vals[7] +
				vals[9] * vals[3] * vals[6];

	iVals[7] =	vals[0] * vals[6] * vals[11] -
				vals[0] * vals[7] * vals[10] -
				vals[4] * vals[2] * vals[11] +
				vals[4] * vals[3] * vals[10] +
				vals[8] * vals[2] * vals[7] -
				vals[8] * vals[3] * vals[6];

	iVals[11] = -vals[0] * vals[5] * vals[11] +
				vals[0] * vals[7] * vals[9] +
				vals[4] * vals[1] * vals[11] -
				vals[4] * vals[3] * vals[9] -
				vals[8] * vals[1] * vals[7] +
				vals[8] * vals[3] * vals[5];

	iVals[15] = vals[0] * vals[5] * vals[10] -
				vals[0] * vals[6] * vals[9] -
				vals[4] * vals[1] * vals[10] +
				vals[4] * vals[2] * vals[9] +
				vals[8] * vals[1] * vals[6] -
				vals[8] * vals[2] * vals[5];

	float determinant = vals[0] * iVals[0] + vals[1] * iVals[4] + vals[2] * iVals[8] + vals[3] * iVals[12];

	if (determinant == 0) {
		return nullptr;
	}

	for (int i = 0; i < 16; i++) {
		iVals[i] = iVals[i] / determinant;
	}

	return new Mat4(iVals);
}

Mat4::~Mat4() {
	delete[] vals;
}