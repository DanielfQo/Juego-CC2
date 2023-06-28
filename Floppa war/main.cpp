
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include <iostream>
#include "Viewer.h"
#include "Controller.h"

int main() {
    bool game = true;
    Controller* controlModel = new Controller();
    controlModel->cargarModel();

    while (game == true) {
        game = false;
    }

    delete controlModel;
    Viewer vista;
    vista.dibujarVentana();
    
    return 0;
}

