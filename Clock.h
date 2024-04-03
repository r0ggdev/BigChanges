#pragma once
#include"BasicFeatures.h"
class Clock : public BasicFeatures //HERENCIA clase clock la cual tiene una clase padre llamada BasicFeatures
{
public:
	Clock(short x_clock) {//contructor de nuestro objeto clock
		x = x_clock;
		y = 500;
		SzW = 11;
		SzH = 1;
		dx = 20;
		dy = H = W = 0;
		IH = IW = 0;
	}
	~Clock() {}

	void addSprite() { setImage(".\\resources\\Sprites\\Clock.png"); }//clase add sprite que usamos para darle el sprite correspondiente a nuestro reloj o clock

	void move(Graphics^ gr, Direction key) { //funcion move que usamos para el movimiento en nuestro juego de nuestro objeto reloj
		trackingBackground(gr, key);
		IW++;
		if (IW > 8) { IW = 0; }
		paint(gr);
	}
};
