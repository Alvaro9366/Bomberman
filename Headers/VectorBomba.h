#ifndef VECTORBOMBA_H
#define VECTORBOMBA_H
using namespace std;

#include <vector>
#include "Bomba.h"

class VectorBomba{

public:
	VectorBomba();
	~VectorBomba();

	void crearBomba(int, int);
	void dibujarBomba(Graphics^, Bitmap^, Bitmap^, int, int, int**);
	
	vector<Bomba*> getVectorBombas() {return vectorBomba;}

private:
	vector<Bomba*> vectorBomba;
	int totalBombas;
};


#endif // !VECTORBOMBAS_H
