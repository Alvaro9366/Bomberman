#pragma once
#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Escenario.h"

class Controlador {

public:
	Controlador();
	~Controlador();
	void nuevoNivel();
	void dibujar(Graphics^, Bitmap^, Bitmap^, Bitmap^);


private:
	Escenario* escenarioPrincipal;
};

#endif // !CONTROLADOR_H
