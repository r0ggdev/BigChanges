#pragma once
#include"Header.h"

class Background //clase background que es la encargada de nuestro fondo
{
public:
	Background(char* image) { //contructor de nuestra clase background donde asignamos valor a nuestras variables
		this->image = image;
		Bitmap^ bmp = gcnew Bitmap(gcnew String(image));
		this->dx = 30;
		this->x = this->y = 0;
		this->width = bmp->Width;
		this->heigth = bmp->Height;

		delete bmp;
	}
	~Background() { delete image; }

	void paint(Graphics^ gr, Direction key) { //clae paint que usamos para imprimir nuestro fondo para nuestros niveles
		Bitmap^ bmp = gcnew Bitmap(gcnew String(image));
		Rectangle bottom_Area = Rectangle(x, y, width, heigth);
		gr->DrawImage(bmp, 0, 0, bottom_Area, GraphicsUnit::Pixel);

		if (x > 0) { if (key == Direction::Left) { x -= dx; } }
		if (x < 2350) { if (key == Direction::Right) { x += dx; } }

		delete bmp, bottom_Area;
	}

private:
	short x, y, width, heigth, dx;
	char* image;
};