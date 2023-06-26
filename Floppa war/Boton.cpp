#include "Boton.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


Boton::Boton(const std::string& texto_, const sf::Vector2f& pos_, const std::string & rutaImagen) {
    textura.loadFromFile(rutaImagen);
    posicion = pos_;
    tamanio = sf::Vector2f(textura.getSize());
    imagen.setTexture(textura);
    imagen.setPosition(posicion);
    texto = texto_;
}
void Boton::dibujarBoton(sf::RenderWindow& window) const {
    window.draw(imagen);
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