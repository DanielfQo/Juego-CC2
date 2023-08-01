#include "EnemigoViewer.h"
#include <iostream>

EnemigoViewer::EnemigoViewer(std::string rutaImagen) : EntidadViewer(rutaImagen) {
    int anchoFrame = spriteTexture.getSize().x / 4;//dividimos el spritesheet en 4
    int altoFrame = spriteTexture.getSize().y;
    frameRect = sf::IntRect(0, 0, anchoFrame, altoFrame);//toma la forma del sprite
    sprite.setTextureRect(frameRect);
    sprite.move(sf::Vector2f(posX, posY));
}
void EnemigoViewer::dibujarEntidad(sf::RenderWindow& window) {
    sprite.setPosition(posX, posY);
    if (posX >= -64 && posX <= 1088 && posY >= -64 && posY <= 704) {
        window.draw(sprite);
    }
    
}
void EnemigoViewer::setPosicion(float x, float y) {
    this->posX = x;
    this->posY = y;
}
void EnemigoViewer::movimientoEntidadPress(const sf::Event::KeyEvent& keyevent){}
void EnemigoViewer::movimientoEntidadRele(const sf::Event::KeyEvent& keyevent){}

//////////////////////////////////////////////////////////////////////

MeleeEnemigoViewer::MeleeEnemigoViewer() : EnemigoViewer("Imagenes/Enemigo1SpriteSheet.png") {

}

RangedEnemigoViewer::RangedEnemigoViewer() : EnemigoViewer("Imagenes/Enemigo2SpriteSheet.png") {}

BomberEnemigoViewer::BomberEnemigoViewer() : EnemigoViewer("Imagenes/Enemigo3SpriteSheet.png") {}