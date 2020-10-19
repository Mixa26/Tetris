#include "Score.h"

void Score::scorePlus()
{
	score += 10;
}

void Score::DrawBlock(Graphics& in_gfx, int i, int j)
{
	for (int y = j; y < j + dimension; y++)
	{
		for (int x = i; x < i + dimension; x++)
		{
			in_gfx.PutPixel(x, y, Colors::White);
		}
	}
}

void Score::DrawScore(Vec2 in_pos, int score, Graphics& in_gfx)
{
	switch (score)
	{
	case 0:
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 1);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 3);
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y + dimension * 4);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y + dimension * 4);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 1);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 3);
		break;									  
	case 1:										  
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y + dimension * 1);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y + dimension * 1);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y + dimension * 3);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y + dimension * 4);
		break;
	case 2:
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 1);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 4);
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y + dimension * 3);
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y + dimension * 4);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y + dimension * 4);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 1);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 4);
		break;
	case 3:
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 1);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 3);
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y + dimension * 4);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y + dimension * 4);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 1);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 3);
		break;
	case 4:
		DrawBlock(in_gfx, in_pos.x, in_pos.y);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 1);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 1);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 3);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 4);
		break;
	case 5:
		DrawBlock(in_gfx, in_pos.x, in_pos.y);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 1);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 4);
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y + dimension * 4);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y + dimension * 4);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 3);
		break;
	case 6:
		DrawBlock(in_gfx, in_pos.x, in_pos.y);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 1);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 3);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 4);
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y + dimension * 4);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y + dimension * 4);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 3);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 4);
		break;
	case 7:
		DrawBlock(in_gfx, in_pos.x, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 1);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 3);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 4);
		break;
	case 8:
		DrawBlock(in_gfx, in_pos.x, in_pos.y);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 1);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 3);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 4);
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y + dimension * 4);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y + dimension * 4);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 1);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 3);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 4);
		break;
	case 9:
		DrawBlock(in_gfx, in_pos.x, in_pos.y);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 1);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x, in_pos.y + dimension * 4);
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x + dimension * 1, in_pos.y + dimension * 4);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x + dimension * 2, in_pos.y + dimension * 4);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 1);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 2);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 3);
		DrawBlock(in_gfx, in_pos.x + dimension * 3, in_pos.y + dimension * 4);
		break;
	}
}
