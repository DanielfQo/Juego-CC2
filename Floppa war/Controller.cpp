#include "Controller.h"

void Controller::cargarModel() {
    Modelo = std::make_shared<Model>();
    Modelo->cargarMapa();
}
