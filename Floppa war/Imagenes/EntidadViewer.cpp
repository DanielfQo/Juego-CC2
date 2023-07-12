#include "EntidadViewer.h"

EntidadViewer::EntidadViewer(std::string rutaImagen_) {
    //llamamos al constructor de Imagen con el nombre de archivo proporcionado
    rutaImagen = rutaImagen_;
    spriteTexture.loadFromFile(rutaImagen);
    sprite.setTexture(spriteTexture);
}
