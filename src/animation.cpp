#include "animation.h"


float Animation::getLength() const {
	return m_timer.getLength();
}

float Animation::currentFrame() const {
	return static_cast<int>(m_timer.getTime() / m_timer.getLength() * m_frameCount);
}

void Animation::step(float deltaTime) {
	m_timer.step(deltaTime);
}