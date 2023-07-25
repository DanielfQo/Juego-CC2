#include "ArmasViewer.h"
ArmasViewer::ArmasViewer(std::string rutaImagen_, float x, float y){
    rutaImagen = rutaImagen_;
    spriteTexture.loadFromFile(rutaImagen);
    sprite.setTexture(spriteTexture);
    sprite.move(x,y);
}

void ArmasViewer::dibujarArma(sf::RenderWindow& window) {
    window.draw(sprite);
}