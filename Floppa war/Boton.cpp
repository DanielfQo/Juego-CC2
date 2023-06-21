#include "Boton.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
Boton::Boton() {};
Boton::Boton(std::string texto_, sf::Vector2f pos_, sf::Vector2f tamanio_) {
    if (!fuente.loadFromFile("Arial.ttf")) {
    }
    texto.setFont(fuente);
    texto.setString(texto_);
    posicion = pos_;
    tamanio = tamanio_;
    rectanguloBoton.setFillColor(sf::Color::Blue);
    rectanguloBoton.setSize(tamanio);
    sf::FloatRect textBounds = texto.getLocalBounds();
    float desx = (tamanio.x - textBounds.width) / 2.f; // centramos el texto
    float desy = (tamanio.y - textBounds.height) / 2.f;
    texto.setPosition(posicion.x + desx, posicion.y + desy);
    rectanguloBoton.setPosition(posicion);
    texto.setCharacterSize(24);
    texto.setFillColor(sf::Color::White);
}

void Boton::dibujarBoton(sf::RenderWindow& window) {
    
    if (window.isOpen()) {
        window.draw(rectanguloBoton);
        //window.draw(texto) // error;
    }
}
Boton::~Boton() {

}