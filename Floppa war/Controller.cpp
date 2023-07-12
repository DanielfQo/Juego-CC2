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
	if (Vista->getTipo() == typeid(VentanaJuego)) {
		Modelo->actualizarMapa(Vista->getDireccion());
	}
}
void Controller::actualizarViewer() {
	if (Vista->getTipo() == typeid(VentanaJuego)) {
		Vista->actualizarMapa(Modelo->getPosicionMapaX(), Modelo->getPosicionMapaY());
	}
}