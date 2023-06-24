#include "Boton.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
Boton::Boton() {};
Boton::Boton(std::string texto_, sf::Vector2f pos_, sf::Vector2f tamanio_) {
    if (!fuente.loadFromFile("Arial.ttf")) {
    }
    posicion = pos_;
    tamanio = tamanio_;
    rectanguloBoton.setFillColor(sf::Color::Blue);
    rectanguloBoton.setSize(tamanio);
    rectanguloBoton.setPosition(posicion);
    texto = texto_;
}

void Boton::dibujarBoton(sf::RenderWindow& window) {
    if (window.isOpen()) {
        window.draw(rectanguloBoton);
        //window.draw(texto) // error;
    }
}
void Boton::estaPresionado(sf::Vector2i coord) {
    if (coord.x >= posicion.x && coord.x <= posicion.x + tamanio.x && coord.y >= posicion.y && coord.y <= posicion.y + tamanio.y)
        presionado = true;
}
bool Boton::getPresionado () const{
    return presionado;
}
std::string Boton::getTexto() const {
    return texto;
}
Boton::~Boton() {}