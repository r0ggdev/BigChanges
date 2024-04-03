#pragma once
#include"BasicFeatures.h"

class MainEnemy : public BasicFeatures //HERENCIA de la clase BasicFeatures usada para nuesro BOSS
{
public:
	MainEnemy() { //contructor de nuestra clase MainEnemy donde asignamos valor a las variables heredadas de BasicFeatures
		SzW = 3;
		SzH = 2;
		x = 1500;
		y = 320;
		dx = 5;
		dy = 10;
		lifebar_enemy = new BasicFeatures();
		alive = true;
		life = 10;
	}
	~MainEnemy() { delete lifebar_enemy, alive, life; }

	//corrobora si el enemigo sigue vivo o no
	bool aliveEnemy() { life <= 0 ? alive = false : alive = true; return alive; }

	//disminuye el contador de vidas
	void decreaseLife() { life--; }

	//barra de vida para el enemigo 
	void lifeBar(Graphics^ gr) {
		lifebar_enemy->setImage(".\\resources\\Counters\\LifeBarEnemy.png");
		lifebar_enemy->setIW(0);
		lifebar_enemy->setSzH(7);
		lifebar_enemy->setSzW(1);
		lifebar_enemy->setX(x);
		lifebar_enemy->setY(y - 40);

		switch (life) {
		case 0: lifebar_enemy->setIH(6); break;
		case 2: lifebar_enemy->setIH(5); break;
		case 4: lifebar_enemy->setIH(4); break;
		case 6: lifebar_enemy->setIH(3); break;
		case 8: lifebar_enemy->setIH(2); dx = 15; break;
		case 9: lifebar_enemy->setIH(1); break;
		case 10: lifebar_enemy->setIH(0); break;
		}

		lifebar_enemy->paint(gr);
	}


	//funcion para muober al enemigo
	void move(Graphics^ gr, Direction key) {
		
		trackingBackground(gr, key);

		
		x += dx;


		if (x < 30) {
			x = 30;      // Asegurarse de no pasar el límite izquierdo
			dx = Math::Abs(dx); // Mantener la velocidad positiva al cambiar la dirección
		}
		else if (x + SzW * IW > 1100) {
			x = 1100 - SzW * IW; // Asegurarse de no pasar el límite derecho
			dx = -Math::Abs(dx); // Cambiar la dirección al llegar al límite derecho
		}

		// Actualizar el frame de la imagen
		dx > 0 ? IH = 1 : IH = 0;
		if (IW > 1) {
			IW = 0;
		}
		IW++;

		// Pintar el enemigo
		paint(gr);
	}
	void change() { dx *= -1; } //cambia la posicion de el BOSS
private:
	short life;
	bool alive;
	BasicFeatures* lifebar_enemy;
};
