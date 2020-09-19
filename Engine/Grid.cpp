#include "Grid.h"

Grid::Grid(Vec2 in_loc)
{
	//init for location of the grid
	loc = in_loc;

	for (int x = width - 1; x >= 0; x--)
	{
		for (int y = height - 1; y >= 0; y--)
		{
			occupied[y][x] = true;
		}
	}

	for (int x = width - 2; x > 0; x--)
	{
		for (int y = height - 2; y >= 0; y--)
		{
			occupied[y][x] = false;
		}
	}
}

void Grid::DrawBlock(Graphics& in_gfx,const Vec2& in_loc,Color color) const
{
	//Draws a single block
	for (int x = in_loc.x * dimension; x < in_loc.x * dimension + dimension; x++)
	{
		for (int y = in_loc.y * dimension; y < in_loc.y * dimension + dimension; y++)
		{
			in_gfx.PutPixel(x, y, color);
		}
	}
}

void Grid::Draw(Graphics& in_gfx) const
{
	//Draws the grid played in with DrawBlock function
	for (int x = loc.x; x < loc.x + width; x++)
	{
		DrawBlock(in_gfx, { x, loc.y }, gridColor);
	}

	for (int x = loc.x; x < loc.x + width; x++)
	{
		DrawBlock(in_gfx, { x, loc.y + height }, gridColor);
	}

	for (int y = loc.y; y < loc.y + height; y++)
	{
		DrawBlock(in_gfx, { loc.x, y }, gridColor);
	}

	for (int y = loc.y; y < loc.y + height; y++)
	{
		DrawBlock(in_gfx, { loc.x + width - 1, y }, gridColor);
	}
}

void Grid::DrawTiles(Graphics & in_gfx) const
{
	for (int i = 1; i <= width - 2; i++)
	{
		for (int j = 1; j <= height - 2; j++)
		{
			if (occupied[j][i])
			{
				DrawBlock(in_gfx, {in_gfx.ScreenWidth / dimension / 2 - width / 2 + i, in_gfx.ScreenHeight / dimension / 2 - height / 2 + j + 1}, colors[j][i]);
			}
		}
	}
}
