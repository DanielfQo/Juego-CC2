#include "Controller.h"

void Controller::cargarModel() {
    Modelo = std::make_unique<Model>();
    Modelo->cargarMapa();
}
