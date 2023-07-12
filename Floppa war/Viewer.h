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
	bool ventanaCerrada();
	void actualizarVentana();
	void manejarEventos();
	void updateMenu(sf::Vector2i);
	void actualizarMapa(float, float);
	const std::type_info& getTipo() {return typeid(*tipoMenu);}
	bool* getDireccion() {return tipoMenu->getDireccion();}
};

