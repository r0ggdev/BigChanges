#pragma once
#include"BasicFeatures.h"

class Water :public BasicFeatures //Herencia de la clase BasicFeatures en la clase Water, usada para las botellas de agua en el nivel 1
{
public:
	Water(short x = 0) { //contructor de la clase water donde se inician los valores de las variables
		this->x = x;
		dx = 25;
		dy = IH = IW = H = W = 0;
		SzH = 1;
		SzW = 1;
		y = 400;
	}
	void addSprite() { setImage("Resources\\Sprites\\Water.png"); } //funcion para añadir el sprite a la botella de agua

	~Water() {}

};
