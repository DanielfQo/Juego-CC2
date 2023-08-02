#include "PersonajesViewer.h"
#include <iostream> 
#include <SFML/Graphics.hpp>
PersonajesViewer::PersonajesViewer(std::string rutaImagen): EntidadViewer(rutaImagen), 
actualFrame(0), totalFrames(4), duracionFrame(0.1f), ultimoFrame(0.0f){
    
    int anchoFrame = spriteTexture.getSize().x / totalFrames;//dividimos el spritesheet en 4
    int altoFrame = spriteTexture.getSize().y;
    frameRect = sf::IntRect(0, 0, anchoFrame, altoFrame);//toma la forma del sprite
    sprite.setTextureRect(frameRect);
    posX = 480;
    posY = 288;
    sprite.setPosition(posX,posY);
    armas.push_back(std::make_unique<ArmaDistancia>("Imagenes/Arma.png", posX+32, posY+32));
    armas.push_back(std::make_unique<ArmaMelee>("Imagenes/Machete.png", posX+32, posY+32));

    spriteTextureHUD.loadFromFile("Imagenes/BarraVaciaVida.png");
    spriteHUD.setTexture(spriteTextureHUD);

    spriteTextureVida.loadFromFile("Imagenes/BarraVida.png");
    spriteVida.setTexture(spriteTextureVida);
    rectVida = sf::IntRect(0, 0, vida*2, 20);
    spriteVida.setTextureRect(rectVida);
    spriteHUD.move(sf::Vector2f(70, 0));
    spriteVida.move(sf::Vector2f(70, 0));
}

void PersonajesViewer::dibujarEntidad(sf::RenderWindow& window) {
    sprite.setPosition(posX, posY);
    armas[armaCambiar]->setPosicionArma(posX+32, posY+32);
    armas[armaCambiar]->mostrarAtaque(window);
    window.draw(sprite);
    armas[armaCambiar]->dibujarArma(window);
    rectVida = sf::IntRect(0, 0, vida * 2, 20);
    spriteVida.setTextureRect(rectVida);
    window.draw(spriteVida);
    window.draw(spriteHUD);
}

void PersonajesViewer::movimientoEntidadPress(bool arriba, bool izquierda, bool abajo, bool derecha) {
    if (arriba) {
        mueveArriba = true;
        mueveAbajo = false;
    }
    else if (izquierda) {
        mueveIzquierda = true;
        mueveDerecha = false;
    }
    if (abajo) {
        mueveAbajo = true;
        mueveArriba = false;
    }
    else if (derecha) {
        mueveDerecha = true;
        mueveIzquierda = false;
    }
    
    ultimoFrame += duracionFrame;
    if (ultimoFrame >= duracionFrame) {
        ultimoFrame -= duracionFrame;
        if (mueveAbajo)
            actualFrame = 0;
        else if (mueveArriba)
            actualFrame = 1;
        else if (mueveDerecha)
            actualFrame = 2;
        else if (mueveIzquierda)
            actualFrame = 3;
        sprite.setTextureRect(FragmentarSprite(actualFrame));
    }

}
void PersonajesViewer::movimientoEntidadRele(bool arriba, bool izquierda, bool abajo, bool derecha) {

    if (arriba) {
        mueveArriba = false;
    }
    if (izquierda) {
        mueveIzquierda = false;
    }
    if (abajo) {
        mueveAbajo = false;
    }
    if (derecha) {
        mueveDerecha = false;
    }
    ultimoFrame += duracionFrame;
    if (ultimoFrame >= duracionFrame) {
        ultimoFrame -= duracionFrame;
        if (mueveAbajo)
            actualFrame = 0;
        else if (mueveArriba)
            actualFrame = 1;
        else if (mueveDerecha)
            actualFrame = 2;
        else if (mueveIzquierda)
            actualFrame = 3;
        sprite.setTextureRect(FragmentarSprite(actualFrame));
    }
}
void PersonajesViewer::movimientoEntidadPress2(bool arriba, bool izquierda, bool abajo, bool derecha) {
    if (arriba) {
        mueveArriba = true;
        mueveAbajo = false;
    }
    else if (izquierda) {
        mueveIzquierda = true;
        mueveDerecha = false;
    }
    if (abajo) {
        mueveAbajo = true;
        mueveArriba = false;
    }
    else if (derecha) {
        mueveDerecha = true;
        mueveIzquierda = false;
    }

    if (abajo)
        velocidadY += aceleracion;
    if (arriba)
        velocidadY -= aceleracion;
    if (derecha)
        velocidadX += aceleracion;
    if (izquierda)
        velocidadX -= aceleracion;

    // Aplicar desaceleración
    if (!abajo && !arriba)
        velocidadY -= (velocidadY * desaceleracion);
    if (!derecha && !izquierda)
        velocidadX -= (velocidadX * desaceleracion);

    // Limitar la velocidad máxima
    if (velocidadY > velocidadMaxima)
        velocidadY = velocidadMaxima;
    if (velocidadY < -velocidadMaxima)
        velocidadY = -velocidadMaxima;
    if (velocidadX > velocidadMaxima)
        velocidadX = velocidadMaxima;
    if (velocidadX < -velocidadMaxima)
        velocidadX = -velocidadMaxima;

    // Mover la posición en función de las velocidades
    posY += velocidadY;
    posX += velocidadX;

    ultimoFrame += duracionFrame;
    if (ultimoFrame >= duracionFrame) {
        ultimoFrame -= duracionFrame;
        if (mueveAbajo) 
            actualFrame = 0;
        else if (mueveArriba)
            actualFrame = 1;
        else if (mueveDerecha)
            actualFrame = 2;
        else if (mueveIzquierda)
            actualFrame = 3;
        sprite.setTextureRect(FragmentarSprite(actualFrame));
    }
}
void PersonajesViewer::movimientoEntidadRele2(bool arriba, bool izquierda, bool abajo, bool derecha) {

    if (arriba) {
        mueveArriba = false;
    }
    if (izquierda) {
        mueveIzquierda = false;
    }
    if (abajo) {
        mueveAbajo = false;
    }
    if (derecha) {
        mueveDerecha = false;
    }

    ultimoFrame += duracionFrame;
    if (ultimoFrame >= duracionFrame) {
        ultimoFrame -= duracionFrame;
        if (mueveAbajo)
            actualFrame = 0;
        else if (mueveArriba)
            actualFrame = 1;
        else if (mueveDerecha)
            actualFrame = 2;
        else if (mueveIzquierda)
            actualFrame = 3;
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
    armas[armaCambiar]->usarArma(x, y);
}
void PersonajesViewer::verificarAtaqueToEnemigo(EntidadViewer& enemigo) {
    armas[armaCambiar]->verificarColisionEnemigo(enemigo);
}
