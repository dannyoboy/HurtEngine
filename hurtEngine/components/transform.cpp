#include "transform.h"

Transform::Transform(Vec3 * posIn, Vec3 * rotIn, Vec3 * scaleIn) : pos(posIn), rot(rotIn), scale(scaleIn) {}

Mat4 * Transform::transformationMatrix() {
	float * translationVals = new float[16]{
		1, 0, 0, pos->x,
		0, 1, 0, pos->y,
		0, 0, 1, pos->z,
		0, 0, 0, 1
	};
	Mat4 * translation = new Mat4(translationVals);

	float radZ = hurtDegToRad(rot->z);
	float sinZ = (float)sin(radZ);
	float cosZ = (float)cos(radZ);
	float * rotationZVals = new float[16]{
		cosZ, -sinZ, 0, 0,
		sinZ,  cosZ, 0, 0,
		0,     0,    1, 0,
		0,     0,    0, 1
	};
	Mat4 * rotationZ = new Mat4(rotationZVals);

	float radY = hurtDegToRad(rot->y);
	float sinY = (float)sin(radY);
	float cosY = (float)cos(radY);
	float * rotationYVals = new float[16]{
		cosY,  0, sinY, 0,
		0,     1, 0,    0,
		-sinY, 0, cosY, 0,
		0,     0, 0,    1
	};
	Mat4 * rotationY = new Mat4(rotationYVals);

	float radX = hurtDegToRad(rot->x);
	float sinX = (float)sin(radX);
	float cosX = (float)cos(radX);
	float * rotationXVals = new float[16]{
		1, 0,    0,     0,
		0, cosX, -sinX, 0,
		0, sinX, cosX,  0,
		0, 0,    0,     1
	};
	Mat4 * rotationX = new Mat4(rotationXVals);

	float * scaleVals = new float[16]{
		scale->x,	0,			0,			0,
		0,			scale->y,	0,			0,
		0,			0,			scale->z,	0,
		0,			0,			0,			1
	};
	Mat4 * scale = new Mat4(scaleVals);

	Mat4 * temp1 = translation->mul(rotationZ);
	Mat4 * temp2 = temp1->mul(rotationY);
	Mat4 * temp3 = temp2->mul(rotationX);
	Mat4 * transformation = temp3->mul(scale);

	delete translation;
	delete rotationZ;
	delete rotationY;
	delete rotationX;
	delete scale;

	delete temp1;
	delete temp2;
	delete temp3;

	return transformation;
}

Mat4 * Transform::transformationMatrixWithOffset(Vec3 * offset) {
	float * translationVals = new float[16]{
		1, 0, 0, pos->x,
		0, 1, 0, pos->y,
		0, 0, 1, pos->z,
		0, 0, 0, 1
	};
	Mat4 * translation = new Mat4(translationVals);

	float radZ = hurtDegToRad(rot->z);
	float sinZ = (float)sin(radZ);
	float cosZ = (float)cos(radZ);
	float * rotationZVals = new float[16]{
		cosZ, -sinZ, 0, 0,
		sinZ,  cosZ, 0, 0,
		0,     0,    1, 0,
		0,     0,    0, 1
	};
	Mat4 * rotationZ = new Mat4(rotationZVals);

	float radY = hurtDegToRad(rot->y);
	float sinY = (float)sin(radY);
	float cosY = (float)cos(radY);
	float * rotationYVals = new float[16]{
		cosY,  0, sinY, 0,
		0,     1, 0,    0,
		-sinY, 0, cosY, 0,
		0,     0, 0,    1
	};
	Mat4 * rotationY = new Mat4(rotationYVals);

	float radX = hurtDegToRad(rot->x);
	float sinX = (float)sin(radX);
	float cosX = (float)cos(radX);
	float * rotationXVals = new float[16]{
		1, 0,    0,     0,
		0, cosX, -sinX, 0,
		0, sinX, cosX,  0,
		0, 0,    0,     1
	};
	Mat4 * rotationX = new Mat4(rotationXVals);

	float * scaleVals = new float[16]{
		scale->x,	0,			0,			0,
		0,			scale->y,	0,			0,
		0,			0,			scale->z,	0,
		0,			0,			0,			1
	};
	Mat4 * scale = new Mat4(scaleVals);

	float * offsetTranslationVals = new float[16]{
		1, 0, 0, offset->x,
		0, 1, 0, offset->y,
		0, 0, 1, offset->z,
		0, 0, 0, 1
	};
	Mat4 * offsetTranslation = new Mat4(offsetTranslationVals);

	Mat4 * temp1 = translation->mul(rotationZ);
	Mat4 * temp2 = temp1->mul(rotationY);
	Mat4 * temp3 = temp2->mul(rotationX);
	Mat4 * temp4 = temp3->mul(offsetTranslation);
	Mat4 * transformation = temp4->mul(scale);

	delete translation;
	delete rotationZ;
	delete rotationY;
	delete rotationX;
	delete scale;
	delete offsetTranslation;

	delete temp1;
	delete temp2;
	delete temp3;
	delete temp4;

	return transformation;
}

Vec3 * Transform::applyRotationTo(Vec3 * offset) {
	float radZ = hurtDegToRad(rot->z);
	float sinZ = (float)sin(radZ);
	float cosZ = (float)cos(radZ);
	float * rotationZVals = new float[16]{
		cosZ, -sinZ, 0, 0,
		sinZ,  cosZ, 0, 0,
		0,     0,    1, 0,
		0,     0,    0, 1
	};
	Mat4 * rotationZ = new Mat4(rotationZVals);

	float radY = hurtDegToRad(rot->y);
	float sinY = (float)sin(radY);
	float cosY = (float)cos(radY);
	float * rotationYVals = new float[16]{
		cosY,  0, sinY, 0,
		0,     1, 0,    0,
		-sinY, 0, cosY, 0,
		0,     0, 0,    1
	};
	Mat4 * rotationY = new Mat4(rotationYVals);

	float radX = hurtDegToRad(rot->x);
	float sinX = (float)sin(radX);
	float cosX = (float)cos(radX);
	float * rotationXVals = new float[16]{
		1, 0,    0,     0,
		0, cosX, -sinX, 0,
		0, sinX, cosX,  0,
		0, 0,    0,     1
	};
	Mat4 * rotationX = new Mat4(rotationXVals);

	Vec4 * swizzledPos = new Vec4(offset->x, offset->y, offset->z, 1);
	Mat4 * temp1 = rotationZ->mul(rotationY);
	Mat4 * temp2 = temp1->mul(rotationX);
	Vec4 * rotatedPos = temp2->mul(swizzledPos);
	Vec3 * result = new Vec3(rotatedPos->x, rotatedPos->y, rotatedPos->z);

	delete rotationZ;
	delete rotationY;
	delete rotationX;

	delete swizzledPos;
	delete temp1;
	delete temp2;
	delete rotatedPos;

	return result;
}

Vec3 * Transform::getPos() {
	return pos;
}

void Transform::setPos(Vec3 * posIn) {
	delete pos;
	pos = posIn;
}

Vec3 * Transform::getRot() {
	return rot;
}

void Transform::setRot(Vec3 * rotIn) {
	delete rot;
	rot = rotIn;
}

Vec3 * Transform::getScale() {
	return scale;
}

void Transform::setScale(Vec3 * scaleIn) {
	delete scale;
	scale = scaleIn;
}

Transform::~Transform() {
	delete pos;
	delete rot;
	delete scale;
}