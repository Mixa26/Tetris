#pragma once

#include "Vec2.h"
#include "Graphics.h"
#include "Colors.h"

class Grid
{
public:
	Grid(Vec2 in_loc);
	void DrawBlock(Graphics& in_gfx,const Vec2& in_loc) const;
	void Draw(Graphics& in_gfx) const;
	void initializeBlockOccupied();
public:
	Color gridColor = Colors::Gray;
	Vec2 loc;
	static constexpr int dimension = 20; // of the blocks
	static constexpr int width = 12; // of the grid
	static constexpr int height = 22; // of the grid
	bool occupied[width][height];
};