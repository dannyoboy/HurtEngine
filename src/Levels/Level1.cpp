#include "Level1.h"
#include "../PathNode.h"
#include "../EndNode.h"
#include "../enemy.h"

constexpr float ENEMY_SPEED = 12;
constexpr float ENEMY_Y = 2;

Level1::Level1(Scene * scene, float window) {
	Vec3 * pos1 = new Vec3(-(window / 2) + 30, ENEMY_Y, (window / 2) - 9);
	PathNode * pn1 = new PathNode(scene, pos1, new Vec3(0, 0, -ENEMY_SPEED));

	Vec3 * pos2 = new Vec3(-(window / 2) + 28, ENEMY_Y, (window / 2) - 21);
	PathNode * pn2 = new PathNode(scene, pos2, new Vec3(-ENEMY_SPEED, 0, 0));

	Vec3 * pos3 = new Vec3(-(window / 2) + 3, ENEMY_Y, (window / 2) - 18);
	PathNode * pn3 = new PathNode(scene, pos3, new Vec3(0, 0, -ENEMY_SPEED));

	Vec3 * pos4 = new Vec3(-(window / 2) + 4, ENEMY_Y, (window / 2) - 31.5f);
	PathNode * pn4 = new PathNode(scene, pos4, new Vec3(ENEMY_SPEED, 0, 0));

	Vec3 * pos5 = new Vec3((window / 2) - 16, ENEMY_Y, (window / 2) - 29.5f);
	PathNode * pn5 = new PathNode(scene, pos5, new Vec3(0, 0, ENEMY_SPEED));

	Vec3 * pos6 = new Vec3((window / 2) - 18.5f, ENEMY_Y, (window / 2) - 5.5f);
	PathNode * pn6 = new PathNode(scene, pos6, new Vec3(ENEMY_SPEED, 0, 0));

	Vec3 * pos7 = new Vec3((window / 2) - 2.5f, ENEMY_Y, (window / 2) - 7.5f);
	PathNode * pn7 = new PathNode(scene, pos7, new Vec3(0, 0, -ENEMY_SPEED));

	Vec3 * pos8 = new Vec3((window / 2) - 4.5f, ENEMY_Y, -(window / 2) + 15.5f);
	PathNode * pn8 = new PathNode(scene, pos8, new Vec3(-ENEMY_SPEED, 0, 0));

	Vec3 * pos9 = new Vec3(-(window / 2) + 2.25f, ENEMY_Y, -(window / 2) + 18);
	PathNode * pn9 = new PathNode(scene, pos9, new Vec3(0, 0, -ENEMY_SPEED));

	Vec3 * pos10 = new Vec3(-(window / 2) + 4, ENEMY_Y, -(window / 2) + 6);
	PathNode * pn10 = new PathNode(scene, pos10, new Vec3(ENEMY_SPEED, 0, 0));
	
	Vec3 * endPos = new Vec3((window / 2) + 2.5f, ENEMY_Y, -(window / 2) + 8.5f);
	EndNode * end = new EndNode(scene, endPos);
}