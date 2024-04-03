#pragma once
#include "Instruccions.h"
#include "Credits.h"
#include "Levels.h"
#include "PlayerForm.h"
#include "File.h"
namespace Game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de StartMenu
	/// </summary>
	public ref class StartMenu : public System::Windows::Forms::Form
	{
	public:
		StartMenu(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			select_level = new File();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~StartMenu()
		{
			if (components)
			{
				delete components, btn_credits, btn_instructions, btn_start, btn_levels;
				delete select_level;
			}
		}
	private: System::Windows::Forms::Button^ btn_start;
	private: System::Windows::Forms::Button^ btn_instructions;
	private: System::Windows::Forms::Button^ btn_credits;
	private: System::Windows::Forms::Button^ btn_levels;
	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		File* select_level;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StartMenu::typeid));
			this->btn_start = (gcnew System::Windows::Forms::Button());
			this->btn_instructions = (gcnew System::Windows::Forms::Button());
			this->btn_credits = (gcnew System::Windows::Forms::Button());
			this->btn_levels = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_start
			// 
			this->btn_start->BackColor = System::Drawing::Color::Transparent;
			this->btn_start->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_start->FlatAppearance->BorderSize = 0;
			this->btn_start->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(4)),
				static_cast<System::Int32>(static_cast<System::Byte>(167)), static_cast<System::Int32>(static_cast<System::Byte>(175)));
			this->btn_start->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_start->ForeColor = System::Drawing::Color::White;
			this->btn_start->Location = System::Drawing::Point(489, 285);
			this->btn_start->Name = L"btn_start";
			this->btn_start->Size = System::Drawing::Size(170, 34);
			this->btn_start->TabIndex = 0;
			this->btn_start->Text = L"Empezar";
			this->btn_start->UseVisualStyleBackColor = false;
			this->btn_start->Click += gcnew System::EventHandler(this, &StartMenu::btn_start_Click);
			// 
			// btn_instructions
			// 
			this->btn_instructions->BackColor = System::Drawing::Color::Transparent;
			this->btn_instructions->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_instructions->FlatAppearance->BorderSize = 0;
			this->btn_instructions->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(4)),
				static_cast<System::Int32>(static_cast<System::Byte>(167)), static_cast<System::Int32>(static_cast<System::Byte>(175)));
			this->btn_instructions->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_instructions->ForeColor = System::Drawing::Color::White;
			this->btn_instructions->Location = System::Drawing::Point(351, 361);
			this->btn_instructions->Name = L"btn_instructions";
			this->btn_instructions->Size = System::Drawing::Size(145, 33);
			this->btn_instructions->TabIndex = 1;
			this->btn_instructions->Text = L"Instrucciones";
			this->btn_instructions->UseVisualStyleBackColor = false;
			this->btn_instructions->Click += gcnew System::EventHandler(this, &StartMenu::btn_instructions_Click);
			// 
			// btn_credits
			// 
			this->btn_credits->BackColor = System::Drawing::Color::Transparent;
			this->btn_credits->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_credits->FlatAppearance->BorderSize = 0;
			this->btn_credits->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(4)),
				static_cast<System::Int32>(static_cast<System::Byte>(167)), static_cast<System::Int32>(static_cast<System::Byte>(175)));
			this->btn_credits->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_credits->ForeColor = System::Drawing::Color::White;
			this->btn_credits->Location = System::Drawing::Point(607, 363);
			this->btn_credits->Name = L"btn_credits";
			this->btn_credits->Size = System::Drawing::Size(167, 31);
			this->btn_credits->TabIndex = 2;
			this->btn_credits->Text = L"Creditos";
			this->btn_credits->UseVisualStyleBackColor = false;
			this->btn_credits->Click += gcnew System::EventHandler(this, &StartMenu::btn_credits_Click);
			// 
			// btn_levels
			// 
			this->btn_levels->BackColor = System::Drawing::Color::Transparent;
			this->btn_levels->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_levels->FlatAppearance->BorderSize = 0;
			this->btn_levels->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(4)),
				static_cast<System::Int32>(static_cast<System::Byte>(167)), static_cast<System::Int32>(static_cast<System::Byte>(175)));
			this->btn_levels->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_levels->ForeColor = System::Drawing::Color::White;
			this->btn_levels->Location = System::Drawing::Point(458, 446);
			this->btn_levels->Name = L"btn_levels";
			this->btn_levels->Size = System::Drawing::Size(165, 30);
			this->btn_levels->TabIndex = 3;
			this->btn_levels->Text = L"Niveles";
			this->btn_levels->UseVisualStyleBackColor = false;
			this->btn_levels->Click += gcnew System::EventHandler(this, &StartMenu::btn_levels_Click);
			// 
			// StartMenu
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1091, 552);
			this->Controls->Add(this->btn_levels);
			this->Controls->Add(this->btn_credits);
			this->Controls->Add(this->btn_instructions);
			this->Controls->Add(this->btn_start);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1109, 599);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(1109, 599);
			this->Name = L"StartMenu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"StartMenu";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btn_start_Click(System::Object^ sender, System::EventArgs^ e) { //boton usado para ir directamente al nivel 1 y jugar la aventura en orden
		select_level->readLevel(1);
		Game::PlayerForm^ player_form = gcnew PlayerForm();
		this->Visible = false;
		player_form->ShowDialog();
		this->Visible = true;

		delete player_form;
	}
	private: System::Void btn_instructions_Click(System::Object^ sender, System::EventArgs^ e) { //boton que nos lleva al formulario de instrucciones
		Game::Instruccions^ instruccion = gcnew Instruccions();
		this->Visible = false;
		instruccion->ShowDialog();
		this->Visible = true;

		delete instruccion;
	}
	private: System::Void btn_credits_Click(System::Object^ sender, System::EventArgs^ e) { //boton que nos lleva al formulario de creditos
		Game::Credits^ credits = gcnew Credits();
		this->Visible = false;
		credits->ShowDialog();
		this->Visible = true;

		delete credits;
	}
	private: System::Void btn_levels_Click(System::Object^ sender, System::EventArgs^ e) { //boton para seleccionar el nivel a jugar
		Game::Levels^ level = gcnew Levels();
		this->Visible = false;
		level->ShowDialog();
		this->Visible = true;

		delete level;
	}
};
}
