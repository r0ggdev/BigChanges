#pragma once
#include"Background.h"
#include"MainCharacter.h"
#include"Clock.h"
#include"Allies.h"
#include"EnemySon.h"
#include"GymImplements.h"
#include "Water.h"
#include<iostream>
#include<vector>

class ControllerLevel1 //clase controladora del nivel 1
{
public:
	ControllerLevel1() {//contructor de nuestra clase controladora del nivel 1
		srand(time(NULL));

		water = new vector<Water*>();
		background = new Background("resources\\Backgrounds\\Background_Lvl1.png");
		main_character = new MainCharacter();
		get_Clock = false;
		verification = false;
		gym_implements = new vector<GymImplements*>();
		enemy = new vector<EnemySon*>();
		clock = new vector<Clock*>();
		end_game = false;
		clockAct = false;
		collision_allies = false;
		main_character->addSpriteMainCharacter(1);
	}
	~ControllerLevel1() { delete background, main_character, clock; delete[]water, gym_implements, enemy, allies, end_game, collision_allies; }

	short getWaterSize() { return water->size(); } //funcion que usamos para obtener el numero de botellas de agua que hay en nuestro arreglo

			
	void paint(Graphics^ gr, Direction key) { //funcion paint que nos sirve para dar sprites, mostrar y mover todos nuestros objetos en el nivel 1
		background->paint(gr, key);
		main_character->chagePosition(key);
		main_character->move(gr, key);
		get_Clock = false;
		paintClock(gr,key);
		collisionWithClock();
		for (int i = 0; i < water->size(); i++) {
			water->at(i)->addSprite();
			water->at(i)->paint(gr);
			water->at(i)->trackingBackground(gr, key);
		}

		for (int i = 0; i < gym_implements->size(); i++) {
			gym_implements->at(i)->addSprite();
			gym_implements->at(i)->paint(gr);
			gym_implements->at(i)->trackingBackground(gr, key);
		}

		for (int i = 0; i < enemy->size(); i++) {
			enemy->at(i)->addSprite();
			enemy->at(i)->fall(gr, key);
			enemy->at(i)->trackingBackground(gr, key);
		}
	}

	void addClock() { //funcion añadir para nuestro objeto CLock
		Random r;
		clock->push_back(new Clock(r.Next(30,1100))); clockAct = true; }

	void paintClock(Graphics^ gr, Direction key) { //funcion usada para pintar y mover nuestro objeto Clock
		for (short i = 0; i < clock->size(); i++) {
			clock->at(i)->addSprite();
			clock->at(i)->move(gr, key);
		}
	}

	void resetTimer(Timer^ timer, Timer^ timer2, Form^ form) { //funcion que usamos para pausar el nivel 1 y poder mostrar otro formulario con una pregunta matematica
		if (get_Clock) {
			timer->Enabled = false;
			timer2->Enabled = false;


			form->ShowDialog();
			verification = true;
			clockAct = false;
			timer->Enabled = true;
			timer2->Enabled = true;

		}
		

	}

	bool endGame(float objective_now) { //funcion que nos ayuda a determinar si el juego acabo y nos retorna un booleano
		if (main_character->getCWater() < 0 && objective_now < 1) { end_game = true; }
		return end_game;
	}

	void addGymImplements() {  //funcion que usamos para generar nuestros objetos de GYM
		for (int i = 0; i < 5; i++) {
			gym_implements->push_back(new GymImplements(200 + rand() % (2900 + 1 - 200), 1 + rand() % (5 + 1 - 1)));
		}
	}

	void addEnemys() { //funcion encargada de añadir enemigos

		enemy->push_back(new EnemySon(300 + rand() % (2900 + 1 - 300), 1 + rand() % (5 + 1 - 1), 15 + rand() % (30 + 1 - 15)));
	}


	void addWater() { //funcion encargada de añadir las botellas de agua en nuestro nivel
		for (int i = 0; i < 5; i++) {
			water->push_back(new Water(200 + rand() % (2700 + 1 - 200)));
		}
	}


	bool couterWater() {//funcion de tipo booleano que usamos para comprobar si hay 0 botellas de agua
		if (water->size() == 0) { return  true; }
		else { return false; }
	}

