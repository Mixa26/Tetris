/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <time.h>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	grid({gfx.ScreenWidth / grid.dimension / 2 - grid.width / 2, gfx.ScreenHeight / grid.dimension / 2 - grid.height / 2})
{
	srand(time(NULL));
	for (int spawn = 0; spawn < Tiles::max; spawn++)
	{
		tile[spawn] = Tiles({ gfx.ScreenWidth / grid.dimension / 2 - 1, gfx.ScreenHeight / grid.dimension / 2 - grid.height / 2 }, (Tiles::Shape)(rand() % 7));
	}
	tileCheck = tile[0];
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = frametimer.Mark();

	tile[TilesSpawned].LCollision(grid, gfx);

	if (wnd.kbd.KeyIsPressed(VK_LEFT) && !tile[TilesSpawned].LCollision(grid, gfx))
	{
		helpful_int = 1;
		if (code_i != helpful_int) // regulates one press at a time
		{
			code_i = helpful_int;
			tile[TilesSpawned].MoveLeft();
		}
	}

	else if (wnd.kbd.KeyIsPressed(VK_RIGHT) && !tile[TilesSpawned].RCollision(grid, gfx))
	{
		helpful_int = 1;
		if (code_i != helpful_int) // regulates one press at a time
		{
			code_i = helpful_int;
			tile[TilesSpawned].MoveRight();
		}
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		helpful_int = 1;
		if (code_i != helpful_int) // regulates one press at a time
		{
			code_i = helpful_int;
			tile[TilesSpawned].moveCounter = 0.0f;
		}
		tile[TilesSpawned].movePeriod = tile[TilesSpawned].speedF;
	}
	else if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		helpful_int = 1;
		if (code_i != helpful_int) // regulates one press at a time
		{
			code_i = helpful_int;

			for (int x = 0; x < 4; x++) // initializing collision to false by default
			{
				for (int y = 0; y < 4; y++)
				{
					tile[TilesSpawned].occupied[y][x] = false;
				}
			}

			tileCheck = tile[TilesSpawned];		//checking if a tile can rotate
			tileCheck.rotation++;
			if (tileCheck.rotation > 4)
			{
				tileCheck.rotation = 1;
			}
			tileCheck.RotationCheck();
			if (!tileCheck.RotateCollision(grid, gfx))
			{

				tile[TilesSpawned].rotation++;

				if (tile[TilesSpawned].rotation > 4)
				{
					tile[TilesSpawned].rotation = 1;
				}
			}
			else
			{
				tileCheck.rotation = tile[TilesSpawned].rotation;
			}
		}
	}
	else
	{
		code_i = 0;
		tile[TilesSpawned].movePeriod = tile[TilesSpawned].speed;
	}

	if (tile[TilesSpawned].Landed(grid, gfx))   // checks if the tile landed 
	{
		tile[TilesSpawned].appendOcuppiedGrid(grid, gfx);
		TilesSpawned++;
	}

	tile[TilesSpawned].moveCounter += dt;						// speed of movement dependent by time
	if (tile[TilesSpawned].moveCounter >= tile[TilesSpawned].movePeriod)
	{
		tile[TilesSpawned].moveCounter -= tile[TilesSpawned].movePeriod;
		tile[TilesSpawned].MoveDown();
	}	

	for (int y = grid.height - 2; y >= 1; y--)		//makes lines dissapear in the game if theyre full
	{ 
		if (grid.lineFull(y))
		{
			grid.eliminateLine(y);
		}
	}

}

void Game::ComposeFrame()
{
	tile[TilesSpawned].Rotation(grid, gfx);
	grid.DrawTiles(gfx);
	grid.Draw(gfx);
	tile[TilesSpawned + 1].DrawNext(gfx, 30, 8);
}

