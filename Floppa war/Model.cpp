#include <iostream>
#include <vector>
#include "Model.h"

void Model::generarMapa() {

    if (idmapa == 1) {
        maparef = std::make_unique<MapaModel>();
        maparef->generarCuartos();
        maparef->generarMapaCompleto();
        maparef->imprimirMapa();
        idmapa++;
    }
}

void Model::actualizarMapa(bool direccion[4]) { 
    maparef->moverMapa(direccion);
}
