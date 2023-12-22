#include "Engine.h"


HPEN Red_brick_pen, Blue_brick_pen;
HBRUSH Red_brick_brush, Blue_brick_brush;


const int Global_Scale = 3;
const int Brick_Width = 15;
const int Brick_Height = 7;
const int Cell_Width = 16;
const int Cell_Height = 8;
const int Level_X_Offset = 8;
const int Level_Y_Offset = 6;



char Level_01[14][12] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

/*Рисует платформу
*/

void Draw_Platform(HDC hdc)
{

}

void Draw_Frame(HDC hdc)
{

	int x = 50;
	int y = 100;
	int circle_size = 7;
	int distance_between = 21;

	//Draw_Lvl(hdc);

	HBRUSH brushEllipse = CreateSolidBrush(RGB(255, 85, 85));

	SelectObject(hdc, brushEllipse);

	Ellipse(hdc, x * Global_Scale, y * Global_Scale, (x + circle_size) * Global_Scale,
		(y + circle_size) * Global_Scale);

	Ellipse(hdc, (x + distance_between) * Global_Scale, y * Global_Scale, 
		(x + circle_size + distance_between) * Global_Scale, (y + circle_size) * Global_Scale);

	brushEllipse = CreateSolidBrush(RGB(85, 255, 255));
	SelectObject(hdc, brushEllipse);
	RoundRect(hdc, (x + 4) * Global_Scale, (y + 1) * Global_Scale, (x + 4 + (distance_between - 1)
		) * Global_Scale, (y + 1 + 5) * Global_Scale, 3 * Global_Scale, 3 * Global_Scale);
}

void init()
{
	Red_brick_pen = CreatePen(PS_SOLID, 0, RGB(255, 85, 85));
	Red_brick_brush = CreateSolidBrush(RGB(255, 85, 85));
	Blue_brick_pen = CreatePen(PS_SOLID, 0, RGB(85, 255, 255));
	Blue_brick_brush = CreateSolidBrush(RGB(85, 255, 255));
}

void Draw_Brick(HDC hdc, int x, int y, char brick_type)
{
	HPEN pen;
	HBRUSH brush;
	switch (brick_type)
	{
	case 0: return;
	case 1:
		pen = Red_brick_pen;
		brush = Red_brick_brush;
		break;
	case 2:
		pen = Blue_brick_pen;
		brush = Blue_brick_brush;
		break;
	default:
		return;
	}

	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	RoundRect(hdc, x * Global_Scale, y * Global_Scale, (x + Brick_Width) * Global_Scale, (y + Brick_Height) * Global_Scale, Brick_Height, Brick_Height);
}

/*Функция нарисовать уровень
* Рисует уровень игры
*/

void Draw_Lvl(HDC hdc)
{
	for (int i = 0; i < 14; i++)
		for (int j = 0; j < 12; j++)
			Draw_Brick(hdc, Level_X_Offset + j * Cell_Width, Level_Y_Offset + i * Cell_Height, Level_01[i][j]);
}

/*
* Функция нарисовать_фрейм
* отрисовывает графику игры
*/