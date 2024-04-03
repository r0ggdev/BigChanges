#pragma once
#include"Header.h"

class Valid //clase usada para validar datos
{
public:
	Valid() { //contructor donde se inician la variables
		this->age = this->HeigthCm = this->gender = this->IMC = this->LFA = this->weightNow = this->weightAim = this->GET = 0;
		this->genderStr = this->moodGame = this->activity = " ";
	}
	~Valid() { }

	void validNumber(KeyPressEventArgs^ e, TextBox^ tbx, ErrorProvider^ wrong) { //valida si el numero introducido es valido
		if (!Char::IsNumber(e->KeyChar) && e->KeyChar != 8) {
			e->Handled = true;
			wrong->Clear();
			wrong->SetError(tbx, "Ingrese valor valido");
		}
		else {
			e->Handled = false;
		}
	}
	void validEmpty(TextBox^ tbx, ErrorProvider^ wrong, Button^ btn_start) { //valida si la casilla fue llenada
		if (tbx->Text == String::Empty) {
			wrong->SetError(tbx, "No puede estar vacio");
			btn_start->Enabled = false;
		}
		else
		{
			wrong->Clear();
			btn_start->Enabled = true;
		}
	}
	void validTbx(TextBox^ tbx, short valueMin, short valueMax, ErrorProvider^ wrong, String^ error) { //valida el textbox si fue introduccido un valor valido
		try {
			short value = Convert::ToInt32(tbx->Text);
			if (value < valueMin || value > valueMax) {
				wrong->SetError(tbx, error);
				tbx->Text = "";
			}
			else { wrong->Clear(); }
		}
		catch (FormatException^) { wrong->SetError(tbx, "Ingrese valor valido"); }
	}

	void validWeight(RadioButton^ rdb1, RadioButton^ rdb2, RadioButton^ rdb3, RadioButton^ rdb4) { //valida el peso y determina el grado de obesidad
		Random r;
		if (rdb1->Checked) { IMC = r.Next(25, 29.95); moodGame = "sobrepeso"; }
		else if (rdb2->Checked) { IMC = r.Next(30, 34.95); moodGame = "Obesidad I"; }
		else if (rdb3->Checked) { IMC = r.Next(35, 39.95); moodGame = "Obesidad II"; }
		else if (rdb4->Checked) { IMC = r.Next(40, 120.9); moodGame = "Obesidad III"; }
	}
	void validGender(RadioButton^ rdb1, RadioButton^ rdb2) { //valida el genero introducido
		if (rdb1->Checked) {
			gender = 1;
			genderStr = "Masculino";
			validaimage = true;

		}
		else if (rdb2->Checked) {
			gender = 0;
			genderStr = "Femenino";
			validaimage = false;
		}


	}
	void validLevelFactorActivity(ListBox^ list1) { //valida el valor de actividad introducido
		if (list1->SelectedIndex == 0) { LFA = 1.2; activity = "Sedentario"; }
		else if (list1->SelectedIndex == 1) { LFA = 1.375; activity = "Ligero"; }
		else if (list1->SelectedIndex == 2) { LFA = 1.725; activity = "Moderado"; }
	}

	float getWeightNow(short heigthCm) { //valida si es correcto el peso actual
		weightNow = (float)Math::Round(IMC * Math::Pow((float)heigthCm / 100, 2), 2);
		return weightNow;
	}
	float getWeightAim() { //valida si es correcti el peso objetivo
		weightAim = weightNow - (0.05 * weightNow);
		return weightAim;
	}

	float getGETNow(short age) { //valida si es correcto el gasto energetico actual
		float TMB = (10 * weightNow) + (6, 25 * HeigthCm) - (5 * age);
		if (gender == 1) { TMB + 5; }
		else { TMB - 161; }

		return (TMB * LFA) + (TMB * 0.3);
	}
	float getGETAim(short age) {//valida si es correcto el gasto energetico objetivo
		float TMB = (10 * weightAim) + (6, 25 * HeigthCm) - (5 * age);
		if (gender == 1) { TMB + 5; }
		else { TMB - 161; }

		return (TMB * LFA) + (TMB * 0.3);
	}

	void validImage(PictureBox^ image) { //valida si la imagen introducida es correcta
		gender == 1 ? image->Image = Image::FromFile("iamge1.png") : image->Image = Image::FromFile("image.jpg");
	}
	
	//metodos de acceso
	float getIMC() { return IMC; }
	string getGender() { return this->genderStr; }
	string getMoodGame() { return this->moodGame; }
	string getActivity() { return this->activity; }

private:
	short age, HeigthCm, gender;
	float  IMC, LFA, weightNow, weightAim, GET, heigthm;
	string genderStr, moodGame, activity;
	bool validaimage;
};