#include "TipoProyectilViewer.h"
#include <iostream>
BalaViewer::BalaViewer() {
    spriteTexture.loadFromFile("Imagenes/BalaAK.png");
    sprite.setTexture(spriteTexture);
}

void BalaViewer::dibujar(sf::RenderWindow& window) {
    
    sprite.setPosition(x+512, y+320);
    window.draw(sprite);
}