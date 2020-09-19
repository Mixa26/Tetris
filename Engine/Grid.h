#pragma once

#include "Vec2.h"
#include "Graphics.h"
#include "Colors.h"

class Grid
{
public:
	Grid(Vec2 in_loc);
	void DrawBlock(Graphics& in_gfx,const Vec2& in_loc,Color color) const;
	void Draw(Graphics& in_gfx) const;
	void DrawTiles(Graphics& in_gfx) const;
public:
	Color gridColor = Colors::Gray;
	Vec2 loc;
	static constexpr int dimension = 20; // of the blocks
	static constexpr int width = 12; // of the grid
	static constexpr int height = 22; // of the grid
	bool occupied[height][width];	//for collision testing
	Color colors[height][width];
public:
	Color green = Colors::Green;
	Color blue = Colors::Blue;
	Color yellow = Colors::Yellow;
	Color white = Colors::White;
	Color cyan = Colors::Cyan;
	Color red = Colors::Red;
	Color magenta = Colors::Magenta;
};