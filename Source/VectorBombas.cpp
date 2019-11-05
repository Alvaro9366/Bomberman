#include "../Headers/VectorBombas.h"

VectorBombas::VectorBombas() {
	totalBombas = 5;		//Establece el numero de bombas que pueden colocarse a la vez
}

VectorBombas ::~VectorBombas() {

}

void VectorBombas::crearBomba(int x, int y) {
	if (vectorBombas.size() < totalBombas) {
		Bomba* nuevaBomba = new Bomba(x, y);
		vectorBombas.push_back(nuevaBomba);
	}
}

void VectorBombas::dibujarBomba(Graphics^ g, Bitmap^ bmpBomba, Bitmap^ bmpExplosion, int xJugador, int yJugador, int** matriz) {
	for (int i{ 0 }; i < vectorBombas.size(); i++) {
		switch (vectorBombas.at(i)->getEstado()) {
		case Estado::Normal:
			vectorBombas.at(i)->dibujarBomba(g, bmpBomba, xJugador, yJugador, matriz);
			vectorBombas.at(i)->animar();
			break;
		case Estado::Explosion:
			vectorBombas.at(i)->dibujarExplosion(g, bmpExplosion, matriz);
			vectorBombas.at(i)->animar();
			break;
		case Estado::Desaparecer:
			vectorBombas.erase(vectorBombas.begin() + i);
			break;
		}
	}
}