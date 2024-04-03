#pragma once
#include"LevelAnimated2.h"
#include "ControllerLevel1.h"
#include"LevelAnimated2.h"
#include "YouLost.h"
#include"Questions.h"
#include"File.h"
#include"Animation.h"
#include<fstream>
namespace Game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class Level1 : public System::Windows::Forms::Form
	{
	public:
		Level1(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			gr = this->CreateGraphics();
			bc = BufferedGraphicsManager::Current;
			bf = bc->Allocate(gr, this->ClientRectangle);
			game = new ControllerLevel1();
			a = new Animated();
			TimerGame->Enabled = true;
			ans = false;
			direccion = Direction::None;
			messageview = false;
			question = gcnew Questions();
			f = new File();
			cont = 0;
			OBASE = 200;
			OBFIN = 1000;

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Level1()
		{
			if (components)
			{
				delete components;

				delete gr, bc, bf, game;

			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		ControllerLevel1* game;
		Direction direccion;
		Graphics^ gr;
		BufferedGraphicsContext^ bc;
		BufferedGraphics^ bf;
		int cont;
		bool messageview,ans;
		float OBASE;
		float OBFIN;
		ifstream* read;
		Animated* a;
		File* f;
		Questions^ question;
	private: System::Windows::Forms::Timer^ TimerGame;
	private: System::Windows::Forms::Panel^ PanelCount;
	private: System::Windows::Forms::Label^ lbl_obFin;





	private: System::Windows::Forms::Timer^ Timer_Enemys;

	private: System::Windows::Forms::Label^ lbl_obBase;
	private: System::Windows::Forms::Label^ contWater;







	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Level1::typeid));
			   this->TimerGame = (gcnew System::Windows::Forms::Timer(this->components));
			   this->PanelCount = (gcnew System::Windows::Forms::Panel());
			   this->lbl_obBase = (gcnew System::Windows::Forms::Label());
			   this->lbl_obFin = (gcnew System::Windows::Forms::Label());
			   this->Timer_Enemys = (gcnew System::Windows::Forms::Timer(this->components));
			   this->contWater = (gcnew System::Windows::Forms::Label());
			   this->PanelCount->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // TimerGame
			   // 
			   this->TimerGame->Tick += gcnew System::EventHandler(this, &Level1::TimerGame_Tick);
			   // 
			   // PanelCount
			   // 
			   this->PanelCount->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PanelCount.BackgroundImage")));
			   this->PanelCount->Controls->Add(this->lbl_obBase);
			   this->PanelCount->Controls->Add(this->lbl_obFin);
			   this->PanelCount->Location = System::Drawing::Point(12, 20);
			   this->PanelCount->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->PanelCount->Name = L"PanelCount";
			   this->PanelCount->Size = System::Drawing::Size(280, 27);
			   this->PanelCount->TabIndex = 0;
			   // 
			   // lbl_obBase
			   // 
			   this->lbl_obBase->AutoSize = true;
			   this->lbl_obBase->BackColor = System::Drawing::Color::Transparent;
			   this->lbl_obBase->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 10.2F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->lbl_obBase->Location = System::Drawing::Point(135, 5);
			   this->lbl_obBase->Name = L"lbl_obBase";
			   this->lbl_obBase->Size = System::Drawing::Size(15, 18);
			   this->lbl_obBase->TabIndex = 1;
			   this->lbl_obBase->Text = L"0";
			   // 
			   // lbl_obFin
			   // 
			   this->lbl_obFin->AutoSize = true;
			   this->lbl_obFin->BackColor = System::Drawing::Color::Transparent;
			   this->lbl_obFin->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 10.2F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->lbl_obFin->Location = System::Drawing::Point(212, 5);
			   this->lbl_obFin->Name = L"lbl_obFin";
			   this->lbl_obFin->Size = System::Drawing::Size(36, 18);
			   this->lbl_obFin->TabIndex = 2;
			   this->lbl_obFin->Text = L"1000";
			   // 
			   // Timer_Enemys
			   // 
			   this->Timer_Enemys->Enabled = true;
			   this->Timer_Enemys->Interval = 500;
			   this->Timer_Enemys->Tick += gcnew System::EventHandler(this, &Level1::Timer_Enemys_Tick);
			   // 
			   // contWater
			   // 
			   this->contWater->AutoSize = true;
			   this->contWater->BackColor = System::Drawing::Color::Transparent;
			   this->contWater->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 10.2F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->contWater->Location = System::Drawing::Point(224, 59);
			   this->contWater->Name = L"contWater";
			   this->contWater->Size = System::Drawing::Size(15, 18);
			   this->contWater->TabIndex = 3;
			   this->contWater->Text = L"0";
			   // 
			   // Level1
			   // 
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			   this->ClientSize = System::Drawing::Size(1183, 651);
			   this->Controls->Add(this->contWater);
			   this->Controls->Add(this->PanelCount);
			   this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->MaximizeBox = false;
			   this->MaximumSize = System::Drawing::Size(1200, 690);
			   this->MinimizeBox = false;
			   this->MinimumSize = System::Drawing::Size(1199, 690);
			   this->Name = L"Level1";
			   this->Text = L"MyForm";
			   this->Load += gcnew System::EventHandler(this, &Level1::Level1_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Level1::Level1_KeyDown);
			   this->PanelCount->ResumeLayout(false);
			   this->PanelCount->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void Level1_Load(System::Object^ sender, System::EventArgs^ e) {  //inicializacion de nuestro formulario
		//añadimos las botellas de agua y los implementos de GYM
		game->addWater();
		game->addGymImplements();
		//seteamos nuestro numero objetivo
		OBFIN = f->getGETOBV();
		lbl_obFin->Text = Convert::ToString(f->getGETOBV());
		OBASE = 200;
		

	}

	private: System::Void TimerGame_Tick(System::Object^ sender, System::EventArgs^ e) { //timer pincipal de la ejecucion de nuestro juego

		Random r;
		
		game->paint(bf->Graphics, direccion);
		game->resetTimer(Timer_Enemys, TimerGame, question);
		//comprobamos si se realizo la pregunta para pedir si la respuesta fue correcta o no , en base a eso sumar o restar puntos
		if (game->getVerification()) {
			ans = question->GetVerifyAns();
			if (ans)
			{
				OBASE += 100;
			}
			else
			{
				OBASE -= 100;
			}
		}
		//aumento de nuestro numero actual en base al movimiento del personaje
		if (direccion == Direction::Left || direccion == Direction::Right)
		{
			OBASE += 3;
		}

		//colisiones para descuentos o sumas de puntos
		if (game->collisionWater()) {
			OBASE += 100;

		}
		if (game->collisionGym()) { OBASE += 100; }
		if (game->collisionEnemy() > 0) {
			OBASE = OBASE - (100 * game->collisionEnemy());

		}
		//imprimir nuevo numero de gasto energetico objetivo y gasto energetico actual
		contWater->Text = Convert::ToString(game->getCWater());
		lbl_obBase->Text = Convert::ToString(OBASE);

		//añade un objeto clock al azar
		if (r.Next(1,101)==77) {
			if(!(game->getClockAct()))game->addClock();
		}


		direccion = Direction::None;

		game->endEnemys();
		//comprueba si el perdiste para mostrarte la pantalla de perdiste
		if (game->endGame(OBASE) && !messageview) {
			messageview = true; TimerGame->Enabled = false;
			this->Close();
			Game::YouLost^ l = gcnew Game::YouLost;
			this->Visible = false;
			l->ShowDialog();
			this->Visible = true;
		}


		bf->Render(gr);

		//comprueba si ganaste para pasar al nivel 2
		if (game->couterWater() && OBASE > OBFIN)
		{
			TimerGame->Enabled = false;
			this->Visible = false;
			
			Game::LevelAnimated2^ level2 = gcnew Game::LevelAnimated2();

			
				this->Close();
				level2->ShowDialog();
			
			delete level2;
			this->Visible = true;
		}

	}
	private: System::Void Level1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) { //usado para detectar el presionado de las teclas
		if (e->KeyCode == Keys::D) { direccion = Direction::Right; }
		if (e->KeyCode == Keys::A) { direccion = Direction::Left; }

	}

	private: System::Void Timer_Enemys_Tick(System::Object^ sender, System::EventArgs^ e) { //timer usado para la generacion de enemigos
		game->addEnemys();
	}

	};
}

