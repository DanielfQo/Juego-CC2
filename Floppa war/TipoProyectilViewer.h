#pragma once
#include <iostream> 
#include <vector> 
#include <SFML/Graphics.hpp>
#include "EntidadViewer.h"
//object pool
template<class T, size_t municion>
class TipoProyectil {
private:
    std::vector<std::unique_ptr<T>> proyectil;
    size_t disparados = 0;
    std::vector < std::tuple<float, float, bool>> posicionProyectiles;
public:
    TipoProyectil() {
        for (size_t i = 0; i < municion;i++) {
            proyectil.push_back(std::make_unique<T>());
            posicionProyectiles.push_back(std::make_tuple(0.00f,0.00f,false));
        }
    }
    void dispararProyectil(float x, float y, float r) {
        if (disparados < municion) {
            proyectil[disparados]->setPosicionMouse(x, y);
            proyectil[disparados]->setRotation(r);
            proyectil[disparados]->calcularVectorDirector();
            proyectil[disparados]->setActivo(true);
            disparados++;
        }
        
    }
    void dibujarProyectil(sf::RenderWindow& window) {
        for (size_t i = 0; i < disparados;i++) {
            proyectil[i]->dibujar(window);
        }
    }
    void verificarColisionEnemigo(EntidadViewer& enemigo) {
        for (size_t i = 0; i < disparados;i++) {
            proyectil[i]->colisionEnemigo(enemigo);
        }
    }
    std::vector < std::tuple<float, float, bool>> obtenerPosiciones() {
        for (size_t i = 0; i < municion;i++) {
            std::get<0>(posicionProyectiles[i]) = proyectil[i]->getPosicionX();
            std::get<1>(posicionProyectiles[i]) = proyectil[i]->getPosicionY();
            std::get<2>(posicionProyectiles[i]) = proyectil[i]->getActivo();
        }
        return posicionProyectiles;
    }
};
class ProyectilesAbstract {

public:
    virtual void setPosicionMouse(float,float) = 0;
    virtual void setRotation(float) = 0;
    virtual void calcularVectorDirector() = 0;
    virtual void setActivo(bool) = 0;
    virtual void dibujar(sf::RenderWindow &) = 0;
    virtual void colisionEnemigo(EntidadViewer&) = 0;
    virtual float getPosicionX() = 0;
    virtual float getPosicionY() = 0;
    virtual bool getActivo() = 0;
};

class BalaViewer:ProyectilesAbstract {
    bool balaActiva = false;
    sf::Texture spriteTexture;
    sf::Sprite sprite;
    std::string rutaImagen;
    float xM, yM;//pos mouse
    float x, y;
    float Px, Py;
    float rotation = 0;
    float vel = 6;

    float vectordx;
    float vectordy;
public:
    BalaViewer();
    ~BalaViewer() = default;
    float getPosicionX() { return Px; }
    float getPosicionY() { return Py; }
    bool getActivo() { return balaActiva; }
    void setActivo(bool a) { this->balaActiva = a; }
    void setPosicion(float x, float y) { this->x = x; this->y = y; }
    void setPosicionMouse(float xM, float yM) { this->xM = xM; this->yM = yM; }
    void setRotation(float rotation) { this->rotation = rotation; }
    void calcularVectorDirector();
    void dibujar(sf::RenderWindow&);
    void colisionEnemigo(EntidadViewer&);
};

class MacheteViewer :ProyectilesAbstract {
    bool balaActiva = false;
    sf::Texture spriteTexture;
    sf::Sprite sprite;
    std::string rutaImagen;
    float xM, yM;//pos mouse
    float x, y;
    float Px, Py;
    float rotation = 0;
    float vel = 6;

    float vectordx;
    float vectordy;
public:
    MacheteViewer();
    ~MacheteViewer() = default;
    float getPosicionX() { return Px; }
    float getPosicionY() { return Py; }
    bool getActivo() { return balaActiva; }
    void setActivo(bool a) { this->balaActiva = a; }
    void setPosicion(float x, float y) { this->x = x; this->y = y; }
    void setPosicionMouse(float xM, float yM) { this->xM = xM; this->yM = yM; }
    void setRotation(float rotation) { this->rotation = rotation; }

    void calcularVectorDirector()override;
    void dibujar(sf::RenderWindow&)override;
    void colisionEnemigo(EntidadViewer&)override;
};