#include "EntidadViewer.h"
#include <iostream>

EntidadViewer::EntidadViewer(std::string rutaImagen_) {
    //llamamos al constructor de Imagen con el nombre de archivo proporcionado
    rutaImagen = rutaImagen_;
    if(spriteTexture.loadFromFile(rutaImagen)){
        std::cout << "Se cargo la imagen";
    }
    sprite.setTexture(spriteTexture);
}
