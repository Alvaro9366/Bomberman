#pragma once
#include "Controlador.h"

namespace ProyectoBomberman {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Ventana
	/// </summary>
	public ref class Ventana : public System::Windows::Forms::Form
	{
		public:
			Controlador* nuevoControlador = new Controlador();
			Bitmap^ bmpFijo = gcnew Bitmap("Imagenes\\bmpFijo.png");
			Bitmap^ bmpDestruible = gcnew Bitmap("Imagenes\\bmpDestruible.png");
			Bitmap^ bmpSuelo = gcnew Bitmap("Imagenes\\bmpSuelo.png");

			Ventana(void)
			{
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~Ventana()
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
			/// <summary>
			/// Required designer variable.
			/// </summary>


	#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
			{
				this->components = (gcnew System::ComponentModel::Container());
				this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				this->SuspendLayout();
				// 
				// timer1
				// 
				this->timer1->Enabled = true;
				this->timer1->Tick += gcnew System::EventHandler(this, &Ventana::timer1_Tick);
				// 
				// Ventana
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(750, 650);		//Ajuste de tamaño de ventana
				this->Name = L"Ventana";
				this->Text = L"Ventana";
				this->Load += gcnew System::EventHandler(this, &Ventana::Ventana_Load);
				this->ResumeLayout(false);

			}
	#pragma endregion
		private: System::Void Ventana_Load(System::Object^ sender, System::EventArgs^ e) {
			nuevoControlador->nuevoNivel();
		}

		private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
			Graphics^ g = this->CreateGraphics();
			BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
			BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
			nuevoControlador->nuevoNivel();
			nuevoControlador->dibujar(buffer->Graphics, bmpSuelo, bmpFijo, bmpDestruible);
			buffer->Render(g);

			delete buffer;
			delete espacio;
			delete g;
		}
	};
}
