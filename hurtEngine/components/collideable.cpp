#include "collideable.h"

Collideable::Collideable(Transform * transformIn, Vec3 * offsetIn, float radiusIn) : transform(transformIn), offset(offsetIn), radius(radiusIn) {
	color = new Vec3(1, 0, 0);
}

Vec3 * Collideable::collisionWith(Collideable * collideable) {
	Vec3 * sphere1Center = worldCenter();
	float sphere1Rad = radius;

	Vec3 * sphere2Center = collideable->worldCenter();
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

		if (!picked) {
			setColor(HURT_BSPHERE_COLLIDE);
		}
		if (!collideable->picked) {
			collideable->setColor(HURT_BSPHERE_COLLIDE);
		}
	}

	delete sphere1Center;
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

Vec3 * Collideable::worldCenter() {
	Vec3 * rotatedOffset = transform->applyRotationTo(offset);
	Vec3 * center = transform->getPos()->add(rotatedOffset);
	delete rotatedOffset;
	return center;
}

void Collideable::setColor(Vec3 * colorIn) {
	delete color;
	color = colorIn;
}

void Collideable::setPicked(float pickedIn) {
	picked = pickedIn;
}

float Collideable::getRadius() {
	return radius;
}

Collideable::~Collideable() {
	delete color;
	delete offset;
}