#ifndef JUGADOR_H
#define JUGADOR_H

using namespace System::Drawing;

class Jugador{

public:


	virtual void dibujarJugador(Graphics^, Bitmap^, int**) = 0;
	virtual void moverJugador(Graphics^, Bitmap^, int**) = 0;
	virtual void ValidarMovimiento(int**) = 0;

	

};

#endif // !JUGADOR_H