#include "Tiles.h"

Tiles::Tiles(const Vec2 & in_loc)
{
	//init for tile location
	loc = in_loc;
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

void Tiles::Draw(Graphics & in_gfx, const Shape& in_shape, Color in_color) const
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
		for (int x = loc.x; x < loc.x + 2; x++)
		{
			for (int y = loc.y; y < loc.y + 2; y++)
			{
				DrawBlock(in_gfx, { x, y }, in_color);
			}
		}
		break;
	case Shape::I:
		for (int y = loc.y; y < loc.y + 4; y++)
		{
			DrawBlock(in_gfx, { loc.x, y }, in_color);
		}
		break;
	case Shape::S:
		DrawBlock(in_gfx, { loc.x + 1, loc.y }, in_color);
		DrawBlock(in_gfx, { loc.x + 2, loc.y }, in_color);
		DrawBlock(in_gfx, { loc.x, loc.y + 1}, in_color);
		DrawBlock(in_gfx, { loc.x + 1, loc.y + 1}, in_color);
		break;
	case Shape::Z:
		DrawBlock(in_gfx, { loc.x, loc.y }, in_color);
		DrawBlock(in_gfx, { loc.x + 1, loc.y }, in_color);
		DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, in_color);
		DrawBlock(in_gfx, { loc.x + 2, loc.y + 1 }, in_color);
		break;
	case Shape::L:
		DrawBlock(in_gfx, { loc.x, loc.y}, in_color);
		DrawBlock(in_gfx, { loc.x, loc.y + 1 }, in_color);
		DrawBlock(in_gfx, { loc.x, loc.y + 2}, in_color);
		DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, in_color);
		break;
	case Shape::J:
		DrawBlock(in_gfx, { loc.x + 1, loc.y }, in_color);
		DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, in_color);
		DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, in_color);
		DrawBlock(in_gfx, { loc.x, loc.y + 2 }, in_color);
		break;
	case Shape::T:
		DrawBlock(in_gfx, { loc.x, loc.y }, in_color);
		DrawBlock(in_gfx, { loc.x + 1, loc.y }, in_color);
		DrawBlock(in_gfx, { loc.x + 1, loc.y + 1}, in_color);
		DrawBlock(in_gfx, { loc.x + 2, loc.y }, in_color);
	}
}
