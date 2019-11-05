#pragma once
#ifndef JUGADOR_H
#define JUGADOR_H

using namespace System::Drawing;

enum Direcciones { 
	Arriba, 
	Abajo, 
	Izquierda, 
	Derecha, 
	Ninguna 
};

class Jugador {

public:
	Jugador(int, int);
	~Jugador();

	int getX();
	int getY();

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
	int aux = 0;
};

#endif // !JUGADOR_H