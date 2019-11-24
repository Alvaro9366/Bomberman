#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Escenario.h"
#include "JugadorIzq.h"
#include "JugadorDer.h"
#include "VectorBomba.h"

class Controlador {

public:
	Controlador();
	~Controlador();


	void nuevoNivel();

	void dibujar(Graphics^, Bitmap^, Bitmap^, Bitmap^, Bitmap^, Bitmap^, Bitmap^, Bitmap^); //Last 2  are new

	JugadorIzq* getJugadorIzq();
	JugadorDer* getJugadorDer();

	void agregarBombaJ1();
	void agregarBombaJ2();

private:
	Escenario* escenarioPrincipal; //Creando variable para el escenario
	JugadorIzq* jugadorPrincipal;
	JugadorDer* jugadorSecundario;

	VectorBomba* bombasPrincipal;
	VectorBomba* bombasSecundario;
};

#endif // !CONTROLADOR_H
