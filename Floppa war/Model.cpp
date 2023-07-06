#include <iostream>
#include <vector>
#include "Model.h"

void Model::cargarMapa() {
    maparef = std::make_unique<MapaModel>();
    maparef->generar_campo();
}
