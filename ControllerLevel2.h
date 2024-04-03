#pragma once
#include"Background.h"
#include "MainCharacter.h"
#include "Allies.h"
#include "MainEnemy.h"
#include "Peas.h"
#include "EnemySon.h"
#include "Clock.h"

#include<vector>

class ControllerLevel2 //clase controladora del nivel 2
{
public:
	ControllerLevel2() { //contructor de la clase controladora del nivel 2
		srand(time(NULL));
		enemy_boss = new MainEnemy();
		main_chraracter = new MainCharacter();
		main_chraracter->addSpriteMainCharacter(1);
		background = new Background(".\\resources\\Backgrounds\\Background_Lvl2.png");
		enemy_boss->setImage(".\\resources\\Sprites\\MainEnemy.png");
		allies = new vector<Allies*>();
		peas = new vector<Peas*>();
		enemy_son = new vector<EnemySon*>();
		clock = new vector<Clock*>();
		verification = false;
		ClockAct = false;
		colisionE = false;
		this->get_clock = false;
		this->alive_enemy = true;
		this->enabled_peas = false;
		this->count_peas = 0;
	}
	~ControllerLevel2() { delete[] enemy_boss, background, main_chraracter, alive_enemy; delete[]allies; delete[]peas; delete[]enemy_son; }
	
	

	//--Balas de guisantes--//

	void addPeas() { //funcion usada para la impresion de las peas o proyectiles , encargada de generar su posicion y velocidad de cambio dx
		if (enabled_peas) {
			short dx_peas = 0;
			main_chraracter->getIH() == 1 ? dx_peas = -15 : dx_peas = 15;
			peas->push_back(new Peas(main_chraracter->getX(), main_chraracter->getY(), dx_peas));
			count_peas++;
		}
	}
	void addPeasC() { //funcion usada parra añadir peas que luego podra disparar en el contador o inventario
		main_chraracter->addPeasCounter();
	}
	
	void movePeas(Graphics^ gr) { //funcion usada para imprimir y mover las peas o proyectiles
		for (short i = 0; i < peas->size(); i++) {
			peas->at(i)->addPeas(); peas->at(i)->movePeas(gr);
		}
	}
	void eraserPeas(short position) { peas->erase(peas->begin() + position); } //funcion usada para eliminar peas del arreglo


	//--Aliados--//

	void addAllies() { //funcion usada paragenerar a los aliados
		allies->push_back(new Allies(100 + rand() % (800 + 1 - 100), 1 + rand() % (5 + 1 - 1), 4 + rand() % (10 + 1 - 4)));
	}

	void paintAllies(Graphics^ gr, Direction key) { //funcion usada para imprimir a los aliados, les da su sprite y los mueve
		for (short i = 0; i < allies->size(); i++) {
			allies->at(i)->addSpriteAllies();
			allies->at(i)->move(gr, key);
		}
	}

	void eraserAllies(short position) { allies->erase(allies->begin() + position); } //funcion usada para eliminar aliados del arreglo


	void addClock() {  //funcion usada para añadir un objeto Clock
	Random r; 
	clock->push_back(new Clock(r.Next(30,1100))); ClockAct = true; }

	void paintClock(Graphics^ gr, Direction key) { //funcion usada para imprimir y mover con respecto al fondo a nuestro objeto Clock
		for (short i = 0; i < clock->size(); i++) {
			clock->at(i)->addSprite();
			clock->at(i)->move(gr, key);
		}
	}

	void eraserClock(short position) { clock->erase(clock->begin() + position); } //funcion usada para eliminar el objeto Clock del arreglo



	//--Enemigos--//

	void paintMainEnemy(Graphics^ gr, Direction key) { //funcion usada para pintar al BOSS
		enemy_boss->lifeBar(gr);
		enemy_boss->move(gr, key);
	}
	void eraserMainEnemy() { //funcion usada para eliminar al BOSS y imprimir una animacion de la destruccion de este
		if (!enemy_boss->aliveEnemy()) {
			alive_enemy = false;
			for (short i = 0; i < 10; i++) {
				addEnemySon();
			}
		}
	}

	void addEnemySon() { //funcion usada para añadir los objetos que se usaran en la animacion de muerte del BOSS
		enemy_son->push_back(new EnemySon(1 + rand() % (5 + 1 - 1), 6 + rand() % (10 + 1 - 6), 500 + rand() % (1100 + 1 - 500), -2 + rand() % (-4 + 1 - (-4))));
	}
	void paintEnemySon(Graphics^ gr, Direction key) { //funcion usada para imprimir la animacion de muerte del BOSS
		for (short i = 0; i < enemy_son->size(); i++) {
			enemy_son->at(i)->addSprite();
			enemy_son->at(i)->move(gr, key);
		}
	}
	void eraserEnemySon(short position) { enemy_son->erase(enemy_son->begin() + position); } //funcion usada para eliminar del arreglo lo objetos usados en la animacion de muerte del BOSS


