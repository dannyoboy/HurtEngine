#pragma once

#include "hurtEngine/hurtEngine.h"

class Level1 {
public:
	Level1(Scene * scene, float window);
	void decrementEnemyCount();
	void addToHealthMoney(int val);
private:
	int numEnemies;
	int healthMoney;
};