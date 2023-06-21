#pragma once
#include <SFML/Graphics.hpp>
#include "Boton.h"
#include <iostream>
#include <vector>
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

};

class MenuInicio:public Menu{

public:
	MenuInicio();
	~MenuInicio();
	void mostrarMenu(sf::RenderWindow&) override;
};

