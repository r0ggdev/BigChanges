#pragma once
#include"BasicFeatures.h"

class MainCharacter : public BasicFeatures // HERENCIA de la clase BasicFeatures , esta clase la usamos para nuestro jugador en ambos niveles
{
public:
	MainCharacter() { //contructor de nuestra clase MainCharacter donde asignamos valor a nuestras variables heredadas de BasicFeatures
		x = 200;
		y = 400;

		SzW = 4;
		SzH = 2;
		dx = dy = H = W = 0;
		IH = IW = 0;

		jump_y = 400;
		jump_recoil = -50;
		jump_height = -4;
		jump_x = 0;
		jump = false;

		this->counter_water = 0;
		peas_counter = 0;
		power_peas = false;
		peas_metter = new BasicFeatures();

	}
	~MainCharacter() { delete peas_metter, peas_counter, power_peas; }

	//medidor de balas tipo guisantes
	void peasMetter(Graphics^ gr) {
		peas_metter->setImage(".\\resources\\Counters\\PeasMeter.png");
		peas_metter->setIW(0);
		peas_metter->setSzH(6);
		peas_metter->setSzW(1);
		peas_metter->setX(2);
		peas_metter->setY(40);

		switch (peas_counter) {
		case 0: peas_metter->setIH(0); break;
		case 1: peas_metter->setIH(1); break;
		case 2: peas_metter->setIH(2); break;
		case 3: peas_metter->setIH(3); break;
		case 4: peas_metter->setIH(4); break;
		case 5: peas_metter->setIH(5); break;
		}
		peas_metter->paint(gr);
	}

	void addPeasCounter() { peas_counter > 4 ? power_peas = true : peas_counter++; } //usado para añadir peas o proyectiles
	bool getPowerPeas() { return power_peas; } //usador para obtener la variable PowerPeas
	void resetPeasCounter() { peas_counter = 0;  power_peas = false; }//usado para resetear el contador de peas o proyectiles a 0
	short getPeasCounter() { return this->peas_counter; }//usado para obtener el numero de peas recolectadas

	//funcion para la seleccion del sprite
	void addSpriteMainCharacter(short value) {
		switch (value) {
		case 1: this->setImage(".\\resources\\Sprites\\MainCharacters.png"); break;
		case 2: setImage(""); break;
		}
	}

	//funcion para evaluar la tecla presionada y el cambio de posicion
	void chagePosition(Direction Key) {
		switch (Key)
		{
		case Left:
			dx = -10; dy = 0;
			break;

		case Right:
			dx = 10; dy = 0;
			break;
		case Space:
			jump = true;
			break;

		case None:
			dx = 0; dy = 0;
			break;
		}
	}

	//mover al jugador
	void move(Graphics^ gr, Direction Key) {
		chagePosition(Key);
		jumping();
		if (Key == Direction::Left) { IH = 1; IW++; }
		if (Key == Direction::Right) { IH = 0; IW++; }
		if (IW > 3) { IW = 0; }
		if (x + dx + IW > 100 && x + dx + IW + W < gr->VisibleClipBounds.Width - 200) { x += dx; }
		if (x < 50)x = 50;

		paint(gr);
	}

	void addCountWater() { counter_water++; }
	void restCountWater() { counter_water--; }

	short getCWater() { return this->counter_water; }


private:
	short peas_counter, life_min, life_max, counter_water;
	bool power_peas;
	BasicFeatures* peas_metter;
};
