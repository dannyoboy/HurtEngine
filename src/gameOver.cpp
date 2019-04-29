#include "gameOver.h"

static string TAG("gameOver");

static Material *DIGIT_MATERIALS[10];

GameOver::GameOver(Scene * scene, float camFactor) : Entity(&TAG) {
	// Game over label
	Material * gameOverLabelMaterial = new Material(&string("res/gameOver.png"), 1, 0, 0, 1);
	const float gameOverLabelSize = 1.25f * camFactor;
	Transform * gameOverLabelTransform = new Transform(new Vec3(0, 0, 0.5f * camFactor), new Vec3(0, 180, 180), new Vec3(gameOverLabelSize, 1, gameOverLabelSize));
	gameOverLabel = new Entity(&TAG);
	gameOverLabel->attachMesh(HURT_PLANE);
	gameOverLabel->attachMaterial(gameOverLabelMaterial);
	gameOverLabel->attachTransform(gameOverLabelTransform);
	scene->addEntity(gameOverLabel);

	// Score label
	Material * scoreLabelMaterial = new Material(&string("res/scoreLabel.png"), 1, 0, 0, 1);
	const float scoreLabelSize = 0.3f * camFactor;
	const float scoreLabelOffset = 0.02f * camFactor;
	Transform * scoreLabelTransform = new Transform(new Vec3(-scoreLabelSize / 2 - scoreLabelOffset, 0, 0), new Vec3(0, 180, 180), new Vec3(scoreLabelSize, 0, scoreLabelSize));
	scoreLabel = new Entity(&TAG);
	scoreLabel->attachMesh(HURT_PLANE);
	scoreLabel->attachMaterial(scoreLabelMaterial);
	scoreLabel->attachTransform(scoreLabelTransform);
	scene->addEntity(scoreLabel);

	// Score digits
	float digitsBaseX = scoreLabelOffset;
	const float digitsSize = 0.07f;
	for (int i = 0; i < NUM_GAME_OVER_DIGITS; i++) {
		digits[i] = new Entity(&TAG);
		digits[i]->attachMesh(HURT_PLANE);
		digits[i]->attachTransform(new Transform(new Vec3(digitsBaseX + camFactor * (i + 0.5f) * digitsSize, 0, -0.05f), new Vec3(0, 180, 180), new Vec3(digitsSize * camFactor, 1, digitsSize * camFactor)));
		digits[i]->setActive(false);
		scene->addEntity(digits[i]);
	}

	// Digit textures
	for (int i = 0; i < 10; i++) {
		string path = string("res/digits/") + to_string(i) + string(".png");
		DIGIT_MATERIALS[i] = new Material(&path, 1, 0, 0, 1);
	}
}

void GameOver::onSceneLoad() {
	int digitCount = 0;
	int value = score;
	while (value > 0) {
		value /= 10;
		digitCount++;
	}

	int place = (int)pow(10, digitCount - 1);
	for (int i = 0; i < NUM_GAME_OVER_DIGITS; i++) {
		if (place > 0) {
			int digit = (score / place) % 10;
			digits[i]->attachMaterial(DIGIT_MATERIALS[digit]);
			digits[i]->setActive(true);
			place /= 10;
		}
		else if (i == 0 && score <= 0) {
			digits[i]->attachMaterial(DIGIT_MATERIALS[0]);
			digits[i]->setActive(true);
			score = 0;
		}
		else {
			digits[i]->setActive(false);
		}
	}
}

GameOver::~GameOver() {
	delete gameOverLabel->getTransform();
	delete gameOverLabel->getMaterial();
	delete scoreLabel->getTransform();
	delete scoreLabel->getMaterial();

	for (int i = 0; i < NUM_GAME_OVER_DIGITS; i++) {
		delete digits[i]->getTransform();
	}

	for (int i = 0; i < 10; i++) {
		delete DIGIT_MATERIALS[i];
	}
}