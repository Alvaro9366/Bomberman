#include "Jugador.h"
#include "Escenario.h"

Jugador::Jugador(int x, int y) {

	//Posición del jugador
	this->x = x;
	this->y = y;

	//Desplazamiento del jugador
	dx = 0;
	dy = 0;


	//Animación del sprite
	ancho = 18;
	alto = 26;
	indiceX = 0;
	indiceY = 0;

	direccion = Direcciones::Ninguna;
	ultima = Direcciones::Abajo;

}

Jugador::~Jugador() {

}

void Jugador::dibujarJugador(Graphics^ g, Bitmap^ bmpJugador, int** matriz) {

	CDI = Rectangle(x + 2 * 3 + dx, y + 15 * 3, (ancho - 4) * 3, (alto - 15) * 3);
	CAA = Rectangle(x + 2 * 3, y + 15 * 3 + dy, (ancho - 4) * 3, (alto - 15) * 3);

	g->DrawRectangle(Pens::Transparent, CDI);
	g->DrawRectangle(Pens::Transparent, CAA);

	validarMovimiento(matriz);

	Rectangle Selector = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	Rectangle Aumento = Rectangle(x, y, ancho * 3, alto * 3);

	g->DrawImage(bmpJugador, Aumento, Selector, GraphicsUnit::Pixel);

	x += dx;
	y += dy;

}

void Jugador::moverJugador(Graphics^ g, Bitmap^ bmpJugador, int** matriz) {

	direccion == Arriba ? ancho = 17 : ancho = 18;

	switch (direccion) {

	case Direcciones::Arriba:
		indiceY = 0;

		if (indiceX >= 1 && indiceX < 3) {
			indiceX++;
		}
		else {
			indiceX = 1;
		}

		dx = 0;
		dy = -10;

		ultima = Arriba;

		break;

	case Direcciones::Abajo:
		indiceX = 0;

		if (indiceY >= 1 && indiceY < 3) {
			indiceY++;
		}
		else {
			indiceY = 1;
		}

		dx = 0;
		dy = 10;

		ultima = Abajo;

		break;

	case Direcciones::Izquierda:
		indiceY = 3;

		if (indiceX >= 1 && indiceX < 3) {
			indiceX++;
		}
		else {
			indiceX = 1;
		}
		dx = -10;
		dy = 0;

		ultima = Izquierda;

		break;

	case Direcciones::Derecha:
		indiceY = 1;

		if (indiceX >= 1 && indiceX < 3) {
			indiceX++;
		}
		else {
			indiceX = 1;
		}
		dx = 10;
		dy = 0;

		ultima = Derecha;

		break;

	case Direcciones::Ninguna:
		dx = 0;
		dy = 0;

		if (ultima == Direcciones::Arriba) {
			indiceX = 0;
			indiceY = 0;
		}
		if (ultima == Direcciones::Abajo) {
			indiceX = 0;
			indiceY = 2;
		}
		if (ultima == Direcciones::Izquierda) {
			indiceX = 1;
			indiceY = 3;
		}
		if (ultima == Direcciones::Derecha) {
			indiceX = 1;
			indiceY = 1;
		}
		break;

	default:
		break;
	}

	dibujarJugador(g, bmpJugador, matriz);
}

void Jugador::setDireccion(Direcciones direccion) {
	this->direccion = direccion;
}

void Jugador::validarMovimiento(int** matriz) {
	int X{ 0 };
	int Y{ 0 };
	for (int i{ 0 }; i < filas; i++) {
		X = 0;
		for (int j{ 0 }; j < columnas; j++) {
			Rectangle bloqueo = Rectangle(X, Y, 50, 50);
			if (matriz[i][j] == 0 || matriz[i][j] == 1) {
				if (CDI.IntersectsWith(bloqueo))
					dx = 0;
				if (CAA.IntersectsWith(bloqueo))
					dy = 0;
			}
			X += 50;
		}
		Y += 50;
	}
}
