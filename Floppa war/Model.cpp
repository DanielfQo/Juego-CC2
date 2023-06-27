#include <iostream>
#include <vector>
#include "Model.h"

void Model::cargarMapa() {
    mapa1 aux;
    maparef = &aux;
    maparef->generar_campo();

}
/*
int main ()
{
    Model* modelo = new Model();
    modelo->cargarMapa();


    delete modelo;


    return 0;
}*/
