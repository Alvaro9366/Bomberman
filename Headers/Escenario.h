#ifndef ESCENARIO_H
#define ESCENARIO_H

#define filas 17
#define columnas 19

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