#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class MapaViewer{
	sf::Texture tilesetTexture;
	sf::Sprite tileSprites[2];
	int FILAS = 20*4;
	int COLUM = 32*4;
	float posicionX;
	float posicionY;
	std::vector<std::vector<int>> mapa;

public:
	void setMapa(std::vector<std::vector<int>> m) { mapa = m; };

	MapaViewer(std::string , std::vector<std::vector<int>> );
	~MapaViewer() = default;
	void mostrarMapa(sf::RenderWindow& );
	void setPosicion(float, float);

};

