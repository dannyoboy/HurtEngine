#include "Level1.h"
#include "../PathNode.h"
#include "../EndNode.h"

float ENEMY_SPEED = 12;

Level1::Level1(Scene * scene, float window) {

	Vec3 * pos1 = new Vec3(-(window / 2) + 30, 5, (window / 2) - 9);
	PathNode * pn1 = new PathNode(scene, pos1, new Vec3(0, 0, -ENEMY_SPEED));

	Vec3 * pos2 = new Vec3(-(window / 2) + 28, 5, (window / 2) - 20);
	PathNode * pn2 = new PathNode(scene, pos2, new Vec3(-ENEMY_SPEED, 0, 0));

	Vec3 * pos3 = new Vec3(-(window / 2) + 4, 5, (window / 2) - 18);
	PathNode * pn3 = new PathNode(scene, pos3, new Vec3(0, 0, -ENEMY_SPEED));

	Vec3 * pos4 = new Vec3(-(window / 2) + 6, 5, (window / 2) - 34);
	PathNode * pn4 = new PathNode(scene, pos4, new Vec3(ENEMY_SPEED, 0, 0));

	Vec3 * pos5 = new Vec3((window / 2) - 18, 5, (window / 2) - 32);
	PathNode * pn5 = new PathNode(scene, pos5, new Vec3(0, 0, ENEMY_SPEED));

	Vec3 * pos6 = new Vec3((window / 2) - 20, 5, (window / 2) - 7);
	PathNode * pn6 = new PathNode(scene, pos6, new Vec3(ENEMY_SPEED, 0, 0));

	Vec3 * pos7 = new Vec3((window / 2) - 4, 5, (window / 2) - 9);
	PathNode * pn7 = new PathNode(scene, pos7, new Vec3(0, 0, -ENEMY_SPEED));

	Vec3 * pos8 = new Vec3((window / 2) - 6, 5, -(window / 2) + 14);
	PathNode * pn8 = new PathNode(scene, pos8, new Vec3(-ENEMY_SPEED, 0, 0));

	Vec3 * pos9 = new Vec3(-(window / 2) + 4, 5, -(window / 2) + 16);
	PathNode * pn9 = new PathNode(scene, pos9, new Vec3(0, 0, -ENEMY_SPEED));

	Vec3 * pos10 = new Vec3(-(window / 2) + 6, 5, -(window / 2) + 4);
	PathNode * pn10 = new PathNode(scene, pos10, new Vec3(ENEMY_SPEED, 0, 0));

	Vec3 * endPos = new Vec3((window / 2) - 2, 5, -(window / 2) + 6);
	EndNode * end = new EndNode(scene, endPos);
}
