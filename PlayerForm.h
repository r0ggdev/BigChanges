#pragma once
#include"File.h"
#include"Valid.h"
#include "LevelAnimated1.h"
#include "LevelAnimated2.h"

namespace Game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de PlayerForm
	/// </summary>
	public ref class PlayerForm : public System::Windows::Forms::Form
	{
	public:
		PlayerForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			
			valid = new Valid();
			data = new File();
			wrong = gcnew ErrorProvider();
			wrongIcon = gcnew System::Drawing::Icon(".\\resources\\Icons\\wrong.ico");
			wrong->Icon = wrongIcon;
			
			rdb_men->Select();
			rdb_overweight->Select();
			listBox_activityFactor->SelectedIndex = 0;
			btn_save->Enabled = false;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~PlayerForm()
		{
			if (components)
			{
				delete tbx_age, tbx_height, rdb_men, rdb_obesity1, rdb_obesity2, rdb_obesity3, rdb_overweight;
				delete panel_gender, panel_weight, listBox_activityFactor, btn_save;
				delete components;

				delete data, wrong, wrongIcon, valid;
			}
		}
	private: System::Windows::Forms::TextBox^ tbx_age;
	private: System::Windows::Forms::TextBox^ tbx_height;
	private: System::Windows::Forms::RadioButton^ rdb_men;
	private: System::Windows::Forms::RadioButton^ rdb_girl;
	private: System::Windows::Forms::RadioButton^ rdb_overweight;
	private: System::Windows::Forms::RadioButton^ rdb_obesity1;
	private: System::Windows::Forms::RadioButton^ rdb_obesity2;
	private: System::Windows::Forms::RadioButton^ rdb_obesity3;
	private: System::Windows::Forms::Panel^ panel_gender;
	private: System::Windows::Forms::Panel^ panel_weight;
	private: System::Windows::Forms::ListBox^ listBox_activityFactor;
	private: System::Windows::Forms::Button^ btn_save;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		
		File* data;
		ErrorProvider^ wrong;
		System::Drawing::Icon^ wrongIcon;
		Valid* valid;
	private: System::Windows::Forms::Label^ lbl_info;


		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PlayerForm::typeid));
			this->tbx_age = (gcnew System::Windows::Forms::TextBox());
			this->tbx_height = (gcnew System::Windows::Forms::TextBox());
			this->rdb_men = (gcnew System::Windows::Forms::RadioButton());
			this->rdb_girl = (gcnew System::Windows::Forms::RadioButton());
			this->rdb_overweight = (gcnew System::Windows::Forms::RadioButton());
			this->rdb_obesity1 = (gcnew System::Windows::Forms::RadioButton());
			this->rdb_obesity2 = (gcnew System::Windows::Forms::RadioButton());
			this->rdb_obesity3 = (gcnew System::Windows::Forms::RadioButton());
			this->panel_gender = (gcnew System::Windows::Forms::Panel());
			this->panel_weight = (gcnew System::Windows::Forms::Panel());
			this->listBox_activityFactor = (gcnew System::Windows::Forms::ListBox());
			this->btn_save = (gcnew System::Windows::Forms::Button());
			this->lbl_info = (gcnew System::Windows::Forms::Label());
			this->panel_gender->SuspendLayout();
			this->panel_weight->SuspendLayout();
			this->SuspendLayout();
			// 
			// tbx_age
			// 
			this->tbx_age->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbx_age->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->tbx_age->Location = System::Drawing::Point(526, 144);
			this->tbx_age->MaxLength = 99;
			this->tbx_age->Name = L"tbx_age";
			this->tbx_age->Size = System::Drawing::Size(54, 29);
			this->tbx_age->TabIndex = 0;
			this->tbx_age->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &PlayerForm::tbx_age_KeyPress);
			this->tbx_age->Leave += gcnew System::EventHandler(this, &PlayerForm::tbx_age_Leave);
			// 
			// tbx_height
			// 
			this->tbx_height->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbx_height->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->tbx_height->Location = System::Drawing::Point(584, 234);
			this->tbx_height->MaxLength = 999;
			this->tbx_height->Name = L"tbx_height";
			this->tbx_height->Size = System::Drawing::Size(69, 29);
			this->tbx_height->TabIndex = 1;
			this->tbx_height->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &PlayerForm::tbx_height_KeyPress);
			this->tbx_height->Leave += gcnew System::EventHandler(this, &PlayerForm::tbx_height_Leave);
			// 
			// rdb_men
			// 
			this->rdb_men->AutoSize = true;
			this->rdb_men->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->rdb_men->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->rdb_men->ForeColor = System::Drawing::SystemColors::Highlight;
			this->rdb_men->Location = System::Drawing::Point(3, 0);
			this->rdb_men->Name = L"rdb_men";
			this->rdb_men->Size = System::Drawing::Size(17, 16);
			this->rdb_men->TabIndex = 2;
			this->rdb_men->TabStop = true;
			this->rdb_men->UseVisualStyleBackColor = true;
			// 
			// rdb_girl
			// 
			this->rdb_girl->AutoSize = true;
			this->rdb_girl->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->rdb_girl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->rdb_girl->ForeColor = System::Drawing::SystemColors::Highlight;
			this->rdb_girl->Location = System::Drawing::Point(59, 0);
			this->rdb_girl->Name = L"rdb_girl";
			this->rdb_girl->Size = System::Drawing::Size(17, 16);
			this->rdb_girl->TabIndex = 3;
			this->rdb_girl->TabStop = true;
			this->rdb_girl->UseVisualStyleBackColor = true;
			// 
			// rdb_overweight
			// 
			this->rdb_overweight->AutoSize = true;
			this->rdb_overweight->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->rdb_overweight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rdb_overweight->ForeColor = System::Drawing::SystemColors::Highlight;
			this->rdb_overweight->Location = System::Drawing::Point(2, 1);
			this->rdb_overweight->Name = L"rdb_overweight";
			this->rdb_overweight->Size = System::Drawing::Size(17, 16);
			this->rdb_overweight->TabIndex = 4;
			this->rdb_overweight->TabStop = true;
			this->rdb_overweight->UseVisualStyleBackColor = true;
			// 
			// rdb_obesity1
			// 
			this->rdb_obesity1->AutoSize = true;
			this->rdb_obesity1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->rdb_obesity1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rdb_obesity1->ForeColor = System::Drawing::SystemColors::Highlight;
			this->rdb_obesity1->Location = System::Drawing::Point(82, 3);
			this->rdb_obesity1->Name = L"rdb_obesity1";
			this->rdb_obesity1->Size = System::Drawing::Size(17, 16);
			this->rdb_obesity1->TabIndex = 5;
			this->rdb_obesity1->TabStop = true;
			this->rdb_obesity1->UseVisualStyleBackColor = true;
			// 
			// rdb_obesity2
			// 
			this->rdb_obesity2->AutoSize = true;
			this->rdb_obesity2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->rdb_obesity2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rdb_obesity2->ForeColor = System::Drawing::SystemColors::Highlight;
			this->rdb_obesity2->Location = System::Drawing::Point(164, 3);
			this->rdb_obesity2->Name = L"rdb_obesity2";
			this->rdb_obesity2->Size = System::Drawing::Size(17, 16);
			this->rdb_obesity2->TabIndex = 6;
			this->rdb_obesity2->TabStop = true;
			this->rdb_obesity2->UseVisualStyleBackColor = true;
			// 
			// rdb_obesity3
			// 
			this->rdb_obesity3->AutoSize = true;
			this->rdb_obesity3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->rdb_obesity3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rdb_obesity3->ForeColor = System::Drawing::SystemColors::Highlight;
			this->rdb_obesity3->Location = System::Drawing::Point(251, 3);
			this->rdb_obesity3->Name = L"rdb_obesity3";
			this->rdb_obesity3->Size = System::Drawing::Size(17, 16);
			this->rdb_obesity3->TabIndex = 7;
			this->rdb_obesity3->TabStop = true;
			this->rdb_obesity3->UseVisualStyleBackColor = true;
			// 
			// panel_gender
			// 
			this->panel_gender->BackColor = System::Drawing::Color::Transparent;
			this->panel_gender->Controls->Add(this->rdb_men);
			this->panel_gender->Controls->Add(this->rdb_girl);
			this->panel_gender->Location = System::Drawing::Point(914, 142);
			this->panel_gender->Name = L"panel_gender";
			this->panel_gender->Size = System::Drawing::Size(79, 24);
			this->panel_gender->TabIndex = 8;
			// 
			// panel_weight
			// 
			this->panel_weight->BackColor = System::Drawing::Color::Transparent;
			this->panel_weight->Controls->Add(this->rdb_obesity3);
			this->panel_weight->Controls->Add(this->rdb_overweight);
			this->panel_weight->Controls->Add(this->rdb_obesity1);
			this->panel_weight->Controls->Add(this->rdb_obesity2);
			this->panel_weight->Location = System::Drawing::Point(466, 491);
			this->panel_weight->Name = L"panel_weight";
			this->panel_weight->Size = System::Drawing::Size(276, 24);
			this->panel_weight->TabIndex = 9;
			// 
			// listBox_activityFactor
			// 
			this->listBox_activityFactor->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox_activityFactor->FormattingEnabled = true;
			this->listBox_activityFactor->ItemHeight = 25;
			this->listBox_activityFactor->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Sendetario", L"Ligero", L"Moderado" });
			this->listBox_activityFactor->Location = System::Drawing::Point(791, 259);
			this->listBox_activityFactor->Name = L"listBox_activityFactor";
			this->listBox_activityFactor->Size = System::Drawing::Size(220, 75);
			this->listBox_activityFactor->TabIndex = 10;
			// 
			// btn_save
			// 
			this->btn_save->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_save->Location = System::Drawing::Point(933, 33);
			this->btn_save->Name = L"btn_save";
			this->btn_save->Size = System::Drawing::Size(106, 45);
			this->btn_save->TabIndex = 11;
			this->btn_save->Text = L"Guardar";
			this->btn_save->UseVisualStyleBackColor = true;
			this->btn_save->Click += gcnew System::EventHandler(this, &PlayerForm::btn_save_Click);
			// 
			// lbl_info
			// 
			this->lbl_info->AutoSize = true;
			this->lbl_info->Location = System::Drawing::Point(321, 164);
			this->lbl_info->Name = L"lbl_info";
			this->lbl_info->Size = System::Drawing::Size(43, 25);
			this->lbl_info->TabIndex = 12;
			this->lbl_info->Text = L"info";
			this->lbl_info->Visible = false;
			// 
			// PlayerForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1091, 552);
			this->Controls->Add(this->lbl_info);
			this->Controls->Add(this->btn_save);
			this->Controls->Add(this->listBox_activityFactor);
			this->Controls->Add(this->panel_weight);
			this->Controls->Add(this->panel_gender);
			this->Controls->Add(this->tbx_height);
			this->Controls->Add(this->tbx_age);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::Highlight;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1109, 599);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(1109, 599);
			this->Name = L"PlayerForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Load += gcnew System::EventHandler(this, &PlayerForm::PlayerForm_Load);
			this->panel_gender->ResumeLayout(false);
			this->panel_gender->PerformLayout();
			this->panel_weight->ResumeLayout(false);
			this->panel_weight->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void goLevel() {
			this->Visible = false;
			Game::LevelAnimated1^ level1 = gcnew Game::LevelAnimated1();
			Game::LevelAnimated2^ level2 = gcnew Game::LevelAnimated2();

			switch (data->getLevel())
			{
			case 1:
				this->Close();
				level1->ShowDialog();
				break;
			case 2: 
				this->Close();
				level2->ShowDialog();
				break;
			}

			delete level1, level2;
			this->Visible = true;
		}



	private: System::Void PlayerForm_Load(System::Object^ sender, System::EventArgs^ e) { }
	private: System::Void btn_save_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{	//validamos los datos recibido
			valid->validGender(rdb_men, rdb_girl);
			valid->validWeight(rdb_overweight, rdb_obesity1, rdb_obesity2, rdb_obesity3);
			valid->validLevelFactorActivity(listBox_activityFactor);

			string gender = valid->getGender();
			short age = Convert::ToInt32(tbx_age->Text);
			short height_cm = Convert::ToInt32(tbx_height->Text);

			string gamemood = valid->getMoodGame();
			float pesoA = valid->getWeightNow(height_cm);
			float pesoO = valid->getWeightAim();
			float alturam = (float)height_cm / 100;
			
			string actividad = valid->getActivity();
			float GET = valid->getGETNow(age);
			float GETOBV = valid->getGETAim(age);
			float IMC = valid->getIMC();
			float nuevoGET = GET + GETOBV;
			//los mandamos al archivo con la funcion readData
			data->readData(gender, age, actividad, alturam, gamemood, pesoA, pesoO, GET, nuevoGET, IMC);
			lbl_info->Text = gcnew String(data->showData().c_str());
			MessageBox::Show(gcnew String(data->showData().c_str()), "Datos de jugador", MessageBoxButtons::OK, MessageBoxIcon::Information);
			goLevel();
		}
		catch (FormatException^) { }

	}
	private: System::Void tbx_age_Leave(System::Object^ sender, System::EventArgs^ e) {
		valid->validEmpty(tbx_age, wrong, btn_save);
		valid->validTbx(tbx_age, 15, 60, wrong, "No puede ser menor a 15 ni mayor a 60");
	}
	private: System::Void tbx_height_Leave(System::Object^ sender, System::EventArgs^ e) {
		valid->validEmpty(tbx_height, wrong, btn_save);
		valid->validTbx(tbx_height, 130, 190, wrong, "No puede ser menor a 130 ni mayor a 190");
	}
	private: System::Void tbx_age_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		valid->validNumber(e, tbx_age, wrong);
	}
	private: System::Void tbx_height_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		valid->validNumber(e, tbx_height, wrong);
	}
};
}
