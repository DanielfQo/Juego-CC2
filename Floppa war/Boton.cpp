#include "Boton.h"
#include "SFML/Window.hpp"
Boton::Boton() {};
Boton::Boton(std::string texto_, sf::Vector2f pos_, sf::Vector2f tamanio_) {
    if (!fuente.loadFromFile("arial.ttf")) {

    }
    texto.setFont(fuente);
    texto.setString(texto_);
    posicion = pos_;
    rectanguloBoton.setFillColor(sf::Color::Blue);
    tamanio = tamanio_;
    rectanguloBoton.setSize(tamanio);
}

void Boton::dibujarBoton(sf::RenderWindow& window) {
    texto.setCharacterSize(24);
    rectanguloBoton.setPosition(posicion);
    sf::FloatRect textBounds = texto.getLocalBounds();

    float desx = (tamanio.x - textBounds.width) / 2.0f; // centramos el texto
    float desy = (tamanio.y - textBounds.height) / 2.0f;

    texto.setPosition(posicion.x+desx,posicion.y+desy);
    texto.setCharacterSize(24);
    texto.setFillColor(sf::Color::White);

    window.draw(rectanguloBoton);
    window.draw(texto);
}
Boton::~Boton() {};