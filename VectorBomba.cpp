#include "VectorBomba.h"

VectorBomba::VectorBomba() {
	totalBombas = 1;		//Establece el numero de bombas que pueden colocarse a la vez
}

VectorBomba ::~VectorBomba() {

}

void VectorBomba::crearBomba(int x, int y) {
	if (vectorBomba.size() < totalBombas) {
		Bomba* nuevaBomba = new Bomba(x, y);
		vectorBomba.push_back(nuevaBomba);
	}
}

void VectorBomba::dibujarBomba(Graphics^ g, Bitmap^ bmpBomba, Bitmap^ bmpExplosion, int xJugador, int yJugador, int** matriz) {
	for (int i{ 0 }; i < vectorBomba.size(); i++) {
		switch (vectorBomba.at(i)->getEstado()) {
		case Estado::Normal:
			vectorBomba.at(i)->dibujarBomba(g, bmpBomba, xJugador, yJugador, matriz);
			vectorBomba.at(i)->animar();
			break;
		case Estado::Explosion:
			vectorBomba.at(i)->dibujarExplosion(g, bmpExplosion, matriz);
			vectorBomba.at(i)->animar();
			break;
		case Estado::Desaparecer:
			vectorBomba.erase(vectorBomba.begin() + i);
			break;
		}
	}
}
