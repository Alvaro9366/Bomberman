#pragma once
#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Escenario.h"
#include "Jugador.h"
#include "VectorBombas.h"

class Controlador {

public:
	Controlador();
	~Controlador();
	void nuevoNivel();
	void agregarBomba();
	void dibujar(Graphics^, Bitmap^, Bitmap^, Bitmap^, Bitmap^, Bitmap^, Bitmap^);
	Jugador* getJugador();

private:
	Escenario* escenarioPrincipal;
	Jugador* jugadorPrincipal;
	VectorBombas* bombasPrincipal;
	
};

#endif // !CONTROLADOR_H
