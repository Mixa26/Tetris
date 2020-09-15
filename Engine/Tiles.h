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
public:
	static int spawned;
	static constexpr int max = 5000;
	int shape;
	float movePeriod = 1.0f;
	float moveCounter = 0.0f;
	bool occupied[4][4];
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