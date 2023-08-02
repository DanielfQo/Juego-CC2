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

    sf::Texture spriteTextureHUD;
    sf::Sprite spriteHUD;
    sf::IntRect rectVida;
    sf::Texture spriteTextureVida;
    sf::Sprite spriteVida;

    float velocidadX = 0.00f;
    float velocidadY = 0.00f;
    const float aceleracion = 0.50f;
    const float desaceleracion = 0.25f;
    const float velocidadMaxima = 5.00f;

public:
    PersonajesViewer(std::string rutaImagen);
    void dibujarEntidad(sf::RenderWindow& window) override;
    void movimientoEntidadPress(bool,bool,bool,bool)override;
    void movimientoEntidadRele(bool, bool, bool, bool)override;
    void movimientoEntidadPress2(bool, bool, bool, bool)override;
    void movimientoEntidadRele2(bool, bool, bool, bool)override;
    sf::IntRect FragmentarSprite(int);
    void setPosicion(float x, float y) override {
        posX = x;
        posY = y;
    };
    void Atacar(float, float);
    void verificarAtaqueToEnemigo(EntidadViewer& enemigo)override;
    std::vector<std::tuple<float, float, bool>> getPosicionesProyectiles()override { return armas[armaCambiar]->getPosicionProyectiles(); }
};