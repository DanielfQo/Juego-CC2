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

bool Model::colisiones(int X, int Y, int posX, int posY, int width, int lenght) {
    if (posX <= X && X <= posX + width && posY <= Y && Y <= posY + lenght)
        return true;
    else
        return false;
}
