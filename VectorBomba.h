#ifndef VECTORBOMBA_H
#define VECTORBOMBA_H

#include <vector>
#include "Bomba.h"

class VectorBomba{

public:
	VectorBomba();
	~VectorBomba();

	void crearBomba(int, int);
	void dibujarBomba(Graphics^, Bitmap^, Bitmap^, int, int, int**);

private:
	std::vector<Bomba*> vectorBomba;
	int totalBombas;
};


#endif // !VECTORBOMBAS_H
