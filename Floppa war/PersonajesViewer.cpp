#include "PersonajesViewer.h"
#include <iostream> 
#include <SFML/Graphics.hpp>
PersonajesViewer::PersonajesViewer(std::string rutaImagen): EntidadViewer(rutaImagen), 
actualFrame(0), totalFrames(5), duracionFrame(0.1f), ultimoFrame(0.0f), mueveDerecha(false) {

    int anchoFrame = spriteTexture.getSize().x / totalFrames;//dividimos el spritesheet en 5
    int altoFrame = spriteTexture.getSize().y;
    frameRect = sf::IntRect(0, 0, anchoFrame, altoFrame);//toma la forma del sprite
    sprite.setTextureRect(frameRect);
    sprite.move(sf::Vector2f(512, 320));
}

void PersonajesViewer::dibujarEntidad(sf::RenderWindow& window) {
    window.draw(sprite);
}

void PersonajesViewer::movimientoEntidad1(const sf::Event::KeyEvent& keyevent) {
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        mueveArriba = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        mueveIzquierda = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        mueveAbajo = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        mueveDerecha = true;
    }
    
    ultimoFrame += duracionFrame;
    if (ultimoFrame >= duracionFrame) {
        ultimoFrame -= duracionFrame;
        if (mueveDerecha) {
            if (actualFrame < 2) {
                actualFrame++;
            }
        }
        if (mueveIzquierda) {
            if (actualFrame > -2) {
                actualFrame--;
            }
        }
        std::cout << actualFrame;
        if (actualFrame < 0)
            sprite.scale(-1, 1);
        sprite.setTextureRect(FragmentarSprite(actualFrame));
    }
}
void PersonajesViewer::movimientoEntidad2(const sf::Event::KeyEvent& keyevent) {
    std::cout << actualFrame;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        mueveArriba = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        mueveIzquierda = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        mueveAbajo = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        mueveDerecha = false;
    }
    ultimoFrame += duracionFrame;
    if (ultimoFrame >= duracionFrame) {
        ultimoFrame -= duracionFrame;
        if (mueveDerecha) {
            if (actualFrame < 2) {
                actualFrame++;
            }
        }
        if (mueveIzquierda) {
            if (actualFrame > -2) {
                actualFrame--;
            }
        }
        sprite.setTextureRect(FragmentarSprite(actualFrame));
    }
}

sf::IntRect PersonajesViewer::FragmentarSprite(int i) {
    int anchoFrame = spriteTexture.getSize().x / totalFrames;//dividimos el spritesheet en 5
    int altoFrame = spriteTexture.getSize().y;
    if (i >= 0) {
        frameRect = sf::IntRect(anchoFrame * i, 0, anchoFrame, altoFrame);
    }
    return frameRect;
}