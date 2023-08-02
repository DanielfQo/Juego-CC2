#pragma once
#include "EntidadViewer.h"
#include <SFML/Graphics.hpp>
#include "ArmasViewer.h"
#include <iostream>

class PersonajesViewer : public EntidadViewer {
private:
    sf::IntRect frameRect;
    int actualFrame, totalFrames;
    float duracionFrame, ultimoFrame;
    std::vector<std::unique_ptr<ArmasViewer>> armas;

public:
    PersonajesViewer(std::string rutaImagen);
    void dibujarEntidad(sf::RenderWindow& window) override;
    void movimientoEntidadPress(const sf::Event::KeyEvent& keyevent);
    void movimientoEntidadRele(const sf::Event::KeyEvent& keyevent);
    sf::IntRect FragmentarSprite(int);
    void setPosicion(float, float) override {};
    void Atacar(float, float);
    void verificarAtaqueToEnemigo(EntidadViewer& enemigo)override;
    std::vector<std::tuple<float, float, bool>> getPosicionesProyectiles()override { return armas[armaCambiar]->getPosicionProyectiles(); }
};