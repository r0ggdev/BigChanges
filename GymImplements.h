#pragma once
#include"BasicFeatures.h"
class GymImplements : public BasicFeatures //HERENCIA de la clase BasicFeatures la cual se usa para los implementos de GYM en el nivel 1
{
public:
	GymImplements(short x, short value) { //contructor de nuestra clase GymImplements donde se reciben valores por parametro y se le da valor a las variables heredadas de BasicFeatures
		this->value = value;
		this->x = x;
		this->dy = 0;

		SzH = 1;
		SzW = 1;

		dx = 25;

		IH = IW = H = W = 0;
		y = 400;
	}
	~GymImplements() { }

	void addSprite() { //funcion addSprite usada para darle un sprite a cada objeto segun el parametro recibido en el contructor
		switch (value)
		{
		case 1:	setImage("Resources\\Sprites\\GYM\\Box.png"); break;
		case 2:	setImage("Resources\\Sprites\\GYM\\BoxingBag.png"); break;
		case 3:	setImage("Resources\\Sprites\\GYM\\Force.png"); break;
		case 4:	setImage("Resources\\Sprites\\GYM\\GymRack.png"); break;
		case 5:	setImage("Resources\\Sprites\\GYM\\GymWeight.png"); break;
		}
	}

private:
	short value;
};
