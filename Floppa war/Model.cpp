#include <iostream>
#include <vector>
#include "Model.h"


int main ()
{
    Model* modelo = new Model();
    modelo->cargarMapa();


    delete modelo;


    return 0;
}
