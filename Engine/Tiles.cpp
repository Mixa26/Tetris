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
		occupied[2][0] = true;
		occupied[2][1] = true;
		occupied[1][1] = true;
		occupied[1][2] = true;
		break;
	case Shape::Z:
		occupied[1][0] = true;
		occupied[1][1] = true;
		occupied[2][1] = true;
		occupied[2][2] = true;
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

void Tiles::MoveDown()
{
	loc.y++;
}

void Tiles::MoveLeft()
{
	loc.x--;
}

void Tiles::MoveRight()
{
	loc.x++;
}

bool Tiles::Landed(const Grid & in_grid, const Graphics& in_gfx) const
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

bool Tiles::LCollision(const Grid& in_grid, const Graphics& in_gfx) const
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (occupied[y][x] && in_grid.occupied[loc.y - (in_gfx.ScreenHeight / in_grid.dimension / 2 - in_grid.height / 2) + y - 1][loc.x - (in_gfx.ScreenWidth / in_grid.dimension / 2 - in_grid.width / 2) + x - 1])
			{
				return true;
			}
		}
	}
	return false;
}

bool Tiles::RCollision(const Grid & in_grid, const Graphics & in_gfx) const
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (occupied[y][x] && in_grid.occupied[loc.y - (in_gfx.ScreenHeight / in_grid.dimension / 2 - in_grid.height / 2) + y - 1][loc.x - (in_gfx.ScreenWidth / in_grid.dimension / 2 - in_grid.width / 2) + x + 1])
			{
				return true;
			}
		}
	}
	return false;
}

bool Tiles::RotateCollision(const Grid & in_grid, const Graphics & in_gfx) const
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (occupied[y][x] && in_grid.occupied[loc.y - (in_gfx.ScreenHeight / in_grid.dimension / 2 - in_grid.height / 2) + y - 1][loc.x - (in_gfx.ScreenWidth / in_grid.dimension / 2 - in_grid.width / 2) + x])
			{
				return true;
			}
		}
	}
	return false;
}

void Tiles::appendOcuppiedGrid(Grid & in_grid,const Graphics& in_gfx) const
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (occupied[y][x])
			{
				in_grid.occupied[loc.y - (in_gfx.ScreenHeight / in_grid.dimension / 2 - in_grid.height / 2) + y - 1][loc.x - (in_gfx.ScreenWidth / in_grid.dimension / 2 - in_grid.width / 2) + x] = occupied[y][x];
			}
		}
	}
}

