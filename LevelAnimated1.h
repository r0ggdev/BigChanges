#pragma once
#include "Animation.h"
#include "Level1.h"
namespace Game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de LevelAnimated1
	/// </summary>
	public ref class LevelAnimated1 : public System::Windows::Forms::Form
	{
	public:
		LevelAnimated1(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

			//animation = new Animated();
			a = new Animated();
			tecla = ' ';
			gr = this->CreateGraphics();
			bc = BufferedGraphicsManager::Current;
			bg = bc->Allocate(gr, this->ClientRectangle);
			Timer_Animation->Enabled = true;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~LevelAnimated1()
		{
			if (components)
			{
				delete components;
				delete Timer_Animation, bc, bg;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

		//Animated* animation;

		Graphics^ gr;
		BufferedGraphicsContext^ bc;
		BufferedGraphics^ bg;
		Animated* a;
		char tecla;
	private: System::Windows::Forms::Timer^ Timer_Animation;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->Timer_Animation = (gcnew System::Windows::Forms::Timer(this->components));
			   this->SuspendLayout();
			   // 
			   // Timer_Animation
			   // 
			   this->Timer_Animation->Tick += gcnew System::EventHandler(this, &LevelAnimated1::Timer_Animation_Tick);
			   // 
			   // LevelAnimated1
			   // 
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			   this->ClientSize = System::Drawing::Size(1184, 656);
			   this->MaximizeBox = false;
			   this->MaximumSize = System::Drawing::Size(1200, 695);
			   this->MinimizeBox = false;
			   this->MinimumSize = System::Drawing::Size(1200, 695);
			   this->Name = L"LevelAnimated1";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Animacion del nivel1";
			   this->Load += gcnew System::EventHandler(this, &LevelAnimated1::LevelAnimated1_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &LevelAnimated1::LevelAnimated1_KeyDown);
			   this->ResumeLayout(false);

		   }
#pragma endregion

	private: System::Void Timer_Animation_Tick(System::Object^ sender, System::EventArgs^ e) {//timer usado para la animacion que se proyecta antes del nivel 1
		this->Size = System::Drawing::Size(1190, 650);
		bg->Graphics->Clear(Color::White);
		a->draw(bg->Graphics, 1);
		a->anima(bg->Graphics, 1, tecla);
		bg->Render(gr);
		tecla = 'K';

		if (a->getIdy() >= 2)
		{

			if (a->getIdx() > 4)
			{


				Timer_Animation->Enabled = false;
				this->Close();
				Game::Level1^ lv1 = gcnew Game::Level1;
				this->Visible = false;
				lv1->ShowDialog();
				this->Visible = true;
				delete lv1;
			}



		}
		
	}
	private: System::Void LevelAnimated1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) { //deteccion de la tecla pulsada enter para pasar al siguiente frame de la animacion
		if (e->KeyCode == Keys::Enter) { tecla = 'E';  }


	}
	private: System::Void LevelAnimated1_Load(System::Object^ sender, System::EventArgs^ e) { //cosas realizadas al cargar el formulario , este caso hacer verdadero el timer de la animacion
		Timer_Animation->Enabled = true;
	}
	};
}
