#pragma once
#include "ControllerLevel2.h"
#include "Questions.h"
#include"File.h"
#include"YouWin.h"
namespace Game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Level2
	/// </summary>
	public ref class Level2 : public System::Windows::Forms::Form
	{
	public:
		Level2(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

			gr = this->CreateGraphics();
			bc = BufferedGraphicsManager::Current;
			bf = bc->Allocate(gr, this->ClientRectangle);
			ans = false;
			game = new ControllerLevel2();
			TimerGame->Enabled = true;
			addAllies->Enabled = false;
			direction = Direction::None;
			question = gcnew Questions();
			f = new File;
			OBASE = 0;
			OBFIN = 0;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Level2()
		{
			if (components)
			{
				delete components, question;
				delete gr, bc, bf, TimerGame, game, addAllies, Panel_Objective, lbl_objectiveNow, lbl_objectiveAim, direction;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		ControllerLevel2* game;
		Direction direction;
		bool ans;
		Questions^ question;
		Graphics^ gr;
		BufferedGraphicsContext^ bc;
		BufferedGraphics^ bf;
		File* f;
		float OBASE, OBFIN;
	private: System::Windows::Forms::Timer^ TimerGame;
	private: System::Windows::Forms::Panel^ Panel_Objective;
	private: System::Windows::Forms::Label^ lbl_objectiveNow;
	private: System::Windows::Forms::Label^ lbl_objectiveAim;
	private: System::Windows::Forms::Timer^ addAllies;
	private: System::Windows::Forms::Timer^ fin;
	private: System::Windows::Forms::Label^ texto;

	private: System::ComponentModel::IContainer^ components;



#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Level2::typeid));
			   this->TimerGame = (gcnew System::Windows::Forms::Timer(this->components));
			   this->Panel_Objective = (gcnew System::Windows::Forms::Panel());
			   this->lbl_objectiveAim = (gcnew System::Windows::Forms::Label());
			   this->lbl_objectiveNow = (gcnew System::Windows::Forms::Label());
			   this->addAllies = (gcnew System::Windows::Forms::Timer(this->components));
			   this->fin = (gcnew System::Windows::Forms::Timer(this->components));
			   this->texto = (gcnew System::Windows::Forms::Label());
			   this->Panel_Objective->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // TimerGame
			   // 
			   this->TimerGame->Tick += gcnew System::EventHandler(this, &Level2::TimerGame_Tick);
			   // 
			   // Panel_Objective
			   // 
			   this->Panel_Objective->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
				   static_cast<System::Int32>(static_cast<System::Byte>(141)));
			   this->Panel_Objective->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Panel_Objective.BackgroundImage")));
			   this->Panel_Objective->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			   this->Panel_Objective->Controls->Add(this->lbl_objectiveAim);
			   this->Panel_Objective->Controls->Add(this->lbl_objectiveNow);
			   this->Panel_Objective->Location = System::Drawing::Point(12, 12);
			   this->Panel_Objective->Name = L"Panel_Objective";
			   this->Panel_Objective->Size = System::Drawing::Size(278, 27);
			   this->Panel_Objective->TabIndex = 0;
			   // 
			   // lbl_objectiveAim
			   // 
			   this->lbl_objectiveAim->AutoSize = true;
			   this->lbl_objectiveAim->BackColor = System::Drawing::Color::Transparent;
			   this->lbl_objectiveAim->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Pixel,
				   static_cast<System::Byte>(0)));
			   this->lbl_objectiveAim->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
				   static_cast<System::Int32>(static_cast<System::Byte>(141)));
			   this->lbl_objectiveAim->Location = System::Drawing::Point(217, 5);
			   this->lbl_objectiveAim->Name = L"lbl_objectiveAim";
			   this->lbl_objectiveAim->Size = System::Drawing::Size(35, 17);
			   this->lbl_objectiveAim->TabIndex = 1;
			   this->lbl_objectiveAim->Text = L"900";
			   // 
			   // lbl_objectiveNow
			   // 
			   this->lbl_objectiveNow->AutoSize = true;
			   this->lbl_objectiveNow->BackColor = System::Drawing::Color::Transparent;
			   this->lbl_objectiveNow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Pixel,
				   static_cast<System::Byte>(0)));
			   this->lbl_objectiveNow->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
				   static_cast<System::Int32>(static_cast<System::Byte>(141)));
			   this->lbl_objectiveNow->Location = System::Drawing::Point(140, 5);
			   this->lbl_objectiveNow->Name = L"lbl_objectiveNow";
			   this->lbl_objectiveNow->Size = System::Drawing::Size(17, 17);
			   this->lbl_objectiveNow->TabIndex = 0;
			   this->lbl_objectiveNow->Text = L"0";
			   // 
			   // addAllies
			   // 
			   this->addAllies->Interval = 1000;
			   this->addAllies->Tick += gcnew System::EventHandler(this, &Level2::addAllies_Tick);
			   // 
			   // fin
			   // 
			   this->fin->Tick += gcnew System::EventHandler(this, &Level2::fin_Tick);
			   // 
			   // texto
			   // 
			   this->texto->AutoSize = true;
			   this->texto->Font = (gcnew System::Drawing::Font(L"Ravie", 26));
			   this->texto->ForeColor = System::Drawing::Color::Black;
			   this->texto->Location = System::Drawing::Point(210, 522);
			   this->texto->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->texto->Name = L"texto";
			   this->texto->Size = System::Drawing::Size(744, 48);
			   this->texto->TabIndex = 1;
			   this->texto->Text = L"Presiona enter para continuar";
			   // 
			   // Level2
			   // 
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			   this->ClientSize = System::Drawing::Size(1184, 656);
			   this->Controls->Add(this->texto);
			   this->Controls->Add(this->Panel_Objective);
			   this->MaximizeBox = false;
			   this->MaximumSize = System::Drawing::Size(1200, 695);
			   this->MinimizeBox = false;
			   this->MinimumSize = System::Drawing::Size(1200, 695);
			   this->Name = L"Level2";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Level2";
			   this->Activated += gcnew System::EventHandler(this, &Level2::Level2_Activated);
			   this->Deactivate += gcnew System::EventHandler(this, &Level2::Level2_Deactivate);
			   this->Load += gcnew System::EventHandler(this, &Level2::Level2_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Level2::Level2_KeyDown);
			   this->Panel_Objective->ResumeLayout(false);
			   this->Panel_Objective->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void Level2_Load(System::Object^ sender, System::EventArgs^ e) {//incializacion de nuestro formulario
		//definimos el numero de gasto energetico Objetivo
		lbl_objectiveAim->Text = Convert::ToString(f->getGETOBV());
		OBFIN = f->getGETOBV();
		OBASE = f->getGETOBV(); 
		texto->Visible = false;

	}


	private: System::Void TimerGame_Tick(System::Object^ sender, System::EventArgs^ e) { //timer principal de la ejecucion de nuestro juego
		Random r;
		//spawneamos un objeto Clock aleatoriamente
		if (r.Next(1, 101) == 77) {
			if (!(game->getClockAct()))game->addClock();
		}
		//comprobacion de si se realizo la pregunta y asi aumentar o restar la cantidad de proyectiles recolectados
		game->resetTimer(addAllies, TimerGame, question);
		if (game->getVerification()) {
			ans = question->GetVerifyAns();
			if (ans)
			{
				game->addPeasC();
				
				
			}
			else
			{
				game->resetPeas();
				
			}
		}
		//comprobar colision con el boss para resetear las peas o proyectiles recolectados
		if (game->getColisionE()){game->resetPeas();
	}

		//imprimir el numero de gasto objetivo ya alcanzado en el nivel anterior
		lbl_objectiveNow->Text = Convert::ToString(OBASE);
		
		if (!(game->getAliveEnemy()))texto->Visible = true;
		

		//pintar todos los objetos
		game->paintEverything(bf->Graphics, direction);
		game->powerPeasCharacter();
		direction = Direction::None;
		bf->Render(gr);
	}

	private: System::Void Level2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) { //deteccion de la tecla pulsada
		if (e->KeyCode == Keys::D) { direction = Direction::Right; }
		if (e->KeyCode == Keys::A) { direction = Direction::Left; }
		if (e->KeyCode == Keys::Space) { direction = Direction::Space; }
		if (e->KeyCode == Keys::E) { game->addPeas(); }
		if (e->KeyCode == Keys::Enter) { if (!(game->getAliveEnemy())) { fin->Enabled = true; } }
	}

	private: System::Void addAllies_Tick(System::Object^ sender, System::EventArgs^ e) { //timer para la generacion de aliados
		game->addAllies();
	}

	private: System::Void Level2_Activated(System::Object^ sender, System::EventArgs^ e) {//usado para desactivar el timer principal de juego del nivel 2
		TimerGame->Enabled = true;
	}

	private: System::Void Level2_Deactivate(System::Object^ sender, System::EventArgs^ e) { //usado para desactivar los timer del nivel 2 y este se pause
		TimerGame->Enabled = false;
		addAllies->Enabled = false;
	}
	private: System::Void fin_Tick(System::Object^ sender, System::EventArgs^ e) { //timer que se activa cuando se finaliza el nivel para mostrar la pantalla de ganaste
		TimerGame->Enabled = false;
		addAllies->Enabled = false;
		fin->Enabled = false;
		this->Close();
		Game::Win^ w = gcnew Game::Win;
		this->Visible = false;
		w->ShowDialog();
		this->Visible = true;
	}
};
}