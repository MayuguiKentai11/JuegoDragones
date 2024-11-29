#pragma once
#include "Controller.h"
#include "Binary.h"
namespace JuegoDragones {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(String^nombre)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			g = this->CreateGraphics();
			r = gcnew Random();
			Remoto = new Controller(g, r);
			img_jugador = gcnew Bitmap("imagenes/jugador.png");
			img_dragones = gcnew Bitmap("imagenes/dragon.png");
			img_bala = gcnew Bitmap("imagenes/bala.png");
			tiempo = 60;
			this->nombre = nombre;
			fondo = gcnew Bitmap("imagenes/fondo_nivel.jpg");
		}
		string getString(String^ a)
		{
			char cStr[50] = { 0 };

			String^ text_to_convert = a;

			if (text_to_convert->Length < sizeof(cStr))
			{
				sprintf(cStr, "%s", text_to_convert);
			}

			return cStr;
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ reloj;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Controller* Remoto;
		Graphics^ g;
		Random^ r;
		String^ nombre;
		//Imagenes
		Bitmap^ img_jugador;
		Bitmap^ img_dragones;
		Bitmap^ fondo;
		short tiempo;
	private: System::Windows::Forms::Timer^ agregar_Dragones;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ mostrar_vidas;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Timer^ fin_juego;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ mostrar_puntaje;
	private: System::Windows::Forms::Label^ label4;



		   Bitmap^ img_bala;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->reloj = (gcnew System::Windows::Forms::Timer(this->components));
			this->agregar_Dragones = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->mostrar_vidas = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->fin_juego = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->mostrar_puntaje = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// reloj
			// 
			this->reloj->Tick += gcnew System::EventHandler(this, &MyForm::reloj_Tick);
			// 
			// agregar_Dragones
			// 
			this->agregar_Dragones->Interval = 3000;
			this->agregar_Dragones->Tick += gcnew System::EventHandler(this, &MyForm::agregar_Dragones_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"VIDAS:";
			// 
			// mostrar_vidas
			// 
			this->mostrar_vidas->AutoSize = true;
			this->mostrar_vidas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mostrar_vidas->Location = System::Drawing::Point(92, 9);
			this->mostrar_vidas->Name = L"mostrar_vidas";
			this->mostrar_vidas->Size = System::Drawing::Size(48, 22);
			this->mostrar_vidas->TabIndex = 1;
			this->mostrar_vidas->Text = L"hola";
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Interval = 1000;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// fin_juego
			// 
			this->fin_juego->Interval = 60000;
			this->fin_juego->Tick += gcnew System::EventHandler(this, &MyForm::fin_juego_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(632, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 22);
			this->label2->TabIndex = 2;
			this->label2->Text = L"TIEMPO:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(744, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 22);
			this->label3->TabIndex = 3;
			this->label3->Text = L"hola";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// mostrar_puntaje
			// 
			this->mostrar_puntaje->AutoSize = true;
			this->mostrar_puntaje->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mostrar_puntaje->Location = System::Drawing::Point(457, 9);
			this->mostrar_puntaje->Name = L"mostrar_puntaje";
			this->mostrar_puntaje->Size = System::Drawing::Size(48, 22);
			this->mostrar_puntaje->TabIndex = 5;
			this->mostrar_puntaje->Text = L"hola";
			this->mostrar_puntaje->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(209, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(74, 22);
			this->label4->TabIndex = 6;
			this->label4->Text = L"VIDAS:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(797, 672);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->mostrar_puntaje);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->mostrar_vidas);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"DragonStriker";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void reloj_Tick(System::Object^ sender, System::EventArgs^ e) {
		BufferedGraphicsContext^ bfc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = bfc->Allocate(g, this->ClientRectangle);
		bf->Graphics->DrawImage(fondo, 0, 0, (int)bf->Graphics->VisibleClipBounds.Width, (int)bf->Graphics->VisibleClipBounds.Height);
		Remoto->FuncionalidadJugador(bf->Graphics, img_jugador);
		Remoto->MoverBala(bf->Graphics, img_bala);
		Remoto->MoverDragones(bf->Graphics, img_dragones);
		//Verificar Colisiones
		Remoto->ColisionesDragonJugador();
		Remoto->ColisionDragonBala(bf->Graphics);
		//Mostrar Registros
		mostrar_vidas->Text = Remoto->get_Vidas().ToString();
		mostrar_puntaje->Text = Remoto->get_Puntaje().ToString();
		//bf->Graphics->DrawString();
		bf->Render(g);
		if (Remoto->ColisionesDragonJugador() == true) {
			reloj->Enabled = false;
			timer->Enabled = false;
			fin_juego->Enabled = false;
			MessageBox::Show("Perdiste! Registro Guardado!");
			Configuracion* configuracion = new Configuracion("data.txt");
			configuracion->guardar(getString(nombre), "Perdio", "Mundo 1");
			delete configuracion;
			this->Close();
			return;
		} //26:56
		delete bf;
		delete bfc;
	}
	Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		Remoto->CambiarVelocidadJugador(e->KeyCode, true);
	}
	Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		Remoto->CambiarVelocidadJugador(e->KeyCode, false);
	}
	Void agregar_Dragones_Tick(System::Object^ sender, System::EventArgs^ e) {
		short aux_dragones=r->Next(1,4);
		if (aux_dragones == 1)Remoto->Agregar_Azul(g, r);
		if (aux_dragones == 2)Remoto->Agregar_Rojo(g, r);
		if (aux_dragones == 3)Remoto->Agregar_Negro(g, r);
	}
	Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		short aux = tiempo - 1;
		tiempo = aux;
		label3->Text = tiempo.ToString();
	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	Remoto->GuardarInformacion();
	label3->BackColor = Color::Transparent;
	MessageBox::Show("Asesina la mayor cantidad de Dragones antes que termine el tiempo!","INFORMATION",MessageBoxButtons::OK,MessageBoxIcon::Information);
	label4->Text = nombre;
	fin_juego->Interval = tiempo*1000;
	reloj->Enabled = true;
	agregar_Dragones->Enabled = true;
	fin_juego->Enabled = true;
	label3->Text = tiempo.ToString();
}
    Void fin_juego_Tick(System::Object^ sender, System::EventArgs^ e) {
		reloj->Enabled = false;
		agregar_Dragones->Enabled = false;
		fin_juego->Enabled = false;
		timer->Enabled = false;
		Remoto->GuardarInformacion();
		MessageBox::Show("Felicidades! Se registro tu puntuacion!");
		Configuracion* configuracion = new Configuracion("data.txt");
		configuracion->guardar(getString(nombre), "Gano", "Mundo 1");
		delete configuracion;
		this->Close();
		return;
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
