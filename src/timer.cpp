#include "timer.h"

void Timer::step(float deltaTime)
{
	time += deltaTime;
	if (time >= length) {
		time -= length;
		timeout = true;
	}
}

void Timer::reset() {
	time = 0;
}
