#pragma once

#include "Graphics.h"
#include "Vec2.h"

class Score
{
public:
	Score() = default;
	void scorePlus();
	void DrawBlock(Graphics& in_gfx, int i, int j);
	void DrawScore(Vec2 in_pos, int score, Graphics& in_gfx);
public:
	int dimension = 5;
	int score = 0;
};