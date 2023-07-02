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
    void movimientoEntidad1(const sf::Event::KeyEvent& keyevent);
    void movimientoEntidad2(const sf::Event::KeyEvent& keyevent);
    sf::IntRect FragmentarSprite(int);
};