	void endAllies() { //funcion la cual se encarga de comprobar si los aliados siguen existiendo o colisionarion con un enemigo , en ese caso se elimina al enemigo
		for (int i = 0; i < allies->size(); i++) {

			for (int j = 0; j < enemy->size(); j++)
			{
				if (allies->at(i)->getCollision().IntersectsWith(enemy->at(j)->getCollision())) {
					collision_allies = true;
					enemy->erase(enemy->begin() + j);
				}
				if (collision_allies)
				{
					break;
				}
			}

		}
	}

	void endEnemys() {//funcion la cual se encarga de comprobar si los enemigos siguen existiendo o colisionarion con el jugador , en ese caso se elimina al enemigo, se resta una botella de agua a los conseguidas y se genera otra para que el jugador deba buscarla
		Random r;
		for (int i = 0; i < enemy->size(); i++) {
			if (enemy->at(i)->getCollision().IntersectsWith(main_character->getCollision())) {

				main_character->restCountWater();

				water->push_back(new Water(r.Next(30,1100)));
				enemy->erase(enemy->begin() + i);
				break;
			}
			if (enemy->at(i)->getY() > 650) {
				enemy->erase(enemy->begin() + i);
				break;
			}
		}
	}

	bool collisionWater() { //funcion encargada de comprobar si las botellas de agua colisionaron con el jugador , en ese caso sube el contador de botellas de agua
		bool aux = false;

		for (int i = 0; i < water->size(); i++) {
			if (main_character->getCollision().IntersectsWith(water->at(i)->getCollision())) {
				water->erase(water->begin() + i);
				main_character->addCountWater();
				aux = true;
				break;
			}

		}
		return aux;
	}

	void collisionWithClock() {	//funcion encargada de verificar si el objeto clock colisiono con el jugador, en ese caso se elimina el reloj y se vuelve verdadero el booleano que determina la colision para generar la pregunta
		for (short i = 0; i < clock->size(); i++) {
			if (clock->at(i)->getCollision().IntersectsWith(main_character->getCollision())) {
				get_Clock = true;
				eraserClock(i);
				break;
			}
		}
	}

	void eraserClock(short position) { clock->erase(clock->begin() + position); } //funcion encargada de eliminar el objeto clock del arreglo

	bool getVerification() { //funcion que nos ayuda a retornar la verificacion de si se hizo la pregunta o no
		if (verification)
		{
			verification = false;
			return !verification;
		}
		if (!verification)
		{
			return verification;
		}

	}

	bool collisionGym() { //funcion encargada de determinar su el jugador colisiono con los implementos de GYM
		bool aux = false;

		for (int i = 0; i < gym_implements->size(); i++) {
			if (main_character->getCollision().IntersectsWith(gym_implements->at(i)->getCollision())) {
				gym_implements->erase(gym_implements->begin() + i);
				aux = true;
				break;
			}
		}
		return aux;
	}

	int collisionEnemy() { //funcion encargada de verificar si los enemigos colisionaron con el jugador y nos retorna la cantidad de estos que colisionaron para poder realizar el descuento de puntos
		int aux = 0;
		for (int i = 0; i < enemy->size(); i++) {
			if (enemy->at(i)->getCollision().IntersectsWith(main_character->getCollision())) {

				aux++;
			}
		}
		return aux;
	}

	//metodos de acceso 

	bool getClockAct() { return clockAct; } //funcion la cual nos retorna un booleano para saber si el objeto Clock esta activo
	short getCWater() { return main_character->getCWater(); } //funcion que nos retorna la cantidad de botellas de agua
	bool getColAllies() { return this->collision_allies; } //funcion de tipo boleano que nos retorna si la colision con los aliados fue verdadera
	void setColAllies(bool set_collision_allies) { this->collision_allies = set_collision_allies; } 
	bool getPW() { return get_Clock; }


private:
	Background* background;
	MainCharacter* main_character;
	vector <Allies*>* allies;
	vector<GymImplements*>* gym_implements;
	vector <EnemySon*>* enemy;
	vector<Clock*>* clock;
	vector <Water*>* water;
	
	bool end_game,clockAct;
	bool collision_allies;
	bool get_Clock,verification;

};
