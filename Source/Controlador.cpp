#include "../Headers/Controlador.h"

Controlador::Controlador() {

	escenarioPrincipal = new Escenario();
	jugadorPrincipal = new Jugador(50, 50);
	bombasPrincipal = new VectorBombas();
}

Controlador::~Controlador() {

}

void Controlador::nuevoNivel() {

	escenarioPrincipal->generarMatriz();
}

void Controlador::agregarBomba() {
	bombasPrincipal->crearBomba(jugadorPrincipal->getX(), jugadorPrincipal->getY());
}

void Controlador::dibujar(Graphics^ g, Bitmap^ bmpSuelo, Bitmap^ bmpFijo, Bitmap^ bmpDestruible, Bitmap^ bmpJugador, Bitmap^ bmpBomba, Bitmap^ bmpExplosion) {

	escenarioPrincipal->pintarSuelo(g, bmpSuelo);
	escenarioPrincipal->pintarBloques(g, bmpFijo, bmpDestruible);
	jugadorPrincipal->moverJugador(g, bmpJugador, escenarioPrincipal->getMatriz());
	bombasPrincipal->dibujarBomba(g, bmpBomba, bmpExplosion, jugadorPrincipal->getX(), jugadorPrincipal->getY(), escenarioPrincipal->getMatriz());
}

Jugador* Controlador::getJugador() {
	return jugadorPrincipal;
}