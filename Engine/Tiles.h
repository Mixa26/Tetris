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
	void DrawBlock(Graphics& in_gfx, const Vec2& in_loc, Color in_color) const;		//draws 20 * 20 block 
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	bool Landed(const Grid& in_grid, const Graphics& in_gfx) const;
	bool LCollision(const Grid& in_grid, const Graphics& in_gfx) const;
	bool RCollision(const Grid& in_grid, const Graphics& in_gfx) const;
	bool RotateCollision(const Grid& in_grid, const Graphics& in_gfx) const;
	void appendOcuppiedGrid(Grid& in_grid, const Graphics& in_gfx) const;
	void Rotation(const Grid& in_grid, Graphics& in_gfx);
	void RotationCheck();
public:
	static constexpr int max = 5000;	//maximum tiles that can spawn (above this results in error)
	float movePeriod = 1.0f;
	float moveCounter = 0.0f;
	float speed = 1.0f;		//speed
	float speedF = 0.1f;	//speed faster
	bool occupied[4][4];	//collision detection
	int rotation = 1;	//rotation count
	Shape shape;
	Color color;
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