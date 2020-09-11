#include "Grid.h"

Grid::Grid(Vec2 in_loc)
{
	loc = in_loc;
}

void Grid::DrawBlock(Graphics& in_gfx,const Vec2& in_loc) const
{
	for (int x = in_loc.x * dimension; x < in_loc.x * dimension + dimension; x++)
	{
		for (int y = in_loc.y * dimension; y < in_loc.y * dimension + dimension; y++)
		{
			in_gfx.PutPixel(x, y, gridColor);
		}
	}
}

void Grid::Draw(Graphics& in_gfx) const
{
	for (int x = loc.x; x < loc.x + width; x++)
	{
		DrawBlock(in_gfx, { x, loc.y });
	}

	for (int x = loc.x; x < loc.x + width + 1; x++)
	{
		DrawBlock(in_gfx, { x, loc.y + height });
	}

	for (int y = loc.y; y < loc.y + height; y++)
	{
		DrawBlock(in_gfx, { loc.x, y });
	}

	for (int y = loc.y; y < loc.y + height; y++)
	{
		DrawBlock(in_gfx, { loc.x + width, y });
	}
}
