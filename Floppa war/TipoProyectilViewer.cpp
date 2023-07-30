#include "TipoProyectilViewer.h"
#include <iostream>
BalaViewer::BalaViewer() {
    x = 512;
    y = 320;
    Px = 0; Py = 0; xM = 0; yM = 0;
    spriteTexture.loadFromFile("Imagenes/BalaAK.png");
    sprite.setTexture(spriteTexture);
}

void BalaViewer::dibujar(sf::RenderWindow& window) {
    float distanciaX = (xM - x);
    float distanciaY = (yM - y);
    float norma = sqrt((distanciaX * distanciaX) + (distanciaY * distanciaY));
    //ecuacion de la recta
    Px = x +(distanciaX / norma) * vel;
    Py = y + (distanciaY / norma) * vel;
    vel+=5;

    sprite.setPosition(Px, Py);
    sprite.setRotation(rotation);
    window.draw(sprite);
}