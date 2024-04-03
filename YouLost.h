#pragma once

namespace Game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm1
	/// </summary>
	public ref class YouLost: public System::Windows::Forms::Form
	{
	public:
		YouLost(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			cont = 0;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~YouLost()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		int cont;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->SuspendLayout();
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Rockwell", 48, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(139, 135);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(591, 99);
			   this->label1->TabIndex = 1;
			   this->label1->Text = L"): PERDISTE :(";
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Tick += gcnew System::EventHandler(this, &YouLost::timer1_Tick);
			   // 
			   // Lost
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::Gray;
			   this->ClientSize = System::Drawing::Size(888, 400);
			   this->Controls->Add(this->label1);
			   this->Name = L"Loss";
			   this->Text = L" ";
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) { //usado para cambiar de color a las letras de perdiste
		cont++;
		if (cont == 1)
		{
			label1->ForeColor = Color::Black;
		}
		else if (cont == 2)
		{
			label1->ForeColor = Color::DarkRed;
		}
		else if (cont == 3)
		{
			label1->ForeColor = Color::DarkCyan;
		}
		else if (cont == 4)
		{
			label1->ForeColor = Color::DarkKhaki;
		}
		else
		{
			cont = 0;
		}
	}
	};
}
