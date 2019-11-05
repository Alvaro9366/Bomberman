#include "Escenario.h"
#include <ctime>
#include <cstdlib>

Escenario::Escenario() {

	matriz = new int* [filas];

	for (int i{ 0 }; i < filas; i++) {

		matriz[i] = new int[columnas];
	}
}

Escenario::~Escenario() {

}

void Escenario::generarMatriz() {		//Función para generar el escenario con bloques destruibles aleatorios

	//Bloques fijos			->  0
	//Bloques destruibles	->  1
	//Bloques transitables	->  2

	srand(time(0));

	for (int i{ 0 }; i < filas; i++) {

		for (int j{ 0 }; j < columnas; j++) {

			//Bordes
			if (i == 0 || j == 0 || i == filas - 1 || j == columnas - 1) {
				matriz[i][j] = 0;
			}

			//Bloques fijos centrales
			else if (i % 2 == 0 && j % 2 == 0) {
				matriz[i][j] = 0;
			}

			//Bloques transitables iniciales
			else if (((i == 1 && (j == 1 || j == 2)) || (i == 2 && j == 1)) ||
				(i == filas - 2 && (j == columnas - 2 || j == columnas - 3) ||
				(i == filas - 3 && j == columnas - 2))) {

				matriz[i][j] = 2;
			}

			//Generación aleatoria de bloques fijos o transitables
			else {
				matriz[i][j] = rand() % 2 + 1;
			}
		}
	}
}

void Escenario::pintarSuelo(Graphics^ g, Bitmap^ bmpSuelo) {		//Pinta todos los bloques transitables
	int X{ 0 };
	int Y{ 0 };

	for (int i{ 0 }; i < filas; i++) {

		X = 0;

		for (int j{ 0 }; j < columnas; j++) {

			if (matriz[i][j] == 2) {

				g->DrawImage(bmpSuelo, X, Y, 50, 50);
			}
			X += 50;
		}
		Y += 50;
	}
}

void Escenario::pintarBloques(Graphics^ g, Bitmap^ bmpFijo, Bitmap^ bmpDestruible) {		//Pinta todos los bloques fijos o destruibles
	int X{ 0 };
	int Y{ 0 };

	for (int i{ 0 }; i < filas; i++) {

		X = 0;

		for (int j{ 0 }; j < columnas; j++) {

			if (matriz[i][j] == 0) {

				g->DrawImage(bmpFijo, X, Y, 50, 50);
			}
			if (matriz[i][j] == 1) {

				g->DrawImage(bmpDestruible, X, Y, 50, 50);
			}
			X += 50;
		}
		Y += 50;
	}
}

int** Escenario::getMatriz() {

	return matriz;
}
