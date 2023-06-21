#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Boton{
private:
	sf::Font fuente;
	sf::RectangleShape rectanguloBoton;
	sf::Text texto;
	sf::Vector2f posicion;
	sf::Vector2f tamanio;

public:
	Boton();
	~Boton();
	Boton(std::string, sf::Vector2f, sf::Vector2f);//el Vector2f en un tipo de dato que almacena un valor x y de tipo float
	void dibujarBoton(sf::RenderWindow&);

};

