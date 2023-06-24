#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Boton{
private:
	sf::Font fuente;
	sf::RectangleShape rectanguloBoton;
	std::string texto;
	sf::Vector2f posicion;
	sf::Vector2f tamanio;
	bool presionado = false;
public:
	Boton();
	~Boton();
	Boton(std::string, sf::Vector2f, sf::Vector2f);//el Vector2f en un tipo de dato que almacena un valor x y de tipo float
	bool getPresionado ()const;
	std::string getTexto()const;
	void dibujarBoton(sf::RenderWindow&);
	void estaPresionado(sf::Vector2i);
};

