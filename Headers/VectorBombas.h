#pragma once
#ifndef VECTORBOMBAS_H
#define VECTORBOMBAS_H

#include <vector>
#include "Bomba.h"

class VectorBombas {

public:
	VectorBombas ();
	~VectorBombas ();

	void crearBomba(int, int);
	void dibujarBomba(Graphics^, Bitmap^, Bitmap^, int, int, int**);

private:
	std::vector<Bomba*> vectorBombas;
	int totalBombas;
};


#endif // !VECTORBOMBAS_H
