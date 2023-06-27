#include <iostream>
#include <vector>
#include "Controller.h"


int main(){
    bool game = true;
    Controller* controlModel = new Controller();
    controlModel->cargarModel();

    while(game == true){
        game =  false;
    }
    delete controlModel;
    return 0;
}