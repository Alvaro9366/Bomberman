#include "Ventana.h"

using namespace BombermanDef;
void main() { //Punto de entrada linker system Windows
	Application::EnableVisualStyles();
	Application::Run(gcnew Ventana());


}