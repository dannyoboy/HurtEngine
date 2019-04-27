#include "meshes.h"

Mesh * HURT_CUBE = nullptr;
Mesh * HURT_PLANE = nullptr;
Mesh * HURT_SPHERE = nullptr;
Mesh * HURT_QUAD = nullptr;

void hurt::hurtMeshesInit() {
	HURT_CUBE = new Mesh(&string("hurtEngine/assets/cube.obj"));
	HURT_PLANE = new Mesh(&string("hurtEngine/assets/plane.obj"));
	HURT_SPHERE = new Mesh(&string("hurtEngine/assets/sphere.obj"));
	HURT_QUAD = new Mesh(&string("hurtEngine/assets/quad.obj"));
}

void hurt::hurtMeshesDestroy() {
	delete HURT_CUBE;
	delete HURT_PLANE;
	delete HURT_SPHERE;
	delete HURT_QUAD;
}