#include "Controlador.h"

Controlador::Controlador() {

	escenarioPrincipal = new Escenario();
	jugadorPrincipal = new Jugador(50, 50);
}

Controlador::~Controlador() {

}

void Controlador::nuevoNivel() {

	escenarioPrincipal->generarMatriz();
}

void Controlador::dibujar(Graphics^ g, Bitmap^ bmpSuelo, Bitmap^ bmpFijo, Bitmap^ bmpDestruible, Bitmap^ bmpJugador) {

	escenarioPrincipal->pintarSuelo(g, bmpSuelo);
	escenarioPrincipal->pintarBloques(g, bmpFijo, bmpDestruible);
	jugadorPrincipal->moverJugador(g, bmpJugador, escenarioPrincipal->getMatriz());
}

Jugador* Controlador::getJugador() {
	return jugadorPrincipal;
}