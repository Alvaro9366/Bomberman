#include "../Ventana.h"

using namespace ProyectoBomberman;
int main() {
	Application::EnableVisualStyles();
	Application::Run(gcnew Ventana());
	return 0;
}
