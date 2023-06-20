#pragma once
#include <SFML/Graphics.hpp>
#include "Boton.h"
#include <iostream>
#include <vector>

class MenuInicio{
private:
	std::vector<Boton> botones;
	
public:
	MenuInicio();
	void abrirMenuJugar();
	void abrirMenuConfiguraciones();
	void abrirMenuTutorial();
};

