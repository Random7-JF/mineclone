#pragma once

class Timer {
	private:
		float length, time;
		bool timeout;
	public:
		Timer(float length) : length(length), time(0), timeout(false) { }

		void step(float deltaTime);
		void reset();
	public:
		bool isTimeout() const { return timeout; }
		float getTime() const { return time; }
		float getLength() const { return length; }
};
