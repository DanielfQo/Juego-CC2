#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class MapaViewer{
	sf::Texture tilesetTexture;
	sf::Sprite tileSprites[2];
	int FILAS = 20;
	int COLUM = 32;
	float posicionX = -100.00f;
	float posicionY = -100.00f;
	std::vector<std::vector<int>> mapa;

public:
	void setMapa(std::vector<std::vector<int>> m) { mapa = m; };

	MapaViewer(std::string , std::vector<std::vector<int>> );
	~MapaViewer() = default;
	void mostrarMapa(sf::RenderWindow& );
	void setPosicion(float, float);

};

