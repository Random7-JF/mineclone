#pragma once
#include "timer.h"

class Animation {
	public:
		Animation() : m_timer(0), m_frameCount(0) {}
		Animation(int frameCount, float length) : m_frameCount(frameCount), m_timer(length) {}

	private:
		Timer m_timer;
		int m_frameCount;
		
	public:
		float getLength() const;
		float currentFrame() const;
		void step(float deltaTime);
};