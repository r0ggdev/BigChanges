#pragma once
#include"Header.h"

namespace Game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Questions
	/// </summary>
	public ref class Questions : public System::Windows::Forms::Form
	{
	public:
		
		Questions(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			value_A = value_B = value_AB = designed_Operator = 0;
			value_Operator = ' ';
			operations = " ";
			timer = 40;
			srand(time(NULL));
		}
		bool GetVerifyAns() {
			return verifyAns;
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Questions()
		{
			if (components)
			{
				delete components;
				delete label1, value_A, value_B, value_AB, designed_Operator, timer, lbl_operation, btn_valid;
				delete operations, value_Operator;
			}
		}

	protected:

	protected:

	private: System::Windows::Forms::Label^ lbl_operation;
	private: System::Windows::Forms::Button^ btn_valid;
	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

		short value_A, value_B, value_AB, designed_Operator, timer;
		char value_Operator;
		String^ operations;
		bool verifyAns;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ Time_Answer;
	private: System::Windows::Forms::TextBox^ tbx_answer;


	private: System::ComponentModel::IContainer^ components;



#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->lbl_operation = (gcnew System::Windows::Forms::Label());
			   this->btn_valid = (gcnew System::Windows::Forms::Button());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->Time_Answer = (gcnew System::Windows::Forms::Timer(this->components));
			   this->tbx_answer = (gcnew System::Windows::Forms::TextBox());
			   this->SuspendLayout();
			   // 
			   // lbl_operation
			   // 
			   this->lbl_operation->AutoSize = true;
			   this->lbl_operation->Location = System::Drawing::Point(125, 107);
			   this->lbl_operation->Name = L"lbl_operation";
			   this->lbl_operation->Size = System::Drawing::Size(25, 13);
			   this->lbl_operation->TabIndex = 2;
			   this->lbl_operation->Text = L"2+2";
			   // 
			   // btn_valid
			   // 
			   this->btn_valid->Location = System::Drawing::Point(58, 194);
			   this->btn_valid->Name = L"btn_valid";
			   this->btn_valid->Size = System::Drawing::Size(162, 65);
			   this->btn_valid->TabIndex = 3;
			   this->btn_valid->Text = L"Valida";
			   this->btn_valid->UseVisualStyleBackColor = true;
			   this->btn_valid->Click += gcnew System::EventHandler(this, &Questions::btn_valid_Click);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(109, 80);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(63, 13);
			   this->label1->TabIndex = 4;
			   this->label1->Text = L"QUESTION";
			   
			   // 
			   // tbx_answer
			   // 
			   this->tbx_answer->Location = System::Drawing::Point(58, 143);
			   this->tbx_answer->Name = L"tbx_answer";
			   this->tbx_answer->Size = System::Drawing::Size(162, 20);
			   this->tbx_answer->TabIndex = 5;
			   // 
			   // Questions
			   // 
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			   this->ClientSize = System::Drawing::Size(304, 332);
			   this->Controls->Add(this->tbx_answer);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->btn_valid);
			   this->Controls->Add(this->lbl_operation);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->MaximizeBox = false;
			   this->MaximumSize = System::Drawing::Size(304, 332);
			   this->MinimizeBox = false;
			   this->MinimumSize = System::Drawing::Size(304, 332);
			   this->Name = L"Questions";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			   this->Text = L"Question";
			   this->Load += gcnew System::EventHandler(this, &Questions::Questions_Load);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

		   void randomOperation() {//Funcion usada para generar una operacion matematica aleatoria
			   designed_Operator = 1 + rand() % (3 + 1 - 1);
			   do {
				   value_A = 10 + rand() % (60 + 1 - 10);
				   value_B = 10 + rand() % (60 + 1 - 10);

				   switch (designed_Operator) {
				   case 1: value_Operator = '+'; value_AB = value_A + value_B; break;
				   case 2: value_Operator = '-'; value_AB = value_A - value_B; break;
				   case 3: value_Operator = 'x';

					   value_A = 2 + rand() % (12 + 1 - 2);
					   value_B = 2 + rand() % (12 + 1 - 2);

					   value_AB = value_A * value_B;
					   break;

				   case 4: value_Operator = '/'; value_AB = value_A / value_B; break;
				   }

			   } while (value_B != 0 && value_A % value_B != 0);

			   operations = operations->Concat((char)value_A, " ", Convert::ToChar(value_Operator), " ", (char)value_B);
		   }

	private: System::Void Questions_Load(System::Object^ sender, System::EventArgs^ e) { //acciones realizadas una vez cargado el formulario
		Time_Answer->Enabled = true;
		randomOperation();
		lbl_operation->Text = operations;
	}
	private: System::Void btn_valid_Click(System::Object^ sender, System::EventArgs^ e) { //boton usado para validar la respues introducida
		short answer = Convert::ToInt16(tbx_answer->Text);
		answer == value_AB ? verifyAns = true : verifyAns = false;
		this->Close();

	}
	
	};
}
