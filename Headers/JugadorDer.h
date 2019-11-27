#ifndef __JUGADORDER_H__
#define __JUGADORDER_H__

#include "Jugador.h"

enum Direcciones2 { Arriba2, Abajo2, Izquierda2, Derecha2, Ninguna2 }; //Conjunto de variables

class JugadorDer : public Jugador {

public:
	JugadorDer(int, int);
	~JugadorDer();

	int getX() { return x + 2 * 3; }
	int getY() { return y + 15 * 3; }
	int getVidas() { return vidas; }

	void dibujarJugador(Graphics^, Bitmap^, int**);
	void moverJugador(Graphics^, Bitmap^, int**);

	void setDireccion(Direcciones2);
	void ValidarMovimiento(int** matriz);

	void disminuirvida(int, int, int, int, int, int, int, int);

private:
	int vidas=5;
	int x; //Pos en x
	int y; //Pos en y
	int dx; //Cambio en x
	int dy; //Cambio en y
	int indiceX; //Ayuda para cambiar entre sprites
	int indiceY; //
	int ancho;
	int alto;
	Direcciones2 direccion;
	Direcciones2 ultima;
	Rectangle CDI; //
	Rectangle CAA; //
};

#endif // !JUGADORDER_H