#include "Controller.h"
Controller::Controller() {}
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
		Modelo->actualizarPosicionProyectiles(Vista->getPosicionesProyectiles());
		Modelo->actualizarPosicionEnemigos();
		if (Modelo->getIdMapa() == 2) {//con idmapa hacemos que solo se genere una vez 
			Vista->setMapaMenu(Modelo->getMapa1());
			Modelo->setIdMapa(3);
		}
	}
	else if (Vista->getTipo() == typeid(SeleccionPersonajeSingle)){
		Modelo->generarMapa();
	}
	else {
		Modelo->setIdMapa(1);
	}
}
void Controller::actualizarViewer() {
	if (Vista->getTipo() == typeid(VentanaJuego)) {
		Vista->actualizarMapa(Modelo->getPosicionMapaX(), Modelo->getPosicionMapaY());
		Vista->actualizarEnemigosMelee(Modelo->getPosicionEnemigosMelee());
		Vista->actualizarEnemigosRanged(Modelo->getPosicionEnemigosRanged());
		Vista->actualizarEnemigosBomber(Modelo->getPosicionEnemigosBomber());
	}
}