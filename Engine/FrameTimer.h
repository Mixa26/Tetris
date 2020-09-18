#pragma once

#include <chrono>

class FrameTimer
{
public:
	FrameTimer();
	float Mark();	//time count for the game
private:
	std::chrono::steady_clock::time_point last;
};