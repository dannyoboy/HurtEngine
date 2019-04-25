#include "collideable.h"

Collideable::Collideable(Transform * transformIn, Vec3 * offsetIn, float radiusIn) : transform(transformIn), offset(offsetIn), radius(radiusIn) {
	color = new Vec3(1, 0, 0);
}

Vec3 * Collideable::collisionWith(Collideable * collideable) {
	Vec3 * rotatedOffset1 = transform->applyRotationTo(offset);
	Vec3 * sphere1Center = transform->getPos()->add(rotatedOffset1);
	float sphere1Rad = radius;

	Vec3 * rotatedOffset2 = collideable->transform->applyRotationTo(collideable->offset);
	Vec3 * sphere2Center = collideable->transform->getPos()->add(rotatedOffset2);
	float sphere2Rad = collideable->radius;

	Vec3 * centerDelta = sphere1Center->sub(sphere2Center);
	float distance = centerDelta->length();
	float radSum = sphere1Rad + sphere2Rad;

	Vec3 * intersection = nullptr;
	if (distance < radSum) {
		float collideAmount = radSum - distance;
		Vec3 * collideDir = centerDelta->normalized();
		intersection = collideDir->mul(collideAmount);
		delete collideDir;
		setColor(HURT_BSPHERE_COLLIDE);
		collideable->setColor(HURT_BSPHERE_COLLIDE);
	}

	delete rotatedOffset1;
	delete sphere1Center;
	delete rotatedOffset2;
	delete sphere2Center;
	delete centerDelta;

	return intersection;
}

void Collideable::load(Shader * bsphereShader) {
	Vec3 * pos = transform->getPos();
	Vec3 * spherePos = new Vec3(pos->x, pos->y, pos->z);
	Vec3 * rot = transform->getRot();
	Vec3 * sphereRot = new Vec3(rot->x, rot->y, rot->z);
	float sphereScale = 2 * radius;
	Transform * sphereTransform = new Transform(spherePos, sphereRot, new Vec3(sphereScale, sphereScale, sphereScale));
	Mat4 * sphereTransformationMatrix = sphereTransform->transformationMatrixWithOffset(offset);
	
	bsphereShader->loadMat4(&string("transform"), sphereTransformationMatrix);
	
	delete sphereTransform;
	delete sphereTransformationMatrix;

	bsphereShader->loadVec3(&string("color"), color);
}

void Collideable::setColor(Vec3 * colorIn) {
	delete color;
	color = colorIn;
}

Collideable::~Collideable() {
	delete color;
	delete offset;
}