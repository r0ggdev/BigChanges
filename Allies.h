#pragma once
#include"BasicFeatures.h"

class Allies : public BasicFeatures //herencia a la clase BasicFeatures
{
public:
	Allies(short value_x, short value_sprite, short value_dy) {//contructor de nuestros aliados
		this->x = value_x;
		this->dy = value_dy;
		this->value = value_sprite;
		SzH = 1;
		SzW = 1;
		dx = 10;

		IH = IW = H = W = 0;
		y = 100;

	}
	Allies(short x, short value) {
		this->value = value;
		this->countKcal = 0;
		this->x = x;
		this->dy = 0;



		SzH = 1;
		SzW = 1;

		dx = 0;

		IH = IW = H = W = 0;
		y = 300;

	}
	~Allies() {}

	//agrega sprite de los aliados "frutas/verduras"
	void addSpriteAllies() {//le damos el sprite correspondiente a nuestros aliados
		switch (value)
		{
		case 1:	setImage(".\\resources\\Sprites\\Allies\\Carrot.png"); break;
		case 2:	setImage(".\\resources\\Sprites\\Allies\\Jalapeno.png"); break;
		case 3:	setImage(".\\resources\\Sprites\\Allies\\Lettuce.png"); break;
		case 4:	setImage(".\\resources\\Sprites\\Allies\\Potatoes.png"); break;
		case 5:	setImage(".\\resources\\Sprites\\Allies\\Tomatoes.png"); break;
		}
	}

	//mueve a los aliados
	void move(Graphics^ gr, Direction key) { //funcion que usamos para el movimiento e impresion de nuestros aliados
		this->trackingBackground(gr, key);
		y += dy;
		paint(gr);
	}


	void AddCountKcal() { countKcal++; }
	short getCoutKcal() { return this->countKcal; }

private:
	short value, countKcal;
};
