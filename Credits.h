#pragma once

namespace Game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Creditos
	/// </summary>
	public ref class Credits: public System::Windows::Forms::Form
	{
	public:
		Credits(void)
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
		~Credits()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		int cont;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Ravie", 26));
			this->label1->ForeColor = System::Drawing::Color::Lime;
			this->label1->Location = System::Drawing::Point(12, 115);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1052, 59);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Costa Morales, Christofer William";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Ravie", 40));
			this->label2->ForeColor = System::Drawing::Color::Peru;
			this->label2->Location = System::Drawing::Point(12, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(792, 89);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Programadores: ";
			this->label2->Click += gcnew System::EventHandler(this, &Credits::label2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Ravie", 26));
			this->label4->ForeColor = System::Drawing::Color::Lime;
			this->label4->Location = System::Drawing::Point(17, 184);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(829, 59);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Armando Baldeon, Santiago";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Ravie", 26));
			this->label5->ForeColor = System::Drawing::Color::LawnGreen;
			this->label5->Location = System::Drawing::Point(17, 254);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(955, 59);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Miranda Ayasta, Rogger Faryd";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Credits::timer1_Tick);
			// 
			// Creditos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Desktop;
			this->ClientSize = System::Drawing::Size(1123, 391);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Creditos";
			this->Text = L"Creditos";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {//timer usado para cambiar el color de las letras de los creditos
		cont++;
		if (cont == 1)
		{
			label2->ForeColor = Color::LightCyan;
		}
		else if (cont == 2)
		{
			label2->ForeColor = Color::Peru;
		}
		else if (cont == 3)
		{
			label2->ForeColor = Color::Purple;
		}
		else if (cont == 4)
		{
			label2->ForeColor = Color::LightYellow;
		}
		else
		{
			cont = 0;
		}
	}
	};
}
