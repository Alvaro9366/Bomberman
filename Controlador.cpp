#include "Controlador.h"

Controlador::Controlador() {
	//Constructor y hace espacio dinamico
	escenarioPrincipal = new Escenario();

	jugadorPrincipal = new JugadorIzq(50, 50);
	jugadorSecundario = new JugadorDer(50*(filas), 50*(columnas-5));

	bombasPrincipal = new VectorBomba();
	bombasSecundario = new VectorBomba();
}

Controlador::~Controlador() {

}

void Controlador::nuevoNivel() {

	escenarioPrincipal->generarMatriz();
}

void Controlador::dibujar(Graphics^ g, Bitmap^ bmpSuelo, Bitmap^ bmpFijo, Bitmap^ bmpDestruible, Bitmap^ bmpJugador, Bitmap^ bmpJugador2, Bitmap^ bmpBomba, Bitmap^ bmpExplosion) {

	escenarioPrincipal->pintarSuelo(g, bmpSuelo);
	escenarioPrincipal->pintarBloques(g, bmpFijo, bmpDestruible);

	jugadorPrincipal->moverJugador(g, bmpJugador, escenarioPrincipal->getMatriz());
	jugadorSecundario->moverJugador(g, bmpJugador2, escenarioPrincipal->getMatriz());

	bombasPrincipal->dibujarBomba(g, bmpBomba, bmpExplosion, jugadorPrincipal->getX(), jugadorPrincipal->getY(), escenarioPrincipal->getMatriz());
	bombasSecundario->dibujarBomba(g, bmpBomba, bmpExplosion, jugadorSecundario->getX(), jugadorSecundario->getY(), escenarioPrincipal->getMatriz());
}

JugadorIzq* Controlador::getJugadorIzq() { 
	return jugadorPrincipal;
}

JugadorDer* Controlador::getJugadorDer() { 
	return jugadorSecundario;
}

void Controlador::agregarBombaJ1() {
	bombasPrincipal->crearBomba(jugadorPrincipal->getX(), jugadorPrincipal->getY());
}

void Controlador::agregarBombaJ2() {
	bombasSecundario->crearBomba(jugadorSecundario->getX(), jugadorSecundario->getY());
}