#include "tester.h"

void Tester::onUpdate() {
	if (hurtKeyPressed(HURT_KEY_SEMICOLON)) {
		cout << "It's a tester" << endl;
	}
}