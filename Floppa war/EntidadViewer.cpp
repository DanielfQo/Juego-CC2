#include "EntidadViewer.h"
#include <iostream>

EntidadViewer::EntidadViewer(std::string rutaImagen_) {
    //llamamos al constructor de Imagen con el nombre de archivo proporcionado
    rutaImagen = rutaImagen_;
    if(spriteTexture.loadFromFile(rutaImagen)){}
    sprite.setTexture(spriteTexture);
}
