#include "JugadorDer.h"
#include "Escenario.h"

JugadorDer::JugadorDer(int x, int y) {

	//Posición del jugador
	this->x = x;
	this->y = y;

	//Desplazamiento del jugador
	dx = 0;
	dy = 0;


	//Animación del sprite
	ancho = (102/6); // 17  Ancho del sprite seleccionado
	alto = 26; //   125/6     Alto del sprite seleccionado 

	indiceX = 0;
	indiceY = 0;

	//Inicialización del jugador
	direccion = Direcciones2::Ninguna2;
	ultima = Direcciones2::Arriba2;

}

JugadorDer::~JugadorDer() {

}

void JugadorDer::ValidarMovimiento(int** matriz) {
	int X = 0;
	int Y = 0;
	for (int i = 0; i < filas; i++) {
		X = 0;
		for (int j = 0; j < columnas; j++) {
			Rectangle C1 = Rectangle(X, Y, 50, 50);
			if (matriz[i][j] == 1 || matriz[i][j] == 0) {
				if (CDI.IntersectsWith(C1))dx = 0;
				if (CAA.IntersectsWith(C1))dy = 0;
			}
			X += 50;
		}
		Y += 50;
	}

}


void JugadorDer::dibujarJugador(Graphics^ g, Bitmap^ bmpJugador2, int** matriz) {

	CDI = Rectangle(x + 2 * 3 + dx, y + 15 * 3, (ancho - 4) * 3, (alto - 15) * 3);
	CAA = Rectangle(x + 2 * 3, y + 15 * 3 + dy, (ancho - 4) * 3, (alto - 15) * 3);

	g->DrawRectangle(Pens::Transparent, CDI);
	g->DrawRectangle(Pens::Transparent, CAA);

	ValidarMovimiento(matriz);

	Rectangle Selector = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto); //Cuadro que limita el bitmap del jugador
	Rectangle Aumento = Rectangle(x,y, ancho * 3, alto * 3); //Cuadro que limita el bitmap del jugador  x + (50 * (filas - 1)), y + (50 * (columnas - 6))

	g->DrawImage(bmpJugador2, Aumento, Selector, GraphicsUnit::Pixel);

	x += dx;
	y += dy;

}

void JugadorDer::moverJugador(Graphics^ g, Bitmap^ bmpJugador2, int** matriz) { //Animacion de caminar

	direccion == Arriba2 ? ancho = 17 : ancho = 18;

	switch (direccion) {

	case Direcciones2::Arriba2:
		indiceY = 0;

		if (indiceX >= 1 && indiceX < 3) { //Intercala entre sprites para caminar hacia arriba
			indiceX++;
		}
		else {
			indiceX = 1;
		}

		dx = 0; //X no cambia si camina arriba
		dy = -10;//Si camina hacia arriba entonces "y" disminuye

		ultima = Arriba2;

		break;

	case Direcciones2::Abajo2:
		indiceX = 0;

		if (indiceY >= 1 && indiceY < 3) {
			indiceY++;
		}
		else {
			indiceY = 1;
		}

		dx = 0;
		dy = 10;

		ultima = Abajo2;

		break;

	case Direcciones2::Izquierda2:
		indiceY = 3;

		if (indiceX >= 1 && indiceX < 3) { //Intercambia el indice en x para caminar a la izquierda
			indiceX++;
		}
		else {
			indiceX = 1;
		}
		dx = -10;
		dy = 0;

		ultima = Izquierda2;

		break;

	case Direcciones2::Derecha2:
		indiceY = 1;

		if (indiceX >= 1 && indiceX < 3) {
			indiceX++;
		}
		else {
			indiceX = 1;
		}
		dx = 10;
		dy = 0;

		ultima = Derecha2;

		break;

	case Direcciones2::Ninguna2:
		dx = 0;
		dy = 0;

		if (ultima == Direcciones2::Arriba2) {
			indiceX = 0;
			indiceY = 0;
		}
		if (ultima == Direcciones2::Abajo2) {
			indiceX = 0;
			indiceY = 2;
		}
		if (ultima == Direcciones2::Izquierda2) {
			indiceX = 1;
			indiceY = 3;
		}
		if (ultima == Direcciones2::Derecha2) {
			indiceX = 1;
			indiceY = 1;
		}
		break;

	default:
		break;
	}

	dibujarJugador(g, bmpJugador2, matriz);
}

void JugadorDer::setDireccion(Direcciones2 direccion) {
	this->direccion = direccion;
}
