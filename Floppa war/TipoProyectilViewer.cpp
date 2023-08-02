#include "TipoProyectilViewer.h"
#include <iostream>
#include <tuple>
BalaViewer::BalaViewer() {
    x = 512;
    y = 320;
    Px = 0; Py = 0; xM = 0; yM = 0;
    spriteTexture.loadFromFile("Imagenes/BalaAK.png");
    sprite.setTexture(spriteTexture);
}
void BalaViewer::dibujar(sf::RenderWindow& window) {
    if (balaActiva) {
        //formula de la recta
        Px = x + (vectordx) * vel;
        Py = y + (vectordy) * vel;
        vel += 6;

        sprite.setPosition(Px, Py);
        sprite.setRotation(rotation);
        window.draw(sprite);
    }
    else {
        Px = -2000.00f;
        Py = -2000.00f;
    }
    //si sale del mapa
    if (Px <= -64 || Px >= 1088 || Py <= -64 || Py >= 704) {
        balaActiva = false;
    }
}
void BalaViewer::calcularVectorDirector() {
    float distanciaX = (xM - x);
    float distanciaY = (yM - y);
    float norma = sqrt((distanciaX * distanciaX) + (distanciaY * distanciaY));
    vectordx = distanciaX / norma;
    vectordy = distanciaY / norma;
}

void BalaViewer::colisionEnemigo(EntidadViewer& enemigo) {
    if (balaActiva) {
        if (Px >= enemigo.getPosicionX() && Px <= enemigo.getPosicionX() + 64 && Py >= enemigo.getPosicionY() && Py <= enemigo.getPosicionY() + 64) {
            balaActiva = false;
        }
    }
}
////////////////////////////
MacheteViewer::MacheteViewer() {
    x = 512;
    y = 320;
    Px = 0; Py = 0; xM = 0; yM = 0;
    spriteTexture.loadFromFile("Imagenes/BalaMachete.png");
    sprite.setTexture(spriteTexture);
}
void MacheteViewer::dibujar(sf::RenderWindow& window) {
    if (balaActiva) {
        //formula de la recta
        Px = x + (vectordx)*vel;
        Py = y + (vectordy)*vel;
        vel += 6;

        sprite.setPosition(Px, Py);
        sprite.setRotation(rotation);
        window.draw(sprite);
    }
    else {
        Px = -2000.00f;
        Py = -2000.00f;
    }
    //si sale del mapa
    if (Px <= -64 || Px >= 1088 || Py <= -64 || Py >= 704) {
        balaActiva = false;
    }
}
void MacheteViewer::calcularVectorDirector() {
    float distanciaX = (xM - x);
    float distanciaY = (yM - y);
    float norma = sqrt((distanciaX * distanciaX) + (distanciaY * distanciaY));
    vectordx = distanciaX / norma;
    vectordy = distanciaY / norma;
}

void MacheteViewer::colisionEnemigo(EntidadViewer& enemigo) {
    if (balaActiva) {
        if (Px >= enemigo.getPosicionX() && Px <= enemigo.getPosicionX() + 64 && Py >= enemigo.getPosicionY() && Py <= enemigo.getPosicionY() + 64) {
            balaActiva = false;
        }
    }
}