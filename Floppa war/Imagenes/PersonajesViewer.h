#pragma once
#include "EntidadViewer.h"
#include <SFML/Graphics.hpp>


class PersonajesViewer : public EntidadViewer {
private:
    sf::IntRect frameRect;
    int actualFrame, totalFrames;
    float duracionFrame, ultimoFrame;
    
    
public:
    PersonajesViewer(std::string rutaImagen);
    void dibujarEntidad(sf::RenderWindow& window) override;
    void movimientoEntidadPress(const sf::Event::KeyEvent& keyevent);
    void movimientoEntidadRele(const sf::Event::KeyEvent& keyevent);
    sf::IntRect FragmentarSprite(int);
    
};