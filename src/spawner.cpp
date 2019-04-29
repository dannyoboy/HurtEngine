#include "spawner.h"

static string TAG("spawner");
static Mesh * enemyMesh = nullptr;
Material * enemyMaterial = nullptr;

Spawner::Spawner(Scene * sceneIn, float enemyYIn, float windowIn, Level1 * level1In) :
	Entity(&TAG), scene(sceneIn), enemyY(enemyYIn), window(windowIn), level1(level1In) {
	enemyMesh = new Mesh(&string("res/drone.obj"));
	enemyMaterial = new Material(&string("res/drone.png"), 0.4f, 0.7f, 0.9f, 8);
}

void Spawner::onUpdate() {
	spawnTime -= TIME_SYNC;

	if (spawnTime <= 0) {
		Vec3 * enPos = new Vec3(-((float)window / 2) + 1, enemyY, ((float)window / 2) - 9);
		new Enemy(scene, enPos, 1, enemyMesh, enemyMaterial, 5, 20);
		spawnTime = SPAWN_TIME;
	}
}

Spawner::~Spawner() {
	delete enemyMesh;
	delete enemyMaterial;
}