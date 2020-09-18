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

	if (wnd.kbd.KeyIsPressed(VK_LEFT) && !tile[TilesSpawned].LCollision(grid, gfx))
	{
		helpful_int = 1;
		if (code_i != helpful_int)
		{
			code_i = helpful_int;
			tile[TilesSpawned].MoveLeft();
		}
	}

	else if (wnd.kbd.KeyIsPressed(VK_RIGHT) && !tile[TilesSpawned].RCollision(grid, gfx))
	{
		helpful_int = 2;
		if (code_i != helpful_int)
		{
			code_i = helpful_int;
			tile[TilesSpawned].MoveRight();
		}
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		helpful_int = 3;
		if (code_i != helpful_int)
		{
			code_i = helpful_int;
			tile[TilesSpawned].moveCounter = 0.0f;
		}
		tile[TilesSpawned].movePeriod = tile[TilesSpawned].speedF;
	}
	else
	{
		code_i = 0;
		tile[TilesSpawned].movePeriod = tile[TilesSpawned].speed;
	}


	tile[TilesSpawned].moveCounter += dt;
	if (tile[TilesSpawned].moveCounter >= tile[TilesSpawned].movePeriod)
	{
		tile[TilesSpawned].moveCounter -= tile[TilesSpawned].movePeriod;
		tile[TilesSpawned].MoveDown();
	}	

	if (tile[TilesSpawned].Landed(grid, gfx))
	{
		tile[TilesSpawned].appendOcuppiedGrid(grid, gfx);
		TilesSpawned++;
	}
}

void Game::ComposeFrame()
{
	grid.Draw(gfx);
	for (int draw = 0; draw <= TilesSpawned; draw++)
	{
		tile[draw].Draw(gfx, tile[draw].shape);
	}
}

