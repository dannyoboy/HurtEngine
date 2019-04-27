#pragma once

#include "hurtEngine/components/mesh.h"

extern Mesh * HURT_CUBE;
extern Mesh * HURT_PLANE;
extern Mesh * HURT_SPHERE;
extern Mesh * HURT_QUAD;

namespace hurt {
	void hurtMeshesInit();
	void hurtMeshesDestroy();
}