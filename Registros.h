#pragma once
#include "Binary.h"
namespace JuegoDragones {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Registros : public System::Windows::Forms::Form
	{
	public:
		Registros(void)
		{
			InitializeComponent();
			Configuracion* config = new Configuracion("data.txt");
			textBox1->Text = "";
			for (int i = 0; i < config->getlines().size(); i++) {
				textBox1->Text += "\n" + (i + 1).ToString() + ".- " + gcnew String(config->getlines()[i].c_str()) +
					"\r";
			}
			delete config;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Registros()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Wheat;
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox1->Location = System::Drawing::Point(0, 0);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(788, 640);
			this->textBox1->TabIndex = 0;
			// 
			// Registros
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(788, 640);
			this->Controls->Add(this->textBox1);
			this->Name = L"Registros";
			this->Text = L"Registros";
			this->Load += gcnew System::EventHandler(this, &Registros::Registros_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Registros_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
