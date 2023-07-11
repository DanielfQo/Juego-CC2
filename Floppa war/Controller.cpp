#include "Controller.h"
void Controller::cargarVentana() {
	while (Vista->ventanaCerrada()) {
		Vista->manejarEventos();
		//actualizacion del viewer respecto al model

		Vista->actualizarVentana();
	}
}