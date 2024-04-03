#pragma once
#include"Level2.h"
#include"Animation.h"
namespace Game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de LevelAnimated2
	/// </summary>
	public ref class LevelAnimated2 : public System::Windows::Forms::Form
	{
	public:
		LevelAnimated2(void)
		{
			InitializeComponent();
			a = new Animated();
			tecla = ' ';
			gr = this->CreateGraphics();
			bc = BufferedGraphicsManager::Current;
			bg = bc->Allocate(gr, this->ClientRectangle);
		
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~LevelAnimated2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Graphics^ gr;
		BufferedGraphicsContext^ bc;
		BufferedGraphics^ bg;
		Animated* a;
		char tecla;
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &LevelAnimated2::timer1_Tick);
			// 
			// LevelAnimated2
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1184, 656);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1200, 695);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(1200, 695);
			this->Name = L"LevelAnimated2";
			this->Text = L"Animacion Nivel 2";
			this->Load += gcnew System::EventHandler(this, &LevelAnimated2::LevelAnimated2_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &LevelAnimated2::LevelAnimated2_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void LevelAnimated2_Load(System::Object^ sender, System::EventArgs^ e) {//acciones realizada al cargar el formulario
		timer1->Enabled = true;
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) { //timer principal usado en la animacion
		this->Size = System::Drawing::Size(1190, 650);
		bg->Graphics->Clear(Color::White);
		a->draw(bg->Graphics, 2);
		a->anima(bg->Graphics, 2, tecla);
		bg->Render(gr);
		tecla = 'K';

		if (a->getIdy() >= 3)
		{

			if (a->getIdx() >= 5)
			{


				timer1->Enabled = false;
				this->Close();
				Game::Level2^ lv2 = gcnew Game::Level2;
				this->Visible = false;
				lv2->ShowDialog();
				this->Visible = true;
				delete lv2;
			}



		}
		

	}
	private: System::Void LevelAnimated2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) { //deteccion de tecla pulsada para pasar al siguiente frame de la animacion
		if (e->KeyCode == Keys::Enter)
		{
			tecla = 'E';

		}

	}

	
	};
}
