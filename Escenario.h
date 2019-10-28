#pragma once
#ifndef ESCENARIO_H
#define ESCENARIO_H

using namespace System::Drawing;

class Escenario {

public:
	Escenario();
	~Escenario();
	void generarMatriz();
	void pintarSuelo(Graphics^, Bitmap^);
	void pintarBloques(Graphics^, Bitmap^, Bitmap^);
	int** getMatriz();

private:
	int** matriz;
};

#endif // !ESCENARIO_H
