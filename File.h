#pragma once
#include"Header.h"

class File //clase File usada para manejo archivos
{
public:
	File() {}
	~File() {}
	void readData(string gender, short age, string activity, float height, string mode,
		float now_weight, float aim_weight, float now_GET, float aim_GET, float IMC) { //contructor de nuestra clase file donde recibe valores por parametro

		fileRead.open(".\\data.txt", ios::in);
		if (fileRead.fail()) {
			fileRead.close();
			fileWrite.open(".\\data.txt", ios::out);
			fileWrite.close();
		}
		fileWrite.open(".\\data.txt", ios::out);

		fileWrite << "#-#-#-#-#-#- DATOS DEL JUGADOR -#-#-#-#-#-#" << endl << endl;
		fileWrite << "Genero: " << gender << endl << endl;
		fileWrite << "Edad: " << age << " años" << endl << endl;
		fileWrite << "Estatura: " << height << " metros" << endl << endl;
		fileWrite << "Nivel de actividad física: " << activity << endl << endl;
		fileWrite << "Modo de juego: " << mode << endl << endl;
		fileWrite << "Peso actual: " << now_weight << " Kilogramos" << endl << endl;
		fileWrite << "Peso objetivo: " << aim_weight << " Kilogramos" << endl << endl;
		fileWrite << "Gasto Energetico Actual: " << now_GET << " Kcal" << endl << endl;
		fileWrite << "Gasto Energetico Objetivo: " << aim_GET << " Kcal" << endl << endl;
		fileWrite << "IMC: " << IMC << endl << endl;

		fileWrite.close();
		fileRead.open(".\\data.txt", ios::in);
	}

	string showData() { //funcion de nuestra clase file usada para retornarnos la data del reporte ejecutado en el contructor
		text = " ";
		fileRead.open(".\\data.txt", ios::in);
		while (getline(fileRead, line)) {
			text += line + "\n";
		}
		fileRead.close();
		return text;
	}



	void readLevel(short select_level) { //funcion usada para almacenar el nivel que queremos jugar en un archivo
		fileRead.open(".\\level.dat", ios::in);
		if (fileRead.fail()) {
			fileRead.close();
			fileWrite.open(".\\level.dat", ios::out);
			fileWrite.close();
		}
		fileWrite.open(".\\level.dat", ios::out);
		fileWrite << select_level << endl;
		fileWrite.close();
		fileRead.open(".\\level.dat", ios::in);
	}

	//metodos de acceso

	short getLevel() { //funcion usada para obtener el nivel almacenado en el archivo
		fileRead.open(".\\level.dat", ios::in);
		getline(fileRead, line);
		return stoi(line);
	}


	float getGETOBV() { //funcion usada para obtener el numero de gasto energetico objetivo
		float GETOBVValue = 0;
		fileRead.open(".\\data.txt", ios::in);

		while (fileRead >> line) {
			if (line == "Gasto" && (fileRead >> line) && line == "Energetico" && (fileRead >> line) && line == "Objetivo:" && (fileRead >> GETOBVValue)) {
				break;
			}
		}

		fileRead.close();
		return GETOBVValue;
	}


private:
	ofstream fileWrite;
	ifstream fileRead;
	string line, text;
};