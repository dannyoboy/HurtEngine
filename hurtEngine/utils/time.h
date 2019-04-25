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
	double lastTime;
	double thisTime;
};