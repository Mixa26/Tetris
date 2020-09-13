#include "Grid.h"

Grid::Grid(Vec2 in_loc)
{
	//init for location of the grid
	loc = in_loc;
}

void Grid::DrawBlock(Graphics& in_gfx,const Vec2& in_loc) const
{
	//Draws a single block
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
	//Draws the grid played in with DrawBlock function
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

void Grid::initializeBlockOccupied()
{
	for (int blocksX = 0; blocksX < width; blocksX++)  // initializing the grid blocks to occupied, and those inside to false
	{
		for (int blocksY = 0; blocksY < height; blocksY++)
		{
			occupied[blocksX][blocksY] = true;
		}
	}
	for (int blocksX = 1; blocksX < width - 2; blocksX++)
	{
		for (int blocksY = 1; blocksY < height - 2; blocksY++)
		{
			occupied[blocksX][blocksY] = false;
		}
	}
}
