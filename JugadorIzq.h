#ifndef JUGADORIZQ_H
#define JUGADORIZQ_H

#include "Jugador.h"

enum Direcciones {Arriba, Abajo, Izquierda, Derecha, Ninguna }; //Conjunto de variables

class JugadorIzq: public Jugador{

public:
	JugadorIzq(int, int);
	~JugadorIzq();

	int getX() { return x + 2 * 3; }
	int getY() { return y + 15 * 3; }


	void dibujarJugador(Graphics^, Bitmap^, int**);
	void moverJugador(Graphics^, Bitmap^, int**);

	void setDireccion(Direcciones);
	void ValidarMovimiento(int** matriz);

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

#endif // !JUGADORIZQ_H