void Tiles::Rotation(const Grid & in_grid,Graphics & in_gfx)
{
	switch (shape)
	{
	case Shape::O:
		switch (rotation)
		{
		case 1:
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, yellow);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 1 }, yellow);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, yellow);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 2 }, yellow);

			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[2][1] = true;
			occupied[2][2] = true;
			break;
		case 2:
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, yellow);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 1 }, yellow);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, yellow);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 2 }, yellow);

			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[2][1] = true;
			occupied[2][2] = true;
			break;
		case 3:
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, yellow);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 1 }, yellow);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, yellow);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 2 }, yellow);

			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[2][1] = true;
			occupied[2][2] = true;
			break;
		case 4:
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, yellow);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 1 }, yellow);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, yellow);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 2 }, yellow);

			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[2][1] = true;
			occupied[2][2] = true;
			break;
		}
		break;
	case Shape::I:
		switch (rotation)
		{
		case 1:
			DrawBlock(in_gfx, { loc.x, loc.y + 1 }, green);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, green);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 1 }, green);
			DrawBlock(in_gfx, { loc.x + 3, loc.y + 1 }, green);

			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[1][3] = true;
			break;
		case 2:
			DrawBlock(in_gfx, { loc.x + 1, loc.y }, green);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, green);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, green);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 3 }, green);

			occupied[0][1] = true;
			occupied[1][1] = true;
			occupied[2][1] = true; 
			occupied[3][1] = true;
			break;
		case 3:
			DrawBlock(in_gfx, { loc.x, loc.y + 1 }, green);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, green);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 1 }, green);
			DrawBlock(in_gfx, { loc.x + 3, loc.y + 1 }, green);

			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[1][3] = true;
			break;
		case 4:
			DrawBlock(in_gfx, { loc.x + 1, loc.y }, green);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, green);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, green);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 3 }, green);

			occupied[0][1] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			occupied[3][1] = true;
			break;
		}
		break;
	case Shape::S:
		switch (rotation)
		{
		case 1:
			DrawBlock(in_gfx, { loc.x, loc.y + 2 }, cyan);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, cyan);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, cyan);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 1 }, cyan);

			occupied[2][0] = true;
			occupied[2][1] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			break;
		case 2:
			DrawBlock(in_gfx, { loc.x, loc.y }, cyan);
			DrawBlock(in_gfx, { loc.x, loc.y + 1 }, cyan);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, cyan);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, cyan);

			occupied[0][0] = true;
			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			break;
		case 3:
			DrawBlock(in_gfx, { loc.x, loc.y + 2 }, cyan);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, cyan);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, cyan);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 1 }, cyan);

			occupied[2][0] = true;
			occupied[2][1] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			break;
		case 4:
			DrawBlock(in_gfx, { loc.x, loc.y }, cyan);
			DrawBlock(in_gfx, { loc.x, loc.y + 1 }, cyan);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, cyan);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, cyan);

			occupied[0][0] = true;
			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			break;
		}
		break;
	case Shape::Z:
		switch (rotation)
		{
		case 1:
			DrawBlock(in_gfx, { loc.x , loc.y + 1 }, red);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, red);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, red);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 2 }, red);

			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			occupied[2][2] = true;
			break;
		case 2:
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 2}, red);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, red);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 1}, red);
			DrawBlock(in_gfx, { loc.x + 2, loc.y }, red);

			occupied[2][1] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[0][2] = true;
			break;
		case 3:
			DrawBlock(in_gfx, { loc.x , loc.y + 1 }, red);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, red);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, red);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 2 }, red);

			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			occupied[2][2] = true;
			break;
		case 4:
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, red);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, red);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 1 }, red);
			DrawBlock(in_gfx, { loc.x + 2, loc.y }, red);

			occupied[2][1] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[0][2] = true;
			break;
		}
		break;
	case Shape::L:
		switch (rotation)
		{
		case 1:
			DrawBlock(in_gfx, { loc.x, loc.y + 1 }, white);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, white);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 1 }, white);
			DrawBlock(in_gfx, { loc.x, loc.y + 2 }, white);

			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[2][0] = true;
			break;
		case 2:
			DrawBlock(in_gfx, { loc.x + 1, loc.y }, white);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, white);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, white);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 2 }, white);

			occupied[0][1] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			occupied[2][2] = true;
			break;
		case 3:
			DrawBlock(in_gfx, { loc.x, loc.y + 1 }, white);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, white);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 1 }, white);
			DrawBlock(in_gfx, { loc.x + 2, loc.y }, white);

			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[0][2] = true;
			break;
		case 4:
			DrawBlock(in_gfx, { loc.x + 1, loc.y }, white);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, white);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, white);
			DrawBlock(in_gfx, { loc.x, loc.y }, white);

			occupied[0][1] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			occupied[0][0] = true;
			break;
		}
		break;
	case Shape::J:
		switch (rotation)
		{
		case 1:
			DrawBlock(in_gfx, { loc.x, loc.y + 1 }, blue);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, blue);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 1 }, blue);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 2 }, blue);

			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[2][2] = true;
			break;
		case 2:
			DrawBlock(in_gfx, { loc.x + 1, loc.y }, blue);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, blue);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, blue);
			DrawBlock(in_gfx, { loc.x + 2, loc.y}, blue);

			occupied[0][1] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			occupied[0][2] = true;
			break;
		case 3:
			DrawBlock(in_gfx, { loc.x, loc.y + 1 }, blue);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, blue);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 1 }, blue);
			DrawBlock(in_gfx, { loc.x , loc.y }, blue);

			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[0][0] = true;
			break;
		case 4:
			DrawBlock(in_gfx, { loc.x + 1, loc.y }, blue);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, blue);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, blue);
			DrawBlock(in_gfx, { loc.x, loc.y + 2}, blue);

			occupied[0][1] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			occupied[2][0] = true;
			break;
		}
		break;
	case Shape::T:
		switch (rotation)
		{
		case 1:
			DrawBlock(in_gfx, { loc.x, loc.y + 1 }, magenta);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, magenta);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, magenta);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 1 }, magenta);

			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[2][1] = true;
			break;
		case 2:
			DrawBlock(in_gfx, { loc.x + 1, loc.y }, magenta);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, magenta);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, magenta);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 1 }, magenta);

			occupied[0][1] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			occupied[1][2] = true;
			break;
		case 3:
			DrawBlock(in_gfx, { loc.x + 1, loc.y }, magenta);
			DrawBlock(in_gfx, { loc.x , loc.y + 1 }, magenta);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1}, magenta);
			DrawBlock(in_gfx, { loc.x + 2, loc.y + 1 }, magenta);

			occupied[0][1] = true;
			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			break;
		case 4:
			DrawBlock(in_gfx, { loc.x + 1, loc.y }, magenta);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 1 }, magenta);
			DrawBlock(in_gfx, { loc.x + 1, loc.y + 2 }, magenta);
			DrawBlock(in_gfx, { loc.x , loc.y + 1 }, magenta);

			occupied[0][1] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			occupied[1][0] = true;
			break;
		}
		break;
	}
}

