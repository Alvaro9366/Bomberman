#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Escenario.h"
#include "Jugador.h"

class Controlador {

public:
	Controlador();
	~Controlador();
	void nuevoNivel();
	void dibujar(Graphics^, Bitmap^, Bitmap^, Bitmap^, Bitmap^);
	Jugador* getJugador();

private:
	Escenario* escenarioPrincipal;
	Jugador* jugadorPrincipal;
};

#endif // !CONTROLADOR_H
