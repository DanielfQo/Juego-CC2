#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Menus.h"
class Viewer{
private:
	sf::RenderWindow ventana;
	Menu* tipoMenu = new MenuInicio();
public:
	Viewer();
	~Viewer();
	sf::RenderWindow& getVentana();
	bool ventanaCerrada();
	void updateMenu();
	void dibujarVentana();
	
};