void Tiles::RotationCheck()
{
	switch (shape)
	{
	case Shape::O:
		switch (rotation)
		{
		case 1:
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[2][1] = true;
			occupied[2][2] = true;
			break;
		case 2:
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[2][1] = true;
			occupied[2][2] = true;
			break;
		case 3:
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[2][1] = true;
			occupied[2][2] = true;
			break;
		case 4:
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[2][1] = true;
			occupied[2][2] = true;
			break;
		}
		break;
	case Shape::I:
		switch (rotation)
		{
		case 1:
			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[1][3] = true;
			break;
		case 2:
			occupied[0][1] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			occupied[3][1] = true;
			break;
		case 3:
			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[1][3] = true;
			break;
		case 4:
			occupied[0][1] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			occupied[3][1] = true;
			break;
		}
		break;
	case Shape::S:
		switch (rotation)
		{
		case 1:
			occupied[2][0] = true;
			occupied[2][1] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			break;
		case 2:
			occupied[0][0] = true;
			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			break;
		case 3:
			occupied[2][0] = true;
			occupied[2][1] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			break;
		case 4:
			occupied[0][0] = true;
			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			break;
		}
		break;
	case Shape::Z:
		switch (rotation)
		{
		case 1:
			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			occupied[2][2] = true;
			break;
		case 2:
			occupied[2][1] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[0][2] = true;
			break;
		case 3:
			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			occupied[2][2] = true;
			break;
		case 4:
			occupied[2][1] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[0][2] = true;
			break;
		}
		break;
	case Shape::L:
		switch (rotation)
		{
		case 1:
			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[2][0] = true;
			break;
		case 2:
			occupied[0][1] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			occupied[2][2] = true;
			break;
		case 3:
			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[0][2] = true;
			break;
		case 4:
			occupied[0][1] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			occupied[0][0] = true;
			break;
		}
		break;
	case Shape::J:
		switch (rotation)
		{
		case 1:
			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[2][2] = true;
			break;
		case 2:
			occupied[0][1] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			occupied[0][2] = true;
			break;
		case 3:
			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[0][0] = true;
			break;
		case 4:
			occupied[0][1] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			occupied[2][0] = true;
			break;
		}
		break;
	case Shape::T:
		switch (rotation)
		{
		case 1:
			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			occupied[2][1] = true;
			break;
		case 2:
			occupied[0][1] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			occupied[1][2] = true;
			break;
		case 3:
			occupied[0][1] = true;
			occupied[1][0] = true;
			occupied[1][1] = true;
			occupied[1][2] = true;
			break;
		case 4:
			occupied[0][1] = true;
			occupied[1][1] = true;
			occupied[2][1] = true;
			occupied[1][0] = true;
			break;
		}
		break;
	}
}
