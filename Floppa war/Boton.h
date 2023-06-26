#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Boton{
private:
	sf::Texture textura;
	sf::Sprite imagen;
	std::string texto;
	sf::Vector2f posicion;
	sf::Vector2f tamanio;
	bool presionado = false;
public:
	Boton(const std::string& , const sf::Vector2f& , const std::string& );
	~Boton() = default;
	bool getPresionado ()const;
	std::string getTexto()const;
	void dibujarBoton(sf::RenderWindow&) const;
	void estaPresionado(sf::Vector2i);
};

