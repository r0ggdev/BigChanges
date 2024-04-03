#pragma once
#include "BasicFeatures.h"

class Peas : public BasicFeatures //HERENCIA de la clase BasicFeatures , en esta clase Peas la usamos para los proyectiles de guisantes
{
public:
	Peas(short x_peas, short y_peas, short dx_peas) { //contructor de nuestra clase peas donde asignamos valor a las variables heredadas de BasicFeatures
		x = x_peas + 45;
		y = y_peas + 45;
		IW = IH = 0;
		dx = dx_peas;
		dy = 0;
		SzH = 1;
		SzW = 2;
	}
	~Peas() {}

	void addPeas() { setImage(".\\resources\\Sprites\\Peas.png"); } //damos el sprite correspondiente a Peas
	void movePeas(Graphics^ gr) {//funcion usada para el movimiento de Peas o proyectiles
		x += dx;
		IW++;
		if (IW > 1) { IW = 0; }
		paint(gr);
	}
};