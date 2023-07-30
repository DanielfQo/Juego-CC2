#pragma once
#include <iostream> 
#include <vector> 
#include <SFML/Graphics.hpp>

template<class T, size_t municion>
class TipoProyectil {
private:
    std::vector<std::unique_ptr<T>> proyectil;
    size_t disparados = 0;
public:
    TipoProyectil() {
        for (size_t i = 0; i < municion;i++) {
            proyectil.push_back(std::make_unique<T>());
        }
    }
    void dispararProyectil(float x, float y, float r) {
        if (disparados < municion) {
            proyectil[disparados]->setPosicionMouse(x, y);
            proyectil[disparados]->setRotation(r);
            disparados++;
        }
        
    }
    void dibujarProyectil(sf::RenderWindow& window) {
        for (size_t i = 0; i < disparados;i++) {
            proyectil[i]->dibujar(window);
        }
    }

};

class BalaViewer {
    sf::Texture spriteTexture;
    sf::Sprite sprite;
    std::string rutaImagen;
    float xM, yM;//pos mouse
    float x, y;
    float Px, Py;
    float rotation = 0;
    float vel = 5;
public:
    BalaViewer();
    ~BalaViewer() = default;
    void setPosicion(float x, float y) { this->x = x; this->y = y; }
    void setPosicionMouse(float xM, float yM) { this->xM = xM; this->yM = yM; }
    void setRotation(float rotation) { this->rotation = rotation; }
    void dibujar(sf::RenderWindow&);
};