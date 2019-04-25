#include "collideable.h"

Collideable::Collideable(Transform * transformIn, Vec3 * offsetIn, float radiusIn) : transform(transformIn), offset(offsetIn), radius(radiusIn) {
	color = new Vec3(1, 0, 0);
}

Vec3 * Collideable::collisionWith(Collideable * collideable) {
	Vec3 * sphere1Center = transform->getPos()->add(offset);
	float sphere1Rad = radius;

	Vec3 * sphere2Center = collideable->transform->getPos()->add(collideable->offset);
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
	}

	delete sphere1Center;
	delete sphere2Center;
	delete centerDelta;

	return intersection;
}

void Collideable::load(Shader * bsphereShader) {
	Vec3 * spherePos = transform->getPos()->add(offset);
	float sphereScale = 2 * radius;
	Transform * sphereTransform = new Transform(spherePos, new Vec3(0, 0, 0), new Vec3(sphereScale, sphereScale, sphereScale));
	Mat4 * sphereTransformationMatrix = sphereTransform->transformationMatrix();
	
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