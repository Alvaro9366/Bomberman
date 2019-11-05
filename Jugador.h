#pragma once
#ifndef JUGADOR_H
#define JUGADOR_H

using namespace System::Drawing;

enum Direcciones { Arriba, Abajo, Izquierda, Derecha, Ninguna };

class Jugador {

public:
	Jugador(int, int);
	~Jugador();
	void dibujarJugador(Graphics^, Bitmap^, int**);
	void moverJugador(Graphics^, Bitmap^, int**);
	void setDireccion(Direcciones);
	void validarMovimiento(int**);

private:
	int x;
	int y;
	int dx;
	int dy;
	int indiceX;
	int indiceY;
	int ancho;
	int alto;
	Direcciones direccion;
	Direcciones ultima;
	Rectangle CDI;
	Rectangle CAA;
};

#endif // !JUGADOR_H