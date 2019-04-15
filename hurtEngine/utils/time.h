#pragma once

#include <chrono>

using namespace std::chrono;

class Time {
public:
	static Time * instance();
	void markDelta();
	float getDelta();
private:
	Time();
	float lastTime;
	float thisTime;
};