#include "Controlador.h"

namespace BombermanDef {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Ventana
	/// </summary>
	public ref class Ventana : public System::Windows::Forms::Form
	{
	public:
		Controlador* nuevoControlador = new Controlador();

		Bitmap^ bmpFijo = gcnew Bitmap("Imagenes\\bmpFijo.png");
		Bitmap^ bmpDestruible = gcnew Bitmap("Imagenes\\bmpDestruible.png");
		Bitmap^ bmpSuelo = gcnew Bitmap("Imagenes\\bmpSuelo.png");
		Bitmap^ bmpJugador = gcnew Bitmap("Imagenes\\Jugador.png");
		Bitmap^ bmpJugador2 = gcnew Bitmap("Imagenes\\Jugador2.png");
		Bitmap^ bmpBomba = gcnew Bitmap("Imagenes\\bomba.png");
		Bitmap^ bmpExplosion = gcnew Bitmap("Imagenes\\explosion.png");

		Ventana(void)
		{
			bmpJugador->MakeTransparent(bmpJugador->GetPixel(0, 0));
			bmpJugador2->MakeTransparent(bmpJugador2->GetPixel(0, 0));
			bmpBomba->MakeTransparent(bmpBomba->GetPixel(0, 0));
			bmpExplosion->MakeTransparent(bmpExplosion->GetPixel(0, 0));
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Ventana()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Timer^ timer1;
	

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
			this->ClientSize = System::Drawing::Size(50*columnas, 50*filas); //Largo y ancho de la ventana
			this->Name = L"Ventana";
			this->Text = L"Ventana";


			//Key Press events
			this->Load += gcnew System::EventHandler(this, &Ventana::Ventana_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Ventana::MantenerTecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Ventana::SoltarTecla);

			this->ResumeLayout(false);

			

		}
#pragma endregion
	
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) { //timer
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		nuevoControlador->dibujar(buffer->Graphics, bmpSuelo, bmpFijo, bmpDestruible, bmpJugador,bmpJugador2, bmpBomba, bmpExplosion);
		buffer->Render(g);

		delete buffer;
		delete espacio;
		delete g;
	}
	private: System::Void Ventana_Load(System::Object^ sender, System::EventArgs^ e) {
		nuevoControlador->nuevoNivel();
	}



	private: System::Void MantenerTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) { //Key Press Events

		switch (e->KeyCode) {

		case Keys::W:
			nuevoControlador->getJugadorIzq()->setDireccion(Direcciones::Arriba);
			break;

		case Keys::S:
			nuevoControlador->getJugadorIzq()->setDireccion(Direcciones::Abajo);
			break;

		case Keys::A:
			nuevoControlador->getJugadorIzq()->setDireccion(Direcciones::Izquierda);
			break;

		case Keys::D:
			nuevoControlador->getJugadorIzq()->setDireccion(Direcciones::Derecha);
			break;

		case Keys::Up:
			nuevoControlador->getJugadorDer()->setDireccion(Direcciones2::Arriba2);
			break;

		case Keys::Down:
			nuevoControlador->getJugadorDer()->setDireccion(Direcciones2::Abajo2);
			break;

		case Keys::Left:
			nuevoControlador->getJugadorDer()->setDireccion(Direcciones2::Izquierda2);
			break;

		case Keys::Right:
			nuevoControlador->getJugadorDer()->setDireccion(Direcciones2::Derecha2);
			break;


		default:
			break;

		}
	}
	private: System::Void SoltarTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) { //Key Press Events

		switch (e->KeyCode) {
			//Solucion de bug de caminatas pausadas
		case Keys::W:
			nuevoControlador->getJugadorIzq()->setDireccion(Direcciones::Ninguna);
			break;

		case Keys::S:
			nuevoControlador->getJugadorIzq()->setDireccion(Direcciones::Ninguna);
			break;

		case Keys::A:
			nuevoControlador->getJugadorIzq()->setDireccion(Direcciones::Ninguna);
			break;

		case Keys::D:
			nuevoControlador->getJugadorIzq()->setDireccion(Direcciones::Ninguna);
			break;

		case Keys::Up:
			nuevoControlador->getJugadorDer()->setDireccion(Direcciones2::Ninguna2);
			break;

		case Keys::Down:
			nuevoControlador->getJugadorDer()->setDireccion(Direcciones2::Ninguna2);
			break;

		case Keys::Left:
			nuevoControlador->getJugadorDer()->setDireccion(Direcciones2::Ninguna2);
			break;

		case Keys::Right:
			nuevoControlador->getJugadorDer()->setDireccion(Direcciones2::Ninguna2);
			break;
		case Keys::C:
			nuevoControlador->agregarBombaJ1();
			break;
		case Keys::Space:
			nuevoControlador->agregarBombaJ2();
			break;

		
		default:
			break;
		}
	}


	};
}
