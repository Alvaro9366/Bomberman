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
	
	disminuirvidasJ1();
	disminuirvidasJ2();
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

void Controlador::disminuirvidasJ1() {
	int PuntaIzquierda,PuntaDerecha,CentroInicioY,CentroFinalY,
		PuntaSuperior,PuntaInferior,CentroInicioX,CentroFinalX;


	//Disminucion de vida por daño propio
	for (int i = 0; i < bombasPrincipal->getVectorBombas().size();i++) {
		//Extremos Bombas de J1
		PuntaIzquierda = bombasPrincipal->getVectorBombas().at(i)->getX() - 100;
		PuntaDerecha = bombasPrincipal->getVectorBombas().at(i)->getX() + 150;
		PuntaSuperior = bombasPrincipal->getVectorBombas().at(i)->getY() - 100;
		PuntaInferior = bombasPrincipal->getVectorBombas().at(i)->getY() + 150;
		//Centros Bombas de J1
		CentroInicioX = bombasPrincipal->getVectorBombas().at(i)->getX();
		CentroFinalX = bombasPrincipal->getVectorBombas().at(i)->getX() + 50;
		CentroInicioY = bombasPrincipal->getVectorBombas().at(i)->getY();
		CentroFinalY= bombasPrincipal->getVectorBombas().at(i)->getY() + 50;

		if (bombasPrincipal->getVectorBombas().at(i)->getEstado()==Estado::Explosion){
			jugadorPrincipal->disminuirvida(PuntaIzquierda,PuntaDerecha,CentroInicioY,CentroFinalY,
			PuntaSuperior,PuntaInferior,CentroInicioX,CentroFinalX);
		}

	}

	//Disminucion de vidas por daño del otro jugador
	for (int i = 0; i < bombasSecundario->getVectorBombas().size(); i++) {
		//Extremos Bombas de J2
		PuntaIzquierda = bombasSecundario->getVectorBombas().at(i)->getX() - 100;
		PuntaDerecha = bombasSecundario->getVectorBombas().at(i)->getX() + 150;
		PuntaSuperior = bombasSecundario->getVectorBombas().at(i)->getY() - 100;
		PuntaInferior = bombasSecundario->getVectorBombas().at(i)->getY() + 150;
		//Centros Bombas de J2
		CentroInicioX = bombasSecundario->getVectorBombas().at(i)->getX();
		CentroFinalX = bombasSecundario->getVectorBombas().at(i)->getX() + 50;
		CentroInicioY = bombasSecundario->getVectorBombas().at(i)->getY();
		CentroFinalY = bombasSecundario->getVectorBombas().at(i)->getY() + 50;

		if (bombasSecundario->getVectorBombas().at(i)->getEstado() == Estado::Explosion) {
			jugadorPrincipal->disminuirvida(PuntaIzquierda, PuntaDerecha, CentroInicioY, CentroFinalY,
				PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX);
		}

	}
}

void Controlador::disminuirvidasJ2() {
	int PuntaIzquierda, PuntaDerecha, CentroInicioY, CentroFinalY,
		PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;

	//Disminucion de vida por daño propio
	for (int i = 0; i < bombasSecundario->getVectorBombas().size(); i++) {
		//Extremos Bombas de J2
		PuntaIzquierda = bombasSecundario->getVectorBombas().at(i)->getX() - 100;
		PuntaDerecha = bombasSecundario->getVectorBombas().at(i)->getX() + 150;
		PuntaSuperior = bombasSecundario->getVectorBombas().at(i)->getY() - 100;
		PuntaInferior = bombasSecundario->getVectorBombas().at(i)->getY() + 150;
		//Centros Bombas de J2
		CentroInicioX = bombasSecundario->getVectorBombas().at(i)->getX();
		CentroFinalX = bombasSecundario->getVectorBombas().at(i)->getX() + 50;
		CentroInicioY = bombasSecundario->getVectorBombas().at(i)->getY();
		CentroFinalY = bombasSecundario->getVectorBombas().at(i)->getY() + 50;

		if (bombasSecundario->getVectorBombas().at(i)->getEstado() == Estado::Explosion) {
			jugadorSecundario->disminuirvida(PuntaIzquierda, PuntaDerecha, CentroInicioY, CentroFinalY,
				PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX);
		}

	}

	//Disminucion de vidas por daño del otro jugador
	for (int i = 0; i < bombasPrincipal->getVectorBombas().size(); i++) {
		//Extremos Bombas de J1
		PuntaIzquierda = bombasPrincipal->getVectorBombas().at(i)->getX() - 100;
		PuntaDerecha = bombasPrincipal->getVectorBombas().at(i)->getX() + 150;
		PuntaSuperior = bombasPrincipal->getVectorBombas().at(i)->getY() - 100;
		PuntaInferior = bombasPrincipal->getVectorBombas().at(i)->getY() + 150;
		//Centros Bombas de J1
		CentroInicioX = bombasPrincipal->getVectorBombas().at(i)->getX();
		CentroFinalX = bombasPrincipal->getVectorBombas().at(i)->getX() + 50;
		CentroInicioY = bombasPrincipal->getVectorBombas().at(i)->getY();
		CentroFinalY = bombasPrincipal->getVectorBombas().at(i)->getY() + 50;

		if (bombasPrincipal->getVectorBombas().at(i)->getEstado() == Estado::Explosion) {
			jugadorSecundario->disminuirvida(PuntaIzquierda, PuntaDerecha, CentroInicioY, CentroFinalY,
				PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX);
		}

	}
}