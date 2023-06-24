#pragma once
#include <SFML/Graphics.hpp>
#include "Boton.h"
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class Menu {
private:
	std::vector<Boton> botones;
public:
	virtual void mostrarMenu(sf::RenderWindow&) = 0;
	const std::vector<Boton>& getBotones() const {
		return botones;
	}
	void agregarBoton(const Boton& boton) {
		botones.push_back(boton);
	}
	void dibujarBotones(sf::RenderWindow& window) {
		for (auto& boton : botones) {
			boton.dibujarBoton(window);
		}
	}
	std::string botonPresionado(sf::Vector2i coordMouse){
		for (auto& boton : botones){
			boton.estaPresionado(coordMouse);
			if (boton.getPresionado()) {
				std::string nombre = boton.getTexto();
				return nombre;
			}
		}
		return "";
	}
};

class MenuInicio:public Menu{
public:
	MenuInicio();
	~MenuInicio() = default;
	void mostrarMenu(sf::RenderWindow&) override;
};

class MenuJugar:public Menu {
public:
	MenuJugar();
	~MenuJugar() = default;
	void mostrarMenu(sf::RenderWindow&) override;
};

class MenuConfiguraciones:public Menu {
public:
	MenuConfiguraciones();
	~MenuConfiguraciones() = default;
	void mostrarMenu(sf::RenderWindow&) override;
};
class MenuTutorial:public Menu {
public:
	MenuTutorial();
	~MenuTutorial() = default;
	void mostrarMenu(sf::RenderWindow&) override;
};