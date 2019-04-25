#include "time.h"

static Time * timeInstance = nullptr;

// Public

Time * Time::instance() {
	if (timeInstance == nullptr) {
		timeInstance = new Time();
	}

	return timeInstance;
}

void Time::markDelta() {
	lastTime = thisTime;

	milliseconds currTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	thisTime = currTime.count() / 1000.0;
}

float Time::getDelta() {
	return (float)(thisTime - lastTime);
}

// Private

Time::Time() {
	milliseconds currTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	thisTime = currTime.count() / 1000.0f;

	lastTime = thisTime;
}