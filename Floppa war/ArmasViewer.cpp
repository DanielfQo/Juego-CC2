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
    float rotation = std::atan2(dy, dx) * 180.f / 3.1415f;
    // Aplicar la rotación al sprite
    sprite.setRotation(rotation);
    window.draw(sprite);
}

ArmaDistancia::ArmaDistancia(std::string rutaImagen_, float x, float y) : ArmasViewer(rutaImagen_, x, y) {
    for (int i = 0;i < 30;i++) {
        proyectiles.push_back(BalaViewer());
    }
}

void ArmaDistancia::usarArma(float x, float y) {
    float dx = x - this->x;
    float dy = y - this->y;
    disparado++;
    if (disparado < 30) {
        proyectiles[disparado].setPosicion(dx, dy);
    }
    
}

void ArmaDistancia::mostrarAtaque(sf::RenderWindow& window) {
    if (disparado < 30) {
        proyectiles[disparado].dibujar(window);
    }
}