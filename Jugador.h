#pragma once
#ifndef JUGADOR_H
#define JUGADOR_H

using namespace System::Drawing;

enum Direcciones { Arriba, Abajo, Izquierda, Derecha, Ninguna }; //Conjunto de variables

class Jugador{

public:
	Jugador(int, int);
	~Jugador();
	void ValidarMovimiento(int **matriz);
	void dibujarJugador(Graphics^, Bitmap^,int**);
	void moverJugador(Graphics^, Bitmap^, int**);
	void setDireccion(Direcciones);

private:
	int x; //Pos en x
	int y; //Pos en y
	int dx; //Cambio en x
	int dy; //Cambio en y
	int indiceX; //Ayuda para cambiar entre sprites
	int indiceY; //
	int ancho;
	int alto;
	Direcciones direccion;
	Direcciones ultima;
	Rectangle CDI; //
	Rectangle CAA; //
};

#endif // !JUGADOR_H