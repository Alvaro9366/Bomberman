#include "Controlador.h"

Controlador::Controlador() {

	escenarioPrincipal = new Escenario();
}

Controlador::~Controlador() {

}

void Controlador::nuevoNivel() {

	escenarioPrincipal->generarMatriz();
}

void Controlador::dibujar(Graphics^ g, Bitmap^ bmpSuelo, Bitmap^ bmpFijo, Bitmap^ bmpDestruible) {

	escenarioPrincipal->pintarSuelo(g, bmpSuelo);
	escenarioPrincipal->pintarBloques(g, bmpFijo, bmpDestruible);
}