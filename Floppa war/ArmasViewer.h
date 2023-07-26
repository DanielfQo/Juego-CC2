#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TipoProyectilViewer.h"
class ArmasViewer{
protected:
	sf::Texture spriteTexture;
	sf::Sprite sprite;
	std::string rutaImagen;
	float x;
	float y;
public:
	ArmasViewer(std::string,float,float);
	~ArmasViewer() = default;
	void dibujarArma(sf::RenderWindow&);
	
	virtual void usarArma(float, float)=0;
	virtual void mostrarAtaque(sf::RenderWindow&) = 0;
};

class ArmaDistancia: public ArmasViewer {
private:
	int disparado = 0;
	int municion = 30;
	std::vector<BalaViewer> proyectiles;
public:
	ArmaDistancia(std::string, float, float);
	~ArmaDistancia() = default;
	void usarArma(float, float)override;
	void mostrarAtaque(sf::RenderWindow&)override;
};
