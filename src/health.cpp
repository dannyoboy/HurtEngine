#include "health.h"

int healthMoney = INIT_HEALTH;

static string HEALTH_TAG("health");
static string MONEY_LABEL_TAG("moneyLabel");
static string DIGIT_TAG("digit");

static Material *DIGIT_MATERIALS[10];

Health::Health(Scene * scene, float hud_width, float hud_height, float camFactor, float hudY) : Entity(&HEALTH_TAG) {
	float labelX = -1 + hud_width + MONEY_LABEL_OFFSET + MONEY_LABEL_SIZE / 2;
	float labelY = -1 + hud_height / 2;
	Transform * labelTransform = new Transform(new Vec3(labelX * camFactor, hudY, labelY * camFactor), new Vec3(0, 180, 180), new Vec3(MONEY_LABEL_SIZE * camFactor, 1, MONEY_LABEL_SIZE * camFactor));
	Material * labelMaterial = new Material(&string("res/moneyLabel.png"), 1, 0, 0, 1);
	money_label = new Entity(&MONEY_LABEL_TAG);
	money_label->attachTransform(labelTransform);
	money_label->attachMaterial(labelMaterial);
	money_label->attachMesh(HURT_PLANE);
	scene->addEntity(money_label);

	float baseDigitX = labelX + MONEY_LABEL_SIZE / 2 + DIGIT_OFFSET;
	for (int i = 0; i < NUM_PLACES; i++) {
		float digitX = baseDigitX + (i + 0.5f) * DIGIT_SIZE;
		Transform * digitTransform = new Transform(new Vec3(digitX * camFactor, hudY, labelY * camFactor), new Vec3(0, 180, 180), new Vec3(DIGIT_SIZE * camFactor, 1, DIGIT_SIZE * camFactor));
		digits[i] = new Entity(&DIGIT_TAG);
		digits[i]->attachTransform(digitTransform);
		digits[i]->attachMesh(HURT_PLANE);
		digits[i]->setActive(false);
		scene->addEntity(digits[i]);
	}
	
	for (int i = 0; i < 10; i++) {
		string path = string("res/digits/") + to_string(i) + string(".png");
		DIGIT_MATERIALS[i] = new Material(&path, 1, 0, 0, 1);
	}
}

void Health::onLateUpdate() {
	int digitCount = 0;
	int value = healthMoney;
	while (value > 0) {
		value /= 10;
		digitCount++;
	}

	int place = (int)pow(10, digitCount - 1);
	for (int i = 0; i < NUM_PLACES; i++) {
		if (place > 0) {
			int digit = (healthMoney / place) % 10;
			digits[i]->attachMaterial(DIGIT_MATERIALS[digit]);
			digits[i]->setActive(true);
			place /= 10;
		}
		else if(i == 0 && healthMoney == 0) {
			digits[i]->attachMaterial(DIGIT_MATERIALS[0]);
			digits[i]->setActive(true);
		}
		else {
			digits[i]->setActive(false);
		}
	}
}

Health::~Health() {
	delete money_label->getTransform();
	delete money_label->getMaterial();

	for (int i = 0; i < NUM_PLACES; i++) {
		delete digits[i]->getTransform();
	}

	for (int i = 0; i < 10; i++) {
		delete DIGIT_MATERIALS[i];
	}
}