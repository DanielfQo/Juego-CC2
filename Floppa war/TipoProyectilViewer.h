#pragma once
#include <iostream> 
#include <vector> 
#include <SFML/Graphics.hpp>

class BalaViewer {
    sf::Texture spriteTexture;
    sf::Sprite sprite;
    std::string rutaImagen;
    float x, y;
public:
    BalaViewer();
    ~BalaViewer() = default;
    void setPosicion(float x, float y) { this->x = x; this->y = y; }
    void dibujar(sf::RenderWindow&);
};