#include "meshes.h"

Mesh * HURT_CUBE = nullptr;
Mesh * HURT_PLANE = nullptr;
Mesh * HURT_SPHERE = nullptr;

void hurt::hurtMeshesInit() {
	HURT_CUBE = new Mesh(&string("hurtEngine/assets/cube.obj"));
	HURT_PLANE = new Mesh(&string("hurtEngine/assets/plane.obj"));
	HURT_SPHERE = new Mesh(&string("hurtEngine/assets/sphere.obj"));
}

void hurt::hurtMeshesDestroy() {
	delete HURT_CUBE;
	delete HURT_PLANE;
	delete HURT_SPHERE;
}