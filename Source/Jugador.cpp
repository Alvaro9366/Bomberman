#include "../Headers/Jugador.h"
#include "../Headers/Escenario.h"

Jugador::Jugador(int x, int y) {

	//Posición del jugador
	this->x = x;
	this->y = y;

	//Desplazamiento del jugador
	dx = 0;
	dy = 0;


	//Animación del sprite
	ancho = 17;
	alto = 26;
	indiceX = 0;
	indiceY = 0;

	direccion = Direcciones::Ninguna;
	ultima = Direcciones::Abajo;

}

Jugador::~Jugador() {

}

int Jugador::getX() {
	return x + 2 * 3;
}

int Jugador::getY() {
	return y + 15 * 3;
}

void Jugador::dibujarJugador(Graphics^ g, Bitmap^ bmpJugador, int** matriz) {
	int i = 3;		//Factor de escala

	CDI = Rectangle(x + 2 * i + dx, y + 15 * i, (ancho - 6) * i - 2, (alto - 15) * i);
	CAA = Rectangle(x + 2 * i, y + 15 * i + dy, (ancho - 6) * i - 2, (alto - 15) * i);

	g->DrawRectangle(Pens::Transparent, CDI);
	g->DrawRectangle(Pens::Transparent, CAA);

	validarMovimiento(matriz);

	Rectangle Selector = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	Rectangle Escala = Rectangle(x, y, ancho * i - 2, alto * i - 2);

	g->DrawImage(bmpJugador, Escala, Selector, GraphicsUnit::Pixel);

	x += dx;
	y += dy;

}

void Jugador::moverJugador(Graphics^ g, Bitmap^ bmpJugador, int** matriz) {

	//direccion == Arriba ? ancho = 17 : ancho = 18;
	if (direccion == Arriba || direccion == Abajo) {
		ancho = 17;
	}
	else {
		if (direccion == Izquierda || direccion == Derecha) {
			ancho = 18;
		}
	}

	switch (direccion) {

	case Direcciones::Arriba:
		indiceY = 0;

		if (indiceX >= 0 && indiceX < 3) {
			indiceX++;
		}
		else {
			indiceX = 0;
		}

		dx = 0;
		dy = -10;

		ultima = Arriba;

		break;

	case Direcciones::Abajo:
		indiceX = 0;

		switch (aux) {
		case 0:
		case 2:
			indiceY = 2;
			aux++;
			break;
		case 1:
			indiceY = 1;
			aux++;
			break;
		case 3:
			indiceY = 3;
			aux = 0;
			break;
		}

		dx = 0;
		dy = 10;

		ultima = Abajo;

		break;

	case Direcciones::Izquierda:
		indiceY = 3;

		switch (aux) {
		case 0:
		case 2:
			indiceX = 1;
			aux++;
			break;
		case 1:
			indiceX = 2;
			aux++;
			break;
		case 3:
			indiceX = 3;
			aux = 0;
			break;
		}

		dx = -10;
		dy = 0;

		ultima = Izquierda;

		break;

	case Direcciones::Derecha:
		indiceY = 1;

		switch (aux) {
		case 0:
		case 2:
			indiceX = 1;
			aux++;
			break;
		case 1:
			indiceX = 2;
			aux++;
			break;
		case 3:
			indiceX = 3;
			aux = 0;
			break;
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
			Rectangle Bloqueo = Rectangle(X, Y, 50, 50);
			if (matriz[i][j] == 0 || matriz[i][j] == 1) {
				if (CDI.IntersectsWith(Bloqueo)) {
					dx = 0;
				}
				if (CAA.IntersectsWith(Bloqueo)) {
					dy = 0;
				}
			}
			X += 50;
		}
		Y += 50;
	}
}
