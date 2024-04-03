#pragma once
#include"Header.h"

class BasicFeatures
{
public:
	BasicFeatures() { image = new char[50]; this->jump = false; this->IH = this->IW = this->jump_recoil = 0; jump_height = -4; dx_tracking = 20; } //contructor de nuestra clase PADRE BasicFeatures la cual nos ayuda con otras clases
	~BasicFeatures() { delete image, jump_x, jump; }

	// funciones basicas para los diversos sprites a utilizar

	virtual void setImage(char* mint) { //clase setImage usada para asignar la imagen correspondiente que usamos para poder imprimirlas en nuestro juego
		strcpy(image, mint);
		Bitmap^ character = gcnew Bitmap(gcnew String(image));
		H = character->Height / SzH;
		W = character->Width / SzW;

		delete character;
	}
	virtual void paint(Graphics^ gr) { //clase paint que usamos para imprimir las diversas imagenes y sprites a lo largo de nuestro juego , ya que esta es una clase padre
		Bitmap^ character = gcnew Bitmap(gcnew String(image));
		Rectangle portion = Rectangle(W * IW, H * IH, W, H);
		Rectangle zoom = Rectangle(x, y, W, H);

		gr->DrawImage(character, zoom, portion, GraphicsUnit::Pixel);

		delete character, portion, zoom;
	}
	virtual void trackingBackground(Graphics^ gr, Direction key) { //funcion tranckingBackground que usamos para el movimiento de nuestros objetos y personajes para que asi den la ilusion de que el fondo se mueve y no afecta a nuestros objetos

		if (key == Direction::Right) { x -= dx_tracking; }
		if (key == Direction::Left) { x += dx_tracking; }

		if ((!x + dx + IW > 100) && !(x + dx + IW + W < gr->VisibleClipBounds.Width - 200)) { dx_tracking = 0; }
	}

	//funciones para el salto
	float ecuationJump(float x) { return (jump_height * x * (x - 1)) * 190; } //funcion para calcular nuestro salto

	void jumping() { //funcion que le permite saltar a nuestro personaje
		if (jump) {
			y = (jump_y + jump_recoil) - (int)ecuationJump(jump_x);
			jump_x += 0.1;
			if (jump_x > 1) {
				jump = false;
				jump_x = 0;
				y = jump_y;
			}
		}
	}

	//Colisiones
	Rectangle getCollision() { return Rectangle(x, y, W, H); }

	//metodos de acceso (setter y getter)
	void setDy(short dy) { this->dy = dy; }
	void setY(short y) { this->y = y; }
	void setX(short x) { this->x = x; }
	void setH(short h) { this->H = h; }
	void setW(short w) { this->W = w; }
	void setDx(short dx) { this->dx = dx; }
	void setIH(short ih) { this->IH = ih; }
	void setIW(short iw) { this->IW = iw; }

	void setSzH(short CH) { this->SzH = CH; }
	void setSzW(short CW) { this->SzW = CW; }

	short getDy() { return this->dy; }
	short getX() { return this->x; }
	short getY() { return this->y; }
	short getH() { return this->H; }
	short getW() { return this->W; }
	short getDx() { return this->dx; }
	short getIH() { return this->IH; }
	short getIW() { return this->IW; }
	short getSzH() { return this->SzH; }
	short getSzW() { return this->SzW; }

protected:
	short x, y, dx, dy, H, W, IW, IH, jump_y, jump_recoil, jump_height, dx_tracking;
	float jump_x;
	short SzH, SzW;
	bool jump;
	char* image;
};
