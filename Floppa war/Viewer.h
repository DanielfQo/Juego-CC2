#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Menus.h"
class Viewer{
private:
	sf::RenderWindow ventana;
	std::unique_ptr<Menu> tipoMenu = std::make_unique<MenuInicio>();
	std::vector<std::vector<int>> mapaGenerado;
public:
	Viewer();
	~Viewer() = default;
	bool ventanaCerrada();
	void actualizarVentana();
	void actualizarEnemigosMelee(const std::vector<std::pair<float, float>>&);
	void actualizarEnemigosRanged(const std::vector<std::pair<float, float>>&);
	void actualizarEnemigosBomber(const std::vector<std::pair<float, float>>&);
	void manejarEventos();
	void updateMenu(sf::Vector2i);
	void updateJuego(sf::Vector2i);
	void actualizarMapa(float, float);
	const std::type_info& getTipo() {return typeid(*tipoMenu);}
	bool* getDireccion() {return tipoMenu->getDireccion();}
	void setMapaMenu(std::vector<std::vector<int>> m) { tipoMenu->setMapa(m); }
};

