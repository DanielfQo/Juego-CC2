#include "Controller.h"
void Controller::cargarVentana() {
	while (Vista->ventanaCerrada()) {
		Vista->manejarEventos();
		//actualizacion del viewer respecto al model
		actualizarModel();
		actualizarViewer();
		Vista->actualizarVentana();
	}
}

void Controller::actualizarModel() {
	std::string a = Vista->getTipo().name();
	std::string b = typeid(VentanaJuego).name();
	if (a == b) {
		Modelo->actualizarMapa(Vista->getDireccion());
	}
}
void Controller::actualizarViewer() {
	std::string a = Vista->getTipo().name();
	std::string b = typeid(VentanaJuego).name();
	if (a == b) {
		Vista->actualizarMapa(Modelo->getPosicionMapaX(), Modelo->getPosicionMapaY());
	}
}