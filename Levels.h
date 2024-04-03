#pragma once
#include"PlayerForm.h"
#include "File.h"

namespace Game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Levels
	/// </summary>
	public ref class Levels : public System::Windows::Forms::Form
	{
	public:
		Levels(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			value_level = new File();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Levels()
		{
			if (components)
			{
				delete components;
				delete btn_level1, btn_level2, value_level;
			}
		}
	private: System::Windows::Forms::Button^ btn_level1;
	protected:
	private: System::Windows::Forms::Button^ btn_level2;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		
		File* value_level;
	private: System::Windows::Forms::Button^ btn_menu;

		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Levels::typeid));
			this->btn_level1 = (gcnew System::Windows::Forms::Button());
			this->btn_level2 = (gcnew System::Windows::Forms::Button());
			this->btn_menu = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_level1
			// 
			this->btn_level1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_level1.BackgroundImage")));
			this->btn_level1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_level1->FlatAppearance->BorderSize = 0;
			this->btn_level1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_level1->Location = System::Drawing::Point(101, 205);
			this->btn_level1->Name = L"btn_level1";
			this->btn_level1->Size = System::Drawing::Size(355, 245);
			this->btn_level1->TabIndex = 0;
			this->btn_level1->UseVisualStyleBackColor = true;
			this->btn_level1->Click += gcnew System::EventHandler(this, &Levels::btn_level1_Click);
			// 
			// btn_level2
			// 
			this->btn_level2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_level2.BackgroundImage")));
			this->btn_level2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_level2->FlatAppearance->BorderSize = 0;
			this->btn_level2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btn_level2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_level2->Location = System::Drawing::Point(619, 205);
			this->btn_level2->Name = L"btn_level2";
			this->btn_level2->Size = System::Drawing::Size(355, 245);
			this->btn_level2->TabIndex = 1;
			this->btn_level2->UseVisualStyleBackColor = true;
			this->btn_level2->Click += gcnew System::EventHandler(this, &Levels::btn_level2_Click);
			// 
			// btn_menu
			// 
			this->btn_menu->BackColor = System::Drawing::Color::Transparent;
			this->btn_menu->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_menu->FlatAppearance->BorderSize = 2;
			this->btn_menu->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->btn_menu->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_menu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_menu->ForeColor = System::Drawing::Color::Teal;
			this->btn_menu->Location = System::Drawing::Point(992, 495);
			this->btn_menu->Name = L"btn_menu";
			this->btn_menu->Size = System::Drawing::Size(87, 35);
			this->btn_menu->TabIndex = 2;
			this->btn_menu->Text = L"Menu";
			this->btn_menu->UseVisualStyleBackColor = false;
			this->btn_menu->Click += gcnew System::EventHandler(this, &Levels::btn_menu_Click);
			// 
			// Levels
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1091, 552);
			this->Controls->Add(this->btn_menu);
			this->Controls->Add(this->btn_level2);
			this->Controls->Add(this->btn_level1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1109, 599);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(1109, 599);
			this->Name = L"Levels";
			this->Text = L"Levels";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btn_level1_Click(System::Object^ sender, System::EventArgs^ e) {
		Game::PlayerForm^ player_form = gcnew PlayerForm();
		this->Visible = false;
		value_level->readLevel(1);
		player_form->ShowDialog();
		this->Close();

		delete player_form;
	}
	private: System::Void btn_level2_Click(System::Object^ sender, System::EventArgs^ e) {
		Game::PlayerForm^ player_form = gcnew PlayerForm();
		this->Visible = false;
		value_level->readLevel(2);
		player_form->ShowDialog();
		this->Close();

		delete player_form;
	}
	private: System::Void btn_menu_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
