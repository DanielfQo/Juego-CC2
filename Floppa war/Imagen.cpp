
#include "Imagen.h"

Imagen::Imagen(std::string rutaImagen) {

    spriteTexture.loadFromFile(rutaImagen);
	sprite.setTexture(spriteTexture);
    sprite.setOrigin(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height);
}



void Imagen::dibujarSprite(sf::RenderWindow & window) {
    window.draw(sprite);
}