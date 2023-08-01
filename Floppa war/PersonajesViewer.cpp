#include "PersonajesViewer.h"
#include <iostream> 
#include <SFML/Graphics.hpp>
PersonajesViewer::PersonajesViewer(std::string rutaImagen): EntidadViewer(rutaImagen), 
actualFrame(0), totalFrames(4), duracionFrame(0.1f), ultimoFrame(0.0f){
    
    int anchoFrame = spriteTexture.getSize().x / totalFrames;//dividimos el spritesheet en 4
    int altoFrame = spriteTexture.getSize().y;
    frameRect = sf::IntRect(0, 0, anchoFrame, altoFrame);//toma la forma del sprite
    sprite.setTextureRect(frameRect);
    sprite.move(sf::Vector2f(480,288));
    arma = std::make_unique<ArmaDistancia>("Imagenes/Arma.png", 512.0f, 320.0f);
}

void PersonajesViewer::dibujarEntidad(sf::RenderWindow& window) {
    arma->mostrarAtaque(window);
    window.draw(sprite);
    arma->dibujarArma(window);
    
}

void PersonajesViewer::movimientoEntidadPress(const sf::Event::KeyEvent& keyevent) {
    

    if (keyevent.code == sf::Keyboard::W) {
        mueveArriba = true;
        mueveAbajo = false;
    }
    else if (keyevent.code == sf::Keyboard::A) {
        mueveIzquierda = true;
        mueveDerecha = false;
    }
    if (keyevent.code == sf::Keyboard::S) {
        mueveAbajo = true;
        mueveArriba = false;
    }
    else if (keyevent.code == sf::Keyboard::D) {
        mueveDerecha = true;
        mueveIzquierda = false;
    }
    
    ultimoFrame += duracionFrame;
    if (ultimoFrame >= duracionFrame) {
        ultimoFrame -= duracionFrame;
        if (mueveAbajo) {
            actualFrame = 0;
        }
        else if (mueveArriba) {
            actualFrame = 1;
        }
        else if (mueveDerecha) {
            actualFrame = 2;
        }
        else if (mueveIzquierda) {
            actualFrame = 3;
        }

        sprite.setTextureRect(FragmentarSprite(actualFrame));
    }

}
void PersonajesViewer::movimientoEntidadRele(const sf::Event::KeyEvent& keyevent) {

    if (keyevent.code == sf::Keyboard::W) {
        mueveArriba = false;
    }
    if (keyevent.code == sf::Keyboard::A) {
        mueveIzquierda = false;
    }
    if (keyevent.code == sf::Keyboard::S) {
        mueveAbajo = false;
    }
    if (keyevent.code == sf::Keyboard::D) {
        mueveDerecha = false;
    }
    ultimoFrame += duracionFrame;
    if (ultimoFrame >= duracionFrame) {
        ultimoFrame -= duracionFrame;
        if (mueveAbajo) {
            actualFrame = 0;
        }
        else if (mueveArriba) {
            actualFrame = 1;
        }
        else if (mueveDerecha) {
            actualFrame = 2;
        }
        else if (mueveIzquierda) {
            actualFrame = 3;
        }

        sprite.setTextureRect(FragmentarSprite(actualFrame));
    }
}

sf::IntRect PersonajesViewer::FragmentarSprite(int i) {
    int anchoFrame = spriteTexture.getSize().x / totalFrames;//dividimos el spritesheet en 4
    int altoFrame = spriteTexture.getSize().y;
    // 0 = adelante
    // 1 = atras
    // 2 = derecha
    // 3 = izquierda
    if (i >= 0) {
        frameRect = sf::IntRect(anchoFrame * i, 0, anchoFrame, altoFrame);
    }
    return frameRect;
}

void PersonajesViewer::Atacar(float x, float y) {
    arma->usarArma(x, y);
}
void PersonajesViewer::verificarAtaqueToEnemigo(EntidadViewer& enemigo) {
    arma->verificarColisionEnemigo(enemigo);
}
