#include "Level1.h"
#include "../PathNode.h"
#include "../EndNode.h"
#include "../enemy.h"

float ENEMY_SPEED = 12;

Level1::Level1(Scene * scene, float window) {
	numEnemies = 1; //change to how many enemies are created
	healthMoney = 1000; //change to whatever health/money they should start with

	Vec3 * pos1 = new Vec3(-(window / 2) + 30, 0.5f, (window / 2) - 9);
	PathNode * pn1 = new PathNode(scene, pos1, new Vec3(0, 0, -ENEMY_SPEED));

	Vec3 * pos2 = new Vec3(-(window / 2) + 28, 0.5f, (window / 2) - 20);
	PathNode * pn2 = new PathNode(scene, pos2, new Vec3(-ENEMY_SPEED, 0, 0));

	Vec3 * pos3 = new Vec3(-(window / 2) + 4, 0.5f, (window / 2) - 18);
	PathNode * pn3 = new PathNode(scene, pos3, new Vec3(0, 0, -ENEMY_SPEED));

	Vec3 * pos4 = new Vec3(-(window / 2) + 6, 0.5f, (window / 2) - 30);
	PathNode * pn4 = new PathNode(scene, pos4, new Vec3(ENEMY_SPEED, 0, 0));

	Vec3 * pos5 = new Vec3((window / 2) - 18, 0.5f, (window / 2) - 28);
	PathNode * pn5 = new PathNode(scene, pos5, new Vec3(0, 0, ENEMY_SPEED));

	Vec3 * pos6 = new Vec3((window / 2) - 20, 0.5f, (window / 2) - 7);
	PathNode * pn6 = new PathNode(scene, pos6, new Vec3(ENEMY_SPEED, 0, 0));

	Vec3 * pos7 = new Vec3((window / 2) - 4, 0.5f, (window / 2) - 9);
	PathNode * pn7 = new PathNode(scene, pos7, new Vec3(0, 0, -ENEMY_SPEED));

	Vec3 * pos8 = new Vec3((window / 2) - 6, 0.5f, -(window / 2) + 18);
	PathNode * pn8 = new PathNode(scene, pos8, new Vec3(-ENEMY_SPEED, 0, 0));

	Vec3 * pos9 = new Vec3(-(window / 2) + 4, 0.5f, -(window / 2) + 20);
	PathNode * pn9 = new PathNode(scene, pos9, new Vec3(0, 0, -ENEMY_SPEED));

	Vec3 * pos10 = new Vec3(-(window / 2) + 6, 0.5f, -(window / 2) + 8);
	PathNode * pn10 = new PathNode(scene, pos10, new Vec3(ENEMY_SPEED, 0, 0));

	Vec3 * endPos = new Vec3((window / 2) - 2, 0.5f, -(window / 2) + 10);
	EndNode * end = new EndNode(scene, endPos);

	Vec3 * enPos1 = new Vec3(-((float)window / 2) + 1, 0.5f, ((float)window / 2) - 9);
	Enemy * en1 = new Enemy(scene, enPos1, 100, 1, this);
}

void Level1::decrementEnemyCount() {
	numEnemies--;
	if (numEnemies == 0) {
		//TODO: do something when all enemies have been eliminated
	}
}

void Level1::addToHealthMoney(int val) {
	healthMoney += val;
	if (healthMoney <= 0) {
		//TODO: do something if you lost
	}
}
