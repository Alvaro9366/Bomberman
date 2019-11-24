#ifndef BOMBA_H
#define BOMBA_H

using namespace System::Drawing;

enum Estado {
	Normal,
	Explosion,
	Desaparecer
};

class Bomba {
public:
	Bomba(int, int);
	~Bomba();

	Estado getEstado();

	bool validarLugar(int, int, int**);
	void dibujarBomba(Graphics^, Bitmap^, int, int, int**);

	void animar();
	void dibujarExplosion(Graphics^, Bitmap^, int**);
	void animarExplosion();



private:		//Datos de la bomba
	int x;
	int y;

	int ancho;
	int alto;
	int indiceX;

	int tiempoPreexplosion;

	Estado estado;

private:		//Datos de la explosión
	int indiceEX;
	int indiceEY;

	int altoExplosion;
	int anchoExplosion;

};
#endif // !BOMBA_H

