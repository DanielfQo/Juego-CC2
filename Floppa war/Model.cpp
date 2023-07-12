#include <iostream>
#include <vector>
#include "Model.h"

void Model::cargarMapa() {
    
    maparef->generar_campo();
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
