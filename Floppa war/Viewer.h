#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Menus.h"
class Viewer{
private:
	sf::RenderWindow ventana;
	std::unique_ptr<Menu> tipoMenu = std::make_unique<MenuInicio>();
	
public:
	Viewer();
	~Viewer();
	sf::RenderWindow& getVentana();
	bool ventanaCerrada();
	void updateMenu(sf::Vector2i);
	void dibujarVentana();
};

