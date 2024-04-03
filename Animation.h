#pragma once
#include "Header.h"


class Animated //clase encargada de las animaciones(cinematicas) de nuestro juego
{
public:
	Animated();
	~Animated();
	int getIdx() { return this->iw; }
	int getIdy() { return this->ih; }
	void draw(Graphics^ g, int i);
	void anima(Graphics^ g, int i, char tecla);
private:
	int x, y, W1, H1, W2, H2, W3, H3, iw, ih;
	char* image1;
	char* image2;

};

inline Animated::Animated() //contructor de nuestra clase animated
{
	image1 = "resources\\History\\AnimatedLevel1.png";
	image2 = "resources\\History\\AnimatedLevel2.png";

	Bitmap^ bmp1 = gcnew Bitmap(gcnew String(image1));
	Bitmap^ bmp2 = gcnew Bitmap(gcnew String(image2));

	this->x = this->y = this->iw = this->ih = 0;
	this->W1 = bmp1->Width / 6;
	this->H1 = bmp1->Height / 3;
	this->W2 = bmp2->Width / 6;
	this->H2 = bmp2->Height / 4;


}

inline Animated::~Animated()
{
}

inline void Animated::draw(Graphics^ g, int i) //funcion usada para dibujar(imprimir) cada frame de nuestra animacion
{
	Bitmap^ bmp1 = gcnew Bitmap(gcnew String(image1));
	Bitmap^ bmp2 = gcnew Bitmap(gcnew String(image2));

	Rectangle area1 = Rectangle(W1 * iw, H1 * ih, W1, H1);
	Rectangle area2 = Rectangle(W2 * iw, H2 * ih, W2, H2);



	if (i == 1)g->DrawImage(bmp1, 0, 0, area1, GraphicsUnit::Pixel);
	if (i == 2)g->DrawImage(bmp2, 0, 0, area2, GraphicsUnit::Pixel);


}

inline void Animated::anima(Graphics^ g, int i, char tecla) //funcion que usamos para cambiar frame a frame de nuesta animacion
{
	if (i == 1)
	{
		if (ih < 2) {
			iw++;
			if (iw > 5)
			{
				iw = 0;
				ih++;

			}
		}

		if (ih >= 2)
		{

			if (tecla == 'E')iw += 2;


		}
	}

	if (i == 2)
	{

		if (ih < 3) {
			iw++;
			if (iw>5)
			{
				iw = 0; 
				ih++;
			}
			
		}
		if (ih>=3)
		{
			if (iw < 3) { if (tecla == 'E')iw++; }
			if (iw >= 3) { if (tecla == 'E')iw+=2; }
		}

	}
}
