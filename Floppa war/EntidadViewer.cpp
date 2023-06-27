#include "EntidadViewer.h"

EntidadViewer::EntidadViewer(std::string rutaImagen) : Imagen(rutaImagen) {
    //llamamos al constructor de Imagen con el nombre de archivo proporcionado
}

void EntidadViewer::movimientoEntidad() {
    velocidad = { 0,0 };
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        velocidad.y = -4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocidad.x = -4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        velocidad.y = 4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocidad.x = 4;
    }

    sprite.move(velocidad);
    if (velocidad.x < 0) {
        sprite.setScale(-1, 1);
    }
    else if (velocidad.x > 0) {
        sprite.setScale(1, 1);
    }

    if (sprite.getGlobalBounds().left < 0) {
        sprite.setPosition(sprite.getOrigin().x, sprite.getPosition().y);
    }
    if (sprite.getGlobalBounds().top < 0) {
        sprite.setPosition(sprite.getPosition().x, sprite.getOrigin().y);
    }
    if (sprite.getGlobalBounds().left + sprite.getGlobalBounds().width > 800) {
        sprite.setPosition(800 - (sprite.getGlobalBounds().width - sprite.getOrigin().x), sprite.getPosition().y);
    }
    if (sprite.getGlobalBounds().top + sprite.getGlobalBounds().height > 600) {
        sprite.setPosition(sprite.getPosition().x, 600 + (sprite.getGlobalBounds().height - sprite.getOrigin().y));
    }
}
void EntidadViewer::updateImagen() {
    movimientoEntidad();
}