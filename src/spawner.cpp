#include "spawner.h"

#define ENEMY_1 new Enemy(scene, enPos, 1, enemyMesh, enemy1Material, 2, 25, 1)
#define ENEMY_2 new Enemy(scene, enPos, 2, enemyMesh, enemy2Material, 5, 50, 1.1f)
#define ENEMY_3 new Enemy(scene, enPos, 3, enemyMesh, enemy3Material, 10, 100, 1.2f)

static string TAG("spawner");
static Mesh * enemyMesh = nullptr;
Material * enemy1Material = nullptr;
Material * enemy2Material = nullptr;
Material * enemy3Material = nullptr;

Spawner::Spawner(Scene * sceneIn, float enemyYIn, float windowIn, Level1 * level1In) :
	Entity(&TAG), scene(sceneIn), enemyY(enemyYIn), window(windowIn), level1(level1In) {
	enemyMesh = new Mesh(&string("res/drone.obj"));
	enemy1Material = new Material(&string("res/drone1.png"), 0.4f, 0.7f, 0.9f, 8);
	enemy2Material = new Material(&string("res/drone2.png"), 0.4f, 0.7f, 0.9f, 8);
	enemy3Material = new Material(&string("res/drone3.png"), 0.4f, 0.7f, 0.9f, 8);
}

void Spawner::onUpdate() {
	totalTime += TIME_SYNC;

	if (totalTime >= ENEMY_1_SPAWN_TIME) {
		spawnTime1 += TIME_SYNC;

		if (spawnTime1 >= spawnRate1) {
			spawnTime1 = 0;
			Vec3 * enPos = new Vec3(-((float)window / 2) + 1, enemyY, ((float)window / 2) - 8.5f);
			ENEMY_1;
		}

		spawnRate1 -= ENEMY_1_SPAWN_ACC;
	}

	if (totalTime >= ENEMY_2_SPAWN_TIME) {
		spawnTime2 += TIME_SYNC;

		if (spawnTime2 >= spawnRate2) {
			spawnTime2 = 0;
			Vec3 * enPos = new Vec3(-((float)window / 2) + 1, enemyY, ((float)window / 2) - 8.5f);
			ENEMY_2;
		}

		spawnRate2 -= ENEMY_2_SPAWN_ACC;
	}

	if (totalTime >= ENEMY_3_SPAWN_TIME) {
		spawnTime3 += TIME_SYNC;

		if (spawnTime3 >= spawnRate3) {
			spawnTime3 = 0;
			Vec3 * enPos = new Vec3(-((float)window / 2) + 1, enemyY, ((float)window / 2) - 8.5f);
			ENEMY_3;
		}

		spawnRate3 -= ENEMY_3_SPAWN_ACC;
	}
}

Spawner::~Spawner() {
	delete enemyMesh;
	delete enemy1Material;
	delete enemy2Material;
	delete enemy3Material;
}