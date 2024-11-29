#pragma once
#include "MyForm.h"
#include "Registros.h"
namespace JuegoDragones {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	/// <summary>
	/// Resumen de Presentacion
	/// </summary>
	public ref class Presentacion : public System::Windows::Forms::Form
	{
	public:
		Presentacion(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			music = gcnew SoundPlayer("musica/musicaa.wav");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Presentacion()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		SoundPlayer^ music;
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btn_jugar;

	private: System::Windows::Forms::Button^ btn_registros;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
		  
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Presentacion::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->btn_jugar = (gcnew System::Windows::Forms::Button());
			this->btn_registros = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-1, -2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(846, 692);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(295, 272);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(279, 41);
			this->textBox1->TabIndex = 8;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btn_jugar
			// 
			this->btn_jugar->BackColor = System::Drawing::SystemColors::ControlDark;
			this->btn_jugar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_jugar->Location = System::Drawing::Point(470, 362);
			this->btn_jugar->Name = L"btn_jugar";
			this->btn_jugar->Size = System::Drawing::Size(158, 59);
			this->btn_jugar->TabIndex = 2;
			this->btn_jugar->Text = L"JUGAR";
			this->btn_jugar->UseVisualStyleBackColor = false;
			this->btn_jugar->Click += gcnew System::EventHandler(this, &Presentacion::btn_jugar_Click);
			// 
			// btn_registros
			// 
			this->btn_registros->BackColor = System::Drawing::SystemColors::ControlDark;
			this->btn_registros->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_registros->Location = System::Drawing::Point(246, 362);
			this->btn_registros->Name = L"btn_registros";
			this->btn_registros->Size = System::Drawing::Size(165, 59);
			this->btn_registros->TabIndex = 3;
			this->btn_registros->Text = L"REGISTROS";
			this->btn_registros->UseVisualStyleBackColor = false;
			this->btn_registros->Click += gcnew System::EventHandler(this, &Presentacion::btn_registros_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Coral;
			this->label1->Location = System::Drawing::Point(213, 205);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(452, 29);
			this->label1->TabIndex = 4;
			this->label1->Text = L"BIENVENIDOS A DRAGON STRIKER!";
			// 
			// Presentacion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(842, 689);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_registros);
			this->Controls->Add(this->btn_jugar);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Presentacion";
			this->Text = L"Presentacion";
			this->Load += gcnew System::EventHandler(this, &Presentacion::Presentacion_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Presentacion_Load(System::Object^ sender, System::EventArgs^ e) {
		label1->Parent = pictureBox1;
		label1->BackColor = Color::Transparent;
		music->PlayLooping();
	}

	Void btn_jugar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text != "") {
			MyForm^ form1 = gcnew MyForm(textBox1->Text);
			this->Hide();
			form1->ShowDialog();
			delete form1;
			this->Show();
			textBox1->Text = "";
		}
		else {
			MessageBox::Show("INGRESE UN NOMBRE DE USUARIO", "ADVERTENCIA");
		}
	}
    Void btn_registros_Click(System::Object^ sender, System::EventArgs^ e) {
		Registros^ registros = gcnew Registros();
		registros->ShowDialog();
		delete registros;
}
};
}
