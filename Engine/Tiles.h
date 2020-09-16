#pragma once

#include "Vec2.h"
#include "Graphics.h"
#include "Grid.h"
#include "Colors.h"
#include <time.h>

class Tiles
{
public:
	enum class Shape
	{
		O,
		I,
		S,
		Z,
		L,
		J,
		T
	};
	Tiles() = default;
	Tiles(const Vec2& in_loc,const Shape& in_shape);
	void DrawBlock(Graphics& in_gfx, const Vec2& in_loc, Color in_color) const;
	void Draw(Graphics& in_gfx, const Shape& in_shape) const;
	void MoveDown();
	bool Landed(const Grid& in_grid, const Graphics& in_gfx);
	void appendOcuppiedGrid(Grid& in_grid, const Graphics& in_gfx) const;
public:
	static constexpr int max = 5000;
	float movePeriod = 0.2f;
	float moveCounter = 0.0f;
	bool occupied[4][4];
	Shape shape;
private:
	Vec2 loc;
	Color green = Colors::Green;
	Color blue = Colors::Blue;
	Color yellow = Colors::Yellow;
	Color white = Colors::White;
	Color cyan = Colors::Cyan;
	Color red = Colors::Red;
	Color magenta = Colors::Magenta;
};