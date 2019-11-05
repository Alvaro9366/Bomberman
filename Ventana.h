#pragma once
#include "./Headers/Controlador.h"

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
		private:
			Controlador* nuevoControlador = new Controlador();
			Bitmap^ bmpFijo = gcnew Bitmap("Imagenes\\bmpFijo.png");
			Bitmap^ bmpDestruible = gcnew Bitmap("Imagenes\\bmpDestruible.png");
			Bitmap^ bmpSuelo = gcnew Bitmap("Imagenes\\bmpSuelo.png");
			Bitmap^ bmpJugador = gcnew Bitmap("Imagenes\\Jugador.png");
			Bitmap^ bmpBomba = gcnew Bitmap("Imagenes\\bomba.png");
			Bitmap^ bmpExplosion = gcnew Bitmap("Imagenes\\explosion.png");

		public:
			Ventana(void)
			{
				bmpJugador->MakeTransparent(bmpJugador->GetPixel(0, 0));
				bmpBomba->MakeTransparent(bmpBomba->GetPixel(0, 0));
				bmpExplosion->MakeTransparent(bmpExplosion->GetPixel(0, 0));
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
				System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Ventana::typeid));
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
				this->ClientSize = System::Drawing::Size(750, 650);
				this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				this->Name = L"Ventana";
				this->Text = L"Bomberman!";
				this->Load += gcnew System::EventHandler(this, &Ventana::Ventana_Load);
				this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Ventana::MantenerTecla);
				this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Ventana::SoltarTecla);
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
			//nuevoControlador->nuevoNivel();
			nuevoControlador->dibujar(buffer->Graphics, bmpSuelo, bmpFijo, bmpDestruible, bmpJugador, bmpBomba, bmpExplosion);
			buffer->Render(g);

			delete buffer;
			delete espacio;
			delete g;
		}
		private: System::Void MantenerTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			
			switch (e->KeyCode) {

				case Keys::Up:
					nuevoControlador->getJugador()->setDireccion(Direcciones::Arriba);
					break;

				case Keys::Down:
					nuevoControlador->getJugador()->setDireccion(Direcciones::Abajo);
					break;

				case Keys::Left:
					nuevoControlador->getJugador()->setDireccion(Direcciones::Izquierda);
					break;

				case Keys::Right:
					nuevoControlador->getJugador()->setDireccion(Direcciones::Derecha);
					break;

				default:
					break;

			}
		}
		private: System::Void SoltarTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

			switch (e->KeyCode) {
			case Keys::Space:
				nuevoControlador->agregarBomba();
			default:
				nuevoControlador->getJugador()->setDireccion(Direcciones::Ninguna);
				break;
			}
		}
	};
}
