#include "../Headers/Bomba.h"

Bomba::Bomba(int x, int y) {
	this->x = x;
	this->y = y;

	estado = Estado::Normal;

	ancho = 22;
	alto = 24;

	indiceX = 0;
	tiempoPreexplosion = 0;

	//Datos iniciales para la explosión

	indiceEX = 0;
	indiceEY = 0;
	altoExplosion = 20;
	anchoExplosion = 20;

}

Bomba::~Bomba() {
}

Estado Bomba::getEstado() {
	return estado;
}

bool Bomba::validarLugar(int xJugador, int yJugador, int** matriz) {
	if (matriz[yJugador / 50][xJugador / 50] == 2) {
		return true;
	} 
	else {
		return false;
	}
}

void Bomba::dibujarBomba(Graphics^ g, Bitmap^ bmpBomba, int xJugador, int yJugador, int** matriz) {

	if (validarLugar(xJugador, yJugador, matriz)) {
		Rectangle Selector = Rectangle(indiceX * ancho, 0, ancho, alto);
		Rectangle aumento = Rectangle(x-3, y-10, 45, 45);
		g->DrawImage(bmpBomba, aumento, Selector, GraphicsUnit::Pixel);
	}

	if (tiempoPreexplosion == 6) {
		estado = Estado::Explosion;
	}
}

void Bomba::animar() {
	if (indiceX >= 0 && indiceX < 2) {
		indiceX++;
	}
	else {
		tiempoPreexplosion++;
		indiceX = 0;
	}
}

void Bomba::dibujarExplosion(Graphics^ g, Bitmap^ bmpExplosion, int** matriz) {

	Rectangle SelectorCentro = Rectangle(indiceEX * anchoExplosion, indiceEY * altoExplosion, anchoExplosion, altoExplosion); // indiceY=0
	Rectangle Centro = Rectangle(x, y, 50, 50);
	g->DrawImage(bmpExplosion, Centro, SelectorCentro, GraphicsUnit::Pixel);

	if (matriz[y / 50][(x - 50) / 50] != 0) {
		Rectangle SelectorIzquierda = Rectangle(indiceEX * anchoExplosion, indiceEY + 2 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 2
		Rectangle Izquierda = Rectangle(x - 50, y, 50, 50);
		g->DrawImage(bmpExplosion, Izquierda, SelectorIzquierda, GraphicsUnit::Pixel);

		if (matriz[y / 50][(x - 50) / 50] == 1) { 
			matriz[y / 50][(x - 50) / 50] = 2; 
		}
	}

	if (matriz[y / 50][(x + 50) / 50] != 0) {
		Rectangle SelectorDerecha = Rectangle(indiceEX * anchoExplosion, indiceEY + 4 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 4
		Rectangle Derecha = Rectangle(x + 50, y, 50, 50);
		g->DrawImage(bmpExplosion, Derecha, SelectorDerecha, GraphicsUnit::Pixel);

		if (matriz[y / 50][(x + 50) / 50] == 1) { 
			matriz[y / 50][(x + 50) / 50] = 2; 
		}
	}

	if (matriz[y / 50][(x + 50) / 50] != 0) {
		Rectangle SelectorPuntaDerecha = Rectangle(indiceEX * anchoExplosion, indiceEY + 3 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 3
		Rectangle PuntaDerecha = Rectangle(x + 100, y, 50, 50);
		g->DrawImage(bmpExplosion, PuntaDerecha, SelectorPuntaDerecha, GraphicsUnit::Pixel);

		if (matriz[y / 50][(x + 100) / 50] == 1) {
			matriz[y / 50][(x + 100) / 50] = 2;
		}
	}

	if (matriz[y / 50][(x - 50) / 50] != 0) {
		Rectangle SelectorPuntaIzquierda = Rectangle(indiceEX * anchoExplosion, indiceEY + 1 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 1
		Rectangle PuntaIzquierda = Rectangle(x - 100, y, 50, 50);
		g->DrawImage(bmpExplosion, PuntaIzquierda, SelectorPuntaIzquierda, GraphicsUnit::Pixel);

		if (matriz[y / 50][(x - 100) / 50] == 1) {
			matriz[y / 50][(x - 100) / 50] = 2;
		}
	}

	Rectangle SelectorVerticales = Rectangle(indiceEX * anchoExplosion, indiceEY + 6 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 6
	Rectangle VerticalSuperior = Rectangle(x, y - 50, 50, 50);
	Rectangle VerticalInferior = Rectangle(x, y + 50, 50, 50);

	if (matriz[(y - 50) / 50][x / 50] != 0) { 
		g->DrawImage(bmpExplosion, VerticalSuperior, SelectorVerticales, GraphicsUnit::Pixel); 
	}

	if (matriz[(y - 50) / 50][x / 50] == 1) { 
		matriz[(y - 50) / 50][x / 50] = 2; 
	}

	if (matriz[(y + 50) / 50][x / 50] != 0) { 
		g->DrawImage(bmpExplosion, VerticalInferior, SelectorVerticales, GraphicsUnit::Pixel); 
	}

	if (matriz[(y + 50) / 50][x / 50] == 1) { 
		matriz[(y + 50) / 50][x / 50] = 2; 
	}

	if (matriz[(y - 50) / 50][x / 50] != 0) {
		Rectangle SelectorPuntaSuperior = Rectangle(indiceEX * anchoExplosion, indiceEY + 5 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 5
		Rectangle PuntaSuperior = Rectangle(x, y - 100, 50, 50);
		g->DrawImage(bmpExplosion, PuntaSuperior, SelectorPuntaSuperior, GraphicsUnit::Pixel);

		if (matriz[(y - 100) / 50][x / 50] == 1) { 
			matriz[(y - 100) / 50][x / 50] = 2; 
		}
	}

	if (matriz[(y + 50) / 50][x / 50] != 0) {
		Rectangle SelectorPuntaInferior = Rectangle(indiceEX * anchoExplosion, indiceEY + 7 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 7
		Rectangle PuntaInferior = Rectangle(x, y + 100, 50, 50);
		g->DrawImage(bmpExplosion, PuntaInferior, SelectorPuntaInferior, GraphicsUnit::Pixel);

		if (matriz[(y + 100) / 50][x / 50] == 1) {
			matriz[(y + 100) / 50][x / 50] = 2;
		}
	}
	animarExplosion();
}

void Bomba::animarExplosion() {
	if (indiceEX >= 0 && indiceEX < 3) {
		indiceEX++;
	}
	else {
		estado = Estado::Desaparecer;
	}
}