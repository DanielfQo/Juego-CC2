#include "ArmasViewer.h"
#include <cmath>


ArmasViewer::ArmasViewer(std::string rutaImagen, float x, float y){
    this->x = x;
    this->y = y;
    this->rutaImagen = rutaImagen;
    spriteTexture.loadFromFile(this->rutaImagen);
    sprite.setTexture(spriteTexture);
    sprite.move(this->x,this->y);
}

void ArmasViewer::dibujarArma(sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    float dx = static_cast<float>(mousePosition.x) - this->x;
    float dy = static_cast<float>(mousePosition.y) - this->y;
    rotation = std::atan2(dy, dx) * 180.f / 3.1415f;
    // Aplicar la rotación al sprite
    sprite.setRotation(rotation);
    window.draw(sprite);
}

ArmaDistancia::ArmaDistancia(std::string rutaImagen_, float x, float y) : ArmasViewer(rutaImagen_, x, y) {
    balas = std::make_unique<TipoProyectil<BalaViewer, 30>>();
}

void ArmaDistancia::usarArma(float xM, float yM) {
    balas->dispararProyectil(xM, yM, rotation);
}

void ArmaDistancia::mostrarAtaque(sf::RenderWindow& window) {
    balas->dibujarProyectil(window);
}