	//--Colisiones--//

	void collisionMainCharacterWithAllies() { //comprueba la colusion de los aliados con el jugador y en base a esto añade peas
		for (short i = 0; i < allies->size(); i++) {
			if (allies->at(i)->getCollision().IntersectsWith(main_chraracter->getCollision())) {
				eraserAllies(i);
				colisionA = true;
				main_chraracter->addPeasCounter();
				break;
			}
			if (allies->at(i)->getY() > 400) {
				eraserAllies(i);
				break;
			}
		}
	}

	void collisionMainEnemy() { //funcion usada para comprobar la colision de las peas o proyectiles con el BOSS
		for (short i = 0; i < peas->size(); i++) {
			if (peas->at(i)->getCollision().IntersectsWith(enemy_boss->getCollision())) {
				eraserPeas(i);
				
				enemy_boss->decreaseLife();
				break;
			}
			if (peas->at(i)->getX() < 0 || peas->at(i)->getX() > 1100) {
				eraserPeas(i);
				break;
			}
		}
	}

	void collisionSonEnemys() {//funcion que comprueba la colision de los objetos de la animacion del BOSS con las peas o proyectiles
		for (short i = 0; i < enemy_son->size(); i++) {
			for (short j = 0; j < peas->size(); j++) {
				if (enemy_son->at(i)->getCollision().IntersectsWith(peas->at(j)->getCollision())) {
					eraserEnemySon(i);
					eraserPeas(j);
					break;
				}
			}
		}
	}

	void collisionWithClock() { //funcion que determina la colision de el objeto Clock con el jugador
		for (short i = 0; i < clock->size(); i++) {
			if (clock->at(i)->getCollision().IntersectsWith(main_chraracter->getCollision())) {
				get_clock = true;
				eraserClock(i);
				break;
			}
		}
	}

	void collisionMainCharacter() { //funcion encargada de comprobar la colision de el jugador con el BOSS
		if (main_chraracter->getCollision().IntersectsWith(enemy_boss->getCollision())) {
			colisionE = true;
			enemy_boss->change();
			main_chraracter->setX(1);
		}
	}


	//--Jugabilidad--//

	void resetTimer(Timer^ timer, Timer^ timer2, Form^ form) { //funcion utilizada para pausar el juegos y abrir un formulario con la pregunta matematica
		if (get_clock) {
			timer->Enabled = false;
			timer2->Enabled = false;

			
			form->ShowDialog();
			verification = true;

			ClockAct = false;
			timer->Enabled = true;
			timer2->Enabled = true;
			
		}
		enabled_peas ? timer->Enabled = false : timer->Enabled = true;

	}

	void powerPeasCharacter() { //funcion encargada de determinar si se reunen las peas suficientes para poder dispararle al BOSS
		if (main_chraracter->getPowerPeas()) {
			enabled_peas = true;
			if (count_peas >= 4) {
				enabled_peas = false;
				main_chraracter->resetPeasCounter();
				count_peas = 0;
			}
		}
	}
	void resetPeas() { //funcion encargada de resetar a 0 el contador de peas recolectadas
		enabled_peas = false;
		main_chraracter->resetPeasCounter();
		count_peas = 0;
	}

	void paintEverything(Graphics^ gr, Direction key) { //funcion encargada de imprimir todo , mover los objetos y comprobar las colisiones
		background->paint(gr, key);
		get_clock = false;
		paintClock(gr, key);
		if (alive_enemy) {
			paintMainEnemy(gr, key);
			eraserMainEnemy();
			collisionMainEnemy();
			collisionMainCharacter();
		}
		paintEnemySon(gr, key);
		collisionWithClock();
		collisionSonEnemys();
		collisionMainCharacterWithAllies();
		main_chraracter->peasMetter(gr);
		main_chraracter->move(gr, key);
		movePeas(gr);
		paintAllies(gr, key);
	}
	
	//metodos de acceso

	bool getClockAct() { return ClockAct; }
	bool getClock() { return this->get_clock; }
	void setClock(bool clock) { this->get_clock = clock; }
	bool getColisionE() { 
		if (colisionE)
		{
			colisionE = false;
			return true;
		}
		else
		{
			return false;
		}
		 }

	bool getColisionA() {
		if (colisionA)
		{
			colisionA = false;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool getAliveEnemy() {
		return alive_enemy;
	}
	bool getVerification() {
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

private:
	bool enabled_peas, alive_enemy, get_clock,ClockAct, verification,colisionE,colisionA;
	short count_peas;

	MainEnemy* enemy_boss;
	MainCharacter* main_chraracter;
	Background* background;
	vector<Peas*>* peas;
	vector<Allies*>* allies;
	vector<EnemySon*>* enemy_son;
	vector<Clock*>* clock;
};
