#pragma once
#include "EntidadViewer.h"
#include <SFML/Graphics.hpp>


class PersonajesViewer : public EntidadViewer {
private:
    sf::IntRect frameRect;
    int actualFrame, totalFrames;
    float duracionFrame, ultimoFrame;
    bool mueveArriba = false,mueveAbajo = false,mueveDerecha = false,mueveIzquierda = false;
    
public:
    PersonajesViewer(std::string rutaImagen);
    void dibujarEntidad(sf::RenderWindow& window) override;
    void movimientoEntidadPress(const sf::Event::KeyEvent& keyevent);
    void movimientoEntidadRele(const sf::Event::KeyEvent& keyevent);
    sf::IntRect FragmentarSprite(int);

    bool getMueveArriba() {return mueveArriba;}
    bool getMueveAbajo() { return mueveAbajo; }
    bool getMueveIzquierda() { return mueveIzquierda; }
    bool getMueveDerecha() { return mueveDerecha; }
};