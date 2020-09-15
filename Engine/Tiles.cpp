#include "Tiles.h"

Tiles::Tiles(const Vec2 & in_loc,const Shape& in_shape)
{
	//init for tile location
	loc = in_loc;
	shape = in_shape;

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			occupied[y][x] = false;
		}
	}

	switch (in_shape)
	{
	case Shape::O:
		occupied[1][1] = true;
		occupied[1][2] = true;
		occupied[2][1] = true;
		occupied[2][2] = true;
		break;
	case Shape::I:
		occupied[1][0] = true;
		occupied[1][1] = true;
		occupied[1][2] = true;
		occupied[1][3] = true;
		break;
	case Shape::S:
		occupied[1][0] = true;
		occupied[1][1] = true;
		occupied[2][1] = true;
		occupied[2][2] = true;
		break;
	case Shape::Z:
		occupied[2][0] = true;
		occupied[2][1] = true;
		occupied[1][1] = true;
		occupied[1][2] = true;
		break;
	case Shape::L:
		occupied[1][0] = true;
		occupied[1][1] = true;
		occupied[1][2] = true;
		occupied[2][0] = true;
		break;
	case Shape::J:
		occupied[1][0] = true;
		occupied[1][1] = true;
		occupied[1][2] = true;
		occupied[2][2] = true;
		break;
	case Shape::T:
		occupied[1][0] = true;
		occupied[1][1] = true;
		occupied[1][2] = true;
		occupied[2][1] = true;
		break;
	}
}

void Tiles::DrawBlock(Graphics& in_gfx, const Vec2& in_loc, Color in_color) const
{
	//Draws a single block
	for (int x = in_loc.x * Grid::dimension; x < in_loc.x * Grid::dimension + Grid::dimension; x++)
	{
		for (int y = in_loc.y * Grid::dimension; y < in_loc.y * Grid::dimension + Grid::dimension; y++)
		{
			in_gfx.PutPixel(x, y, in_color);
		}
	}
}

void Tiles::Draw(Graphics & in_gfx, const Shape& in_shape) const
{
	switch (in_shape)
	{
		//Draws Tiles with the DrawBlock function
		/*O,
		I,
		S,
		Z,
		L,
		J,
		T*/
	case Shape::O:
		DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, green);
		DrawBlock(in_gfx, { loc.x + 2, loc.y + 1 }, green);
		DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, green);
		DrawBlock(in_gfx, { loc.x + 2, loc.y + 2 }, green);
		break;
	case Shape::I:
		DrawBlock(in_gfx, { loc.x, loc.y + 1 }, green);
		DrawBlock(in_gfx, { loc.x + 1, loc.y + 1}, green);
		DrawBlock(in_gfx, { loc.x + 2, loc.y + 1 }, green);
		DrawBlock(in_gfx, { loc.x + 3, loc.y + 1 }, green);
		break;
	case Shape::S:
		DrawBlock(in_gfx, { loc.x, loc.y + 2 }, green);
		DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, green);
		DrawBlock(in_gfx, { loc.x + 1, loc.y + 1}, green);
		DrawBlock(in_gfx, { loc.x + 2, loc.y + 1}, green);
		break;
	case Shape::Z:
		DrawBlock(in_gfx, { loc.x , loc.y + 1 }, red);
		DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, red);
		DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, red);
		DrawBlock(in_gfx, { loc.x + 2, loc.y + 2 }, red);
		break;
	case Shape::L:
		DrawBlock(in_gfx, { loc.x, loc.y + 1}, white);
		DrawBlock(in_gfx, { loc.x, loc.y + 2 }, white);
		DrawBlock(in_gfx, { loc.x + 1, loc.y + 1}, white);
		DrawBlock(in_gfx, { loc.x + 2, loc.y + 1 }, white);
		break;
	case Shape::J:
		DrawBlock(in_gfx, { loc.x, loc.y + 1 }, blue);
		DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, blue);
		DrawBlock(in_gfx, { loc.x + 2, loc.y + 1 }, blue);
		DrawBlock(in_gfx, { loc.x + 2, loc.y + 2 }, blue);
		break;
	case Shape::T:
		DrawBlock(in_gfx, { loc.x, loc.y + 1 }, magenta);
		DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, magenta);
		DrawBlock(in_gfx, { loc.x + 1, loc.y + 2}, magenta);
		DrawBlock(in_gfx, { loc.x + 2, loc.y + 1}, magenta);
	}
}

void Tiles::MoveDown()
{
	loc.y++;
}

bool Tiles::Landed(const Grid & in_grid, const Graphics& in_gfx)
{
	for (int y = 3; y >= 0; y--)
	{
		for (int x = 0; x < 4; x++)
		{
			if (occupied[y][x] && in_grid.occupied[loc.y - (in_gfx.ScreenHeight / in_grid.dimension / 2 - in_grid.height / 2) + y][loc.x - (in_gfx.ScreenWidth / in_grid.dimension / 2 - in_grid.width / 2) + x])
			{
				return true;
			}
		}
	}
	return false;
}
