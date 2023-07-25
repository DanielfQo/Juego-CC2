#include <iostream>
#include <vector>
#include "Model.h"

Model::Model(){}

void Model::generarMapa() {

    if (idmapa == 1) {
        maparef = std::make_unique<MapaModel>();
        maparef->generarCuartos();
        maparef->generarMapaCompleto();
        maparef->imprimirMapa();
        maparef->generar_entidades();
        idmapa++;
    }
}

void Model::actualizarMapa(bool direccion[4]) { 
    maparef->moverMapa(direccion);
}

void Model::actualizarPosicionEnemigos() {
    maparef->movimientoEnemigosPersonaje();
    maparef->movimientoEnemigosEnemigos();

}

