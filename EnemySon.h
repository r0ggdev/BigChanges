#pragma once
#include"BasicFeatures.h"

class EnemySon : public BasicFeatures //HERENCIA de la clase BasicFeatures en la clase EnemySon encargada de los objetos para la animaciond de muerte del BOSS y enemigos del nivel 1
{
public:
	EnemySon(short value, short dx_value, short x_value, short jumpHeigth) { //contructor de la clase EnemySon donde se incializan las variables y reciben valores por parametros

		x = x_value;
		y = 400;

		evalue = value;

		dx = dx_value;
		IW = IH = H = W = 0;
		SzH = SzW = 1;

		jump_y = 400;
		jump_recoil = 30;
		jump_height = jumpHeigth;
		jump_x = 0;
		jump = true;
	}
	EnemySon(short x, short value, short dy) { //contructor de la clase EnemySon donde se inicializan las variables , pero recibe diferentes parametros con respecto al contructor anterior
		this->evalue = value;
		this->x = x;
		this->dy = dy;

		SzH = 1;
		SzW = 1;

		dx = 25;
		IH = IW = H = W = 0;
		y = 0;

	}

	~EnemySon() {}

	void addSprite() { //funcion encargada de añadir sprites a cada objeto enemigo
		switch (evalue)
		{
		case 1: setImage(".\\resources\\Sprites\\Enemys\\Burguer.png"); break;
		case 2: setImage(".\\resources\\Sprites\\Enemys\\Cupcake.png"); break;
		case 3: setImage(".\\resources\\Sprites\\Enemys\\FrenchFries.png"); break;
		case 4: setImage(".\\resources\\Sprites\\Enemys\\Pizza.png"); break;
		case 5: setImage(".\\resources\\Sprites\\Enemys\\Tacos.png"); break;
		}
	}

	void move(Graphics^ gr, Direction key) { //funcion usada para mover con respecto al fondo a los objetos enemigos
		trackingBackground(gr, key);
		jump = true;
		if (x + dx < 200 || x + dx > gr->VisibleClipBounds.Width) { dx *= -1; }
		jumping();
		x += dx;
		paint(gr);
	}

	void fall(Graphics^ gr, Direction key) { //funcion fall para hacer la animacion de caer desde el cielo a los enemigos usada en el nivel 1
		trackingBackground(gr,key);
		y += dy;
		paint(gr);
	}

private:
	short evalue;
};
