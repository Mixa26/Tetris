#include "FrameTimer.h"

FrameTimer::FrameTimer()
{
	last = std::chrono::steady_clock::now();
}

float FrameTimer::Mark()
{
	auto old = last;
	last = std::chrono::steady_clock::now();
	const std::chrono::duration<float> frameTime = last - old;
	return frameTime.count();